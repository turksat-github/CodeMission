import sqlite3
import datetime
import re
import os
import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox, filedialog
from typing import List, Dict, Optional, Any, Tuple
import json
import threading
import socket
import time
class AFTNDatabase:
    def __init__(self, db_path: str = "aftn_messages.db"):
        self.db_path = db_path
        self.conn = self.initialize_database()
    def initialize_database(self) -> sqlite3.Connection:
        new_db = not os.path.exists(self.db_path)
        conn = sqlite3.connect(self.db_path)
        conn.row_factory = sqlite3.Row  # Dictionary-like row access
        cursor = conn.cursor()
        if new_db:
            cursor.executescript(''' CREATE TABLE messages (message_id INTEGER PRIMARY KEY AUTOINCREMENT, aftn_header TEXT NOT NULL, priority_id INTEGER NOT NULL, filing_time DATETIME NOT NULL, originator TEXT NOT NULL, content TEXT NOT NULL, status TEXT NOT NULL, created_at DATETIME DEFAULT CURRENT_TIMESTAMP, FOREIGN KEY (priority_id) REFERENCES priorities(priority_id)); CREATE TABLE addresses (address_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, address_type TEXT NOT NULL, address_value TEXT NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE priorities (priority_id INTEGER PRIMARY KEY AUTOINCREMENT, priority_code TEXT NOT NULL UNIQUE, description TEXT NOT NULL); CREATE TABLE message_types (type_id INTEGER PRIMARY KEY AUTOINCREMENT, type_code TEXT NOT NULL UNIQUE, description TEXT NOT NULL); CREATE TABLE message_type_mapping (mapping_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, type_id INTEGER NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id), FOREIGN KEY (type_id) REFERENCES message_types(type_id)); CREATE TABLE routing_info (routing_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, route_point TEXT NOT NULL, timestamp DATETIME NOT NULL, status TEXT NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE station_directory (station_id INTEGER PRIMARY KEY AUTOINCREMENT, station_code TEXT UNIQUE NOT NULL, station_name TEXT NOT NULL, country TEXT NOT NULL, region TEXT NOT NULL, coordinates TEXT, ip_address TEXT, port INTEGER, active BOOLEAN DEFAULT TRUE); CREATE TABLE audit_log (log_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER, action TEXT NOT NULL, performed_by TEXT NOT NULL, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, details TEXT, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE network_config (config_id INTEGER PRIMARY KEY AUTOINCREMENT, local_station_code TEXT NOT NULL, listen_ip TEXT NOT NULL, listen_port INTEGER NOT NULL, last_updated DATETIME DEFAULT CURRENT_TIMESTAMP); ''')
            cursor.executescript(''' CREATE INDEX idx_messages_filing_time ON messages(filing_time); CREATE INDEX idx_addresses_message_id ON addresses(message_id); CREATE INDEX idx_routing_info_message_id ON routing_info(message_id); ''')
            priorities = [ ('SS', 'Distress'), ('DD', 'Urgency'), ('FF', 'Flight Safety'), ('GG', 'Meteorological'), ('KK', 'Administrative') ]
            cursor.executemany('INSERT INTO priorities (priority_code, description) VALUES (?, ?)', priorities)
            message_types = [ ('FPL', 'Filed Flight Plan'), ('CHG', 'Modification'), ('CNL', 'Cancellation'), ('DLA', 'Delay'), ('DEP', 'Departure'), ('ARR', 'Arrival'), ('NOTAM', 'Notice to Airmen'), ('METAR', 'Weather Report'), ('TAF', 'Forecast'), ('SIGMET', 'Significant Weather') ]
            cursor.executemany('INSERT INTO message_types (type_code, description) VALUES (?, ?)', message_types)
            cursor.execute('INSERT INTO network_config (local_station_code, listen_ip, listen_port) VALUES (?, ?, ?)', ('EGLLZPZX', '127.0.0.1', 5000))
            self._populate_sample_stations(cursor)
            conn.commit()
            print(f"New database created at {self.db_path}")
        else:
            print(f"Connected to existing database at {self.db_path}")
        return conn
    def _populate_sample_stations(self, cursor):
        stations = [ ('KJFK', 'JFK Airport', 'United States', 'North America', '40.6413° N, 73.7781° W', '127.0.0.1', 5001, True), ('EGLL', 'Heathrow Airport', 'United Kingdom', 'Europe', '51.4700° N, 0.4543° W', '127.0.0.1', 5002, True), ('RJTT', 'Haneda Airport', 'Japan', 'Asia', '35.5494° N, 139.7798° E', '127.0.0.1', 5003, True), ]
        cursor.executemany('INSERT INTO station_directory (station_code, station_name, country, region, coordinates, ip_address, port, active) VALUES (?, ?, ?, ?, ?, ?, ?, ?)', stations)
    def close(self):
        if self.conn:
            self.conn.close()
            print("Database connection closed.")
    def store_message(self, aftn_header: str, priority_code: str, filing_time: datetime.datetime, originator: str, addressees: List[str], content: str, message_type: str) -> int:
        cursor = self.conn.cursor()
        try:
            cursor.execute('SELECT priority_id FROM priorities WHERE priority_code = ?', (priority_code,))
            priority_id = cursor.fetchone()[0]
            cursor.execute('SELECT type_id FROM message_types WHERE type_code = ?', (message_type,))
            type_id = cursor.fetchone()[0]
            cursor.execute('INSERT INTO messages (aftn_header, priority_id, filing_time, originator, content, status) VALUES (?, ?, ?, ?, ?, ?)', (aftn_header, priority_id, filing_time, originator, content, 'RECEIVED'))
            message_id = cursor.lastrowid
            cursor.execute('INSERT INTO addresses (message_id, address_type, address_value) VALUES (?, ?, ?)', (message_id, 'ORIGINATOR', originator))
            for addressee in addressees:
                cursor.execute('INSERT INTO addresses (message_id, address_type, address_value) VALUES (?, ?, ?)', (message_id, 'ADDRESSEE', addressee))
            cursor.execute('INSERT INTO message_type_mapping (message_id, type_id) VALUES (?, ?)', (message_id, type_id))
            cursor.execute('INSERT INTO routing_info (message_id, route_point, timestamp, status) VALUES (?, ?, ?, ?)', (message_id, originator, datetime.datetime.now(), 'RECEIVED'))
            cursor.execute('INSERT INTO audit_log (message_id, action, performed_by, details) VALUES (?, ?, ?, ?)', (message_id, 'CREATED', 'SYSTEM', f"Received from {originator}"))
            self.conn.commit()
            return message_id
        except Exception as e:
            self.conn.rollback()
            raise Exception(f"Failed to store message: {e}")
    def update_message_status(self, message_id: int, status: str, performed_by: str) -> bool:
        cursor = self.conn.cursor()
        try:
            cursor.execute('UPDATE messages SET status = ? WHERE message_id = ?', (status, message_id))
            cursor.execute('INSERT INTO audit_log (message_id, action, performed_by, details) VALUES (?, ?, ?, ?)', (message_id, 'STATUS_UPDATE', performed_by, f"Status set to {status}"))
            self.conn.commit()
            return True
        except Exception as e:
            self.conn.rollback()
            raise Exception(f"Failed to update status: {e}")
    def get_message_by_id(self, message_id: int) -> Dict[str, Any]:
        cursor = self.conn.cursor()
        cursor.execute(''' SELECT m.*, p.priority_code, mt.type_code, mt.description FROM messages m JOIN priorities p ON m.priority_id = p.priority_id LEFT JOIN message_type_mapping mtm ON m.message_id = mtm.message_id LEFT JOIN message_types mt ON mtm.type_id = mt.type_id WHERE m.message_id = ? ''', (message_id,))
        msg = cursor.fetchone()
        if not msg:
            raise ValueError(f"Message {message_id} not found")
        message = dict(msg)
        cursor.execute('SELECT address_value FROM addresses WHERE message_id = ? AND address_type = "ADDRESSEE"', (message_id,))
        message['addressees'] = [row['address_value'] for row in cursor.fetchall()]
        cursor.execute('SELECT route_point, timestamp, status FROM routing_info WHERE message_id = ?', (message_id,))
        message['routing'] = [dict(row) for row in cursor.fetchall()]
        return message
    def search_messages(self, start_date: Optional[datetime.datetime] = None, end_date: Optional[datetime.datetime] = None, originator: Optional[str] = None, addressee: Optional[str] = None, status: Optional[str] = None, message_type: Optional[str] = None, priority: Optional[str] = None) -> List[Dict[str, Any]]:
        query = ''' SELECT m.message_id, m.aftn_header, p.priority_code, m.filing_time, m.originator, m.status, mt.type_code FROM messages m JOIN priorities p ON m.priority_id = p.priority_id LEFT JOIN message_type_mapping mtm ON m.message_id = mtm.message_id LEFT JOIN message_types mt ON mtm.type_id = mt.type_id '''
        params = []
        conditions = []
        if addressee:
            query += ' JOIN addresses a ON m.message_id = a.message_id AND a.address_type = "ADDRESSEE" '
            conditions.append('a.address_value LIKE ?')
            params.append(f'%{addressee}%')
        if start_date:
            conditions.append('m.filing_time >= ?')
            params.append(start_date)
        if end_date:
            conditions.append('m.filing_time <= ?')
            params.append(end_date)
        if originator:
            conditions.append('m.originator LIKE ?')
            params.append(f'%{originator}%')
        if status:
            conditions.append('m.status = ?')
            params.append(status)
        if message_type:
            conditions.append('mt.type_code = ?')
            params.append(message_type)
        if priority:
            conditions.append('p.priority_code = ?')
            params.append(priority)
        if conditions:
            query += ' WHERE ' + ' AND '.join(conditions)
        query += ' ORDER BY m.filing_time DESC'
        cursor = self.conn.cursor()
        cursor.execute(query, params)
        return [dict(row) for row in cursor.fetchall()]
    def get_all_stations(self) -> List[Dict[str, Any]]:
        cursor = self.conn.cursor()
        cursor.execute('SELECT * FROM station_directory ORDER BY station_code')
        return [dict(row) for row in cursor.fetchall()]
    def get_station_network_info(self, station_code: str) -> Optional[Dict[str, Any]]:
        cursor = self.conn.cursor()
        cursor.execute('SELECT ip_address, port FROM station_directory WHERE station_code = ? AND active = TRUE', (station_code,))
        row = cursor.fetchone()
        return {'ip_address': row[0], 'port': row[1]} if row else None
    def get_network_config(self) -> Dict[str, Any]:
        cursor = self.conn.cursor()
        cursor.execute('SELECT local_station_code, listen_ip, listen_port FROM network_config ORDER BY config_id DESC LIMIT 1')
        row = cursor.fetchone()
        return dict(row) if row else {'local_station_code': 'EGLLZPZX', 'listen_ip': '127.0.0.1', 'listen_port': 5000}
    def update_network_config(self, local_station_code: str, listen_ip: str, listen_port: int) -> bool:
        cursor = self.conn.cursor()
        try:
            cursor.execute('INSERT INTO network_config (local_station_code, listen_ip, listen_port) VALUES (?, ?, ?)', (local_station_code, listen_ip, listen_port))
            self.conn.commit()
            return True
        except Exception as e:
            self.conn.rollback()
            raise Exception(f"Failed to update network config: {e}")
    def parse_aftn_message(self, raw_message: str) -> Dict[str, Any]:
        lines = raw_message.strip().split('\n')
        if len(lines) < 3:
            raise ValueError("Invalid AFTN message: too few lines")
        header_match = re.match(r'^\s*(\w+)\s+(\w+)\s+(\d{6})\s*$', lines[0])
        if not header_match:
            raise ValueError(f"Invalid header: {lines[0]}")
        priority_code, originator, filing_time_str = header_match.groups()
        try:
            day, hour, minute = map(int, [filing_time_str[:2], filing_time_str[2:4], filing_time_str[4:]])
            now = datetime.datetime.now()
            filing_time = datetime.datetime(now.year, now.month, day, hour, minute)
            if filing_time > now and (now.day - day) > 20:
                filing_time = filing_time.replace(month=filing_time.month - 1 if filing_time.month > 1 else 12, year=filing_time.year - 1 if filing_time.month == 1 else filing_time.year)
        except ValueError:
            raise ValueError(f"Invalid filing time: {filing_time_str}")
        address_parts = lines[1].strip().split()
        if len(address_parts) < 2:
            raise ValueError(f"Invalid address line: {lines[1]}")
        originator = address_parts[0]
        addressees = address_parts[1:]
        content = '\n'.join(lines[2:]).strip()
        message_type = 'GEN'
        first_line = lines[2].strip()
        type_match = re.match(r'^(\w{3})', first_line)
        if type_match and type_match.group(1) in ['FPL', 'CHG', 'CNL', 'DLA', 'DEP', 'ARR']:
            message_type = type_match.group(1)
        elif 'NOTAM' in first_line:
            message_type = 'NOTAM'
        elif first_line.startswith('METAR'):
            message_type = 'METAR'
        elif first_line.startswith('TAF'):
            message_type = 'TAF'
        return {
            'aftn_header': f"{priority_code} {originator} {filing_time_str}", 'priority_code': priority_code, 'filing_time': filing_time, 'originator': originator, 'addressees': addressees, 'content': content, 'message_type': message_type }
    def store_raw_message(self, raw_message: str) -> int:
        parsed = self.parse_aftn_message(raw_message)
        return self.store_message(parsed['aftn_header'], parsed['priority_code'], parsed['filing_time'], parsed['originator'], parsed['addressees'], parsed['content'], parsed['message_type'])
class AFTNMessageBuilder:
    @staticmethod
    def create_aftn_message(priority_code: str, addressees: List[str], originator: str, content: str) -> str:
        now = datetime.datetime.now()
        filing_time = now.strftime("%d%H%M")
        header = f"{priority_code} {originator} {filing_time}"
        address_line = f"{originator} {' '.join(addressees)}"
        return f"{header}\n{address_line}\n{content}"
class AFTNNetworkHandler:
    def __init__(self, db: AFTNDatabase):
        self.db = db
        self.server_socket = None
        self.client_socket = None
        self.is_running = False
        self.server_thread = None
        self.clients = set()
        self.config = self.db.get_network_config()
    def start_server(self) -> bool:
        if self.is_running:
            return False
        try:
            self.config = self.db.get_network_config()
            self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.server_socket.bind((self.config['listen_ip'], self.config['listen_port']))
            self.server_socket.listen(5)
            self.is_running = True
            self.server_thread = threading.Thread(target=self._accept_connections)
            self.server_thread.daemon = True
            self.server_thread.start()
            print(f"Server started on {self.config['listen_ip']}:{self.config['listen_port']}")
            return True
        except Exception as e:
            print(f"Failed to start server: {e}")
            if self.server_socket:
                self.server_socket.close()
            self.is_running = False
            return False
    def stop_server(self) -> bool:
        if not self.is_running:
            return False
        try:
            self.is_running = False
            for client in self.clients:
                client.close()
            self.clients.clear()
            if self.server_socket:
                self.server_socket.close()
                self.server_socket = None
            print("Server stopped")
            return True
        except Exception as e:
            print(f"Failed to stop server: {e}")
            return False
    def _accept_connections(self):
        while self.is_running:
            try:
                client_socket, addr = self.server_socket.accept()
                self.clients.add(client_socket)
                threading.Thread(target=self._handle_client, args=(client_socket, addr), daemon=True).start()
                print(f"Connected: {addr}")
            except Exception as e:
                if self.is_running:
                    print(f"Connection error: {e}")
    def _handle_client(self, client_socket: socket.socket, addr: Tuple[str, int]):
        try:
            buffer = ""
            while self.is_running:
                data = client_socket.recv(1024).decode('utf-8')
                if not data:
                    break
                buffer += data
                if "\n\n" in buffer:
                    messages = buffer.split("\n\n")
                    buffer = messages.pop()
                    for msg in messages:
                        if msg.strip():
                            message_id = self.db.store_raw_message(msg)
                            print(f"Stored message {message_id} from {addr}")
        except Exception as e:
            print(f"Client {addr} error: {e}")
        finally:
            client_socket.close()
            self.clients.discard(client_socket)
            print(f"Disconnected: {addr}")
    def send_message(self, host: str, port: int, message: str) -> bool:
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(10)
            sock.connect((host, port))
            if not message.endswith("\n\n"):
                message += "\n\n"
            sock.sendall(message.encode('utf-8'))
            sock.close()
            print(f"Sent to {host}:{port}")
            return True
        except Exception as e:
            print(f"Send error to {host}:{port}: {e}")
            return False
class AFTNApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("AFTN Message System")
        self.root.geometry("1024x768")
        self.db = AFTNDatabase()
        self.network = AFTNNetworkHandler(self.db)
        self.main_frame = ttk.Frame(root, padding="10")
        self.main_frame.pack(fill=tk.BOTH, expand=True)
        self.notebook = ttk.Notebook(self.main_frame)
        self.notebook.pack(fill=tk.BOTH, expand=True)
        self.create_tabs()
        self.status_var = tk.StringVar(value="Ready")
        ttk.Label(root, textvariable=self.status_var, relief=tk.SUNKEN, anchor=tk.W).pack(side=tk.BOTTOM, fill=tk.X)
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.load_initial_data()
    def create_tabs(self):
        self.msg_tab = ttk.Frame(self.notebook)
        self.notebook.add(self.msg_tab, text="Messages")
        self.create_message_tab()
        self.inbox_tab = ttk.Frame(self.notebook)
        self.notebook.add(self.inbox_tab, text="Inbox")
        self.create_inbox_tab()
        self.compose_tab = ttk.Frame(self.notebook)
        self.notebook.add(self.compose_tab, text="Compose")
        self.create_compose_tab()
        self.net_tab = ttk.Frame(self.notebook)
        self.notebook.add(self.net_tab, text="Network")
        self.create_network_tab()
        self.stations_tab = ttk.Frame(self.notebook)
        self.notebook.add(self.stations_tab, text="Stations")
        self.create_stations_tab()
    def create_message_tab(self):
        columns = ("ID", "Priority", "Time", "Originator", "Type", "Status")
        self.msg_tree = ttk.Treeview(self.msg_tab, columns=columns, show="headings")
        for col in columns:
            self.msg_tree.heading(col, text=col)
            self.msg_tree.column(col, width=100, anchor=tk.CENTER)
        self.msg_tree.pack(fill=tk.BOTH, expand=True)
        self.msg_tree.bind("<<TreeviewSelect>>", self.on_message_select)
        self.msg_details = scrolledtext.ScrolledText(self.msg_tab, height=10)
        self.msg_details.pack(fill=tk.BOTH, expand=True, pady=5)
        filter_frame = ttk.Frame(self.msg_tab)
        filter_frame.pack(fill=tk.X, pady=5)
        ttk.Button(filter_frame, text="Refresh", command=self.refresh_messages).pack(side=tk.LEFT, padx=5)
    def create_inbox_tab(self):
        columns = ("ID", "Priority", "Time", "Originator", "Type", "Status")
        self.inbox_tree = ttk.Treeview(self.inbox_tab, columns=columns, show="headings")
        for col in columns:
            self.inbox_tree.heading(col, text=col)
            self.inbox_tree.column(col, width=100, anchor=tk.CENTER)
        self.inbox_tree.pack(fill=tk.BOTH, expand=True)
        self.inbox_tree.bind("<<TreeviewSelect>>", self.on_inbox_select)
        self.inbox_details = scrolledtext.ScrolledText(self.inbox_tab, height=10)
        self.inbox_details.pack(fill=tk.BOTH, expand=True, pady=5)
        btn_frame = ttk.Frame(self.inbox_tab)
        btn_frame.pack(fill=tk.X, pady=5)
        ttk.Button(btn_frame, text="Mark Read", command=self.mark_read).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Reply", command=self.reply_message).pack(side=tk.LEFT, padx=5)
    def create_compose_tab(self):
        header_frame = ttk.LabelFrame(self.compose_tab, text="Header")
        header_frame.pack(fill=tk.X, pady=5)
        ttk.Label(header_frame, text="Priority:").grid(row=0, column=0, padx=5, pady=5)
        self.compose_priority = ttk.Combobox(header_frame, values=['SS', 'DD', 'FF', 'GG', 'KK'], state="readonly")
        self.compose_priority.grid(row=0, column=1, padx=5, pady=5)
        self.compose_priority.set('GG')
        ttk.Label(header_frame, text="From:").grid(row=0, column=2, padx=5, pady=5)
        self.compose_from = ttk.Entry(header_frame)
        self.compose_from.grid(row=0, column=3, padx=5, pady=5)
        ttk.Label(header_frame, text="To:").grid(row=1, column=0, padx=5, pady=5)
        self.compose_to = ttk.Entry(header_frame, width=50)
        self.compose_to.grid(row=1, column=1, columnspan=3, padx=5, pady=5)
        self.compose_content = scrolledtext.ScrolledText(self.compose_tab, height=15)
        self.compose_content.pack(fill=tk.BOTH, expand=True, pady=5)
        btn_frame = ttk.Frame(self.compose_tab)
        btn_frame.pack(fill=tk.X, pady=5)
        ttk.Button(btn_frame, text="Send", command=self.send_message).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Clear", command=self.clear_compose).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Save Draft", command=self.save_draft).pack(side=tk.LEFT, padx=5)
    def create_network_tab(self):
        config_frame = ttk.LabelFrame(self.net_tab, text="Server Config")
        config_frame.pack(fill=tk.X, pady=5)
        ttk.Label(config_frame, text="Station Code:").grid(row=0, column=0, padx=5, pady=5)
        self.net_station = ttk.Entry(config_frame)
        self.net_station.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(config_frame, text="IP:").grid(row=1, column=0, padx=5, pady=5)
        self.net_ip = ttk.Entry(config_frame)
        self.net_ip.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(config_frame, text="Port:").grid(row=2, column=0, padx=5, pady=5)
        self.net_port = ttk.Entry(config_frame)
        self.net_port.grid(row=2, column=1, padx=5, pady=5)
        btn_frame = ttk.Frame(config_frame)
        btn_frame.grid(row=3, column=0, columnspan=2, pady=5)
        ttk.Button(btn_frame, text="Start", command=self.start_server).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Stop", command=self.stop_server).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Save", command=self.save_network_config).pack(side=tk.LEFT, padx=5)
        self.net_log = scrolledtext.ScrolledText(self.net_tab, height=10)
        self.net_log.pack(fill=tk.BOTH, expand=True, pady=5)
    def create_stations_tab(self):
        columns = ("Code", "Name", "Country", "Region", "Status")
        self.stations_tree = ttk.Treeview(self.stations_tab, columns=columns, show="headings")
        for col in columns:
            self.stations_tree.heading(col, text=col)
            self.stations_tree.column(col, width=150 if col == "Name" else 100)
        self.stations_tree.pack(fill=tk.BOTH, expand=True)
        btn_frame = ttk.Frame(self.stations_tab)
        btn_frame.pack(fill=tk.X, pady=5)
        ttk.Button(btn_frame, text="Refresh", command=self.load_stations).pack(side=tk.LEFT, padx=5)
    def load_initial_data(self):
        config = self.db.get_network_config()
        self.compose_from.insert(0, config['local_station_code'])
        self.net_station.insert(0, config['local_station_code'])
        self.net_ip.insert(0, config['listen_ip'])
        self.net_port.insert(0, str(config['listen_port']))
        self.refresh_messages()
        self.load_stations()
    def refresh_messages(self):
        self.msg_tree.delete(*self.msg_tree.get_children())
        self.inbox_tree.delete(*self.inbox_tree.get_children())
        messages = self.db.search_messages()
        for msg in messages:
            time_str = msg['filing_time'].strftime("%Y-%m-%d %H:%M") if isinstance(msg['filing_time'], datetime.datetime) else msg['filing_time']
            values = (msg['message_id'], msg['priority_code'], time_str, msg['originator'], msg.get('type_code', 'GEN'), msg['status'])
            self.msg_tree.insert("", tk.END, values=values)
            if msg['status'] in ['RECEIVED', 'READ']:
                self.inbox_tree.insert("", tk.END, values=values)
    def on_message_select(self, event):
        sel = self.msg_tree.selection()
        if sel:
            msg_id = self.msg_tree.item(sel[0], 'values')[0]
            msg = self.db.get_message_by_id(int(msg_id))
            self.msg_details.delete("1.0", tk.END)
            details = f"ID: {msg['message_id']}\nPriority: {msg['priority_code']}\nTime: {msg['filing_time']}\nFrom: {msg['originator']}\nTo: {', '.join(msg['addressees'])}\n\n{msg['content']}"
            self.msg_details.insert(tk.END, details)
    def on_inbox_select(self, event):
        sel = self.inbox_tree.selection()
        if sel:
            msg_id = self.inbox_tree.item(sel[0], 'values')[0]
            msg = self.db.get_message_by_id(int(msg_id))
            self.inbox_details.delete("1.0", tk.END)
            details = f"ID: {msg['message_id']}\nPriority: {msg['priority_code']}\nTime: {msg['filing_time']}\nFrom: {msg['originator']}\nTo: {', '.join(msg['addressees'])}\n\n{msg['content']}"
            self.inbox_details.insert(tk.END, details)
    def mark_read(self):
        sel = self.inbox_tree.selection()
        if sel:
            msg_id = self.inbox_tree.item(sel[0], 'values')[0]
            self.db.update_message_status(int(msg_id), 'READ', 'USER')
            self.refresh_messages()
    def reply_message(self):
        sel = self.inbox_tree.selection()
        if sel:
            msg_id = self.inbox_tree.item(sel[0], 'values')[0]
            msg = self.db.get_message_by_id(int(msg_id))
            self.notebook.select(self.compose_tab)
            self.compose_to.delete(0, tk.END)
            self.compose_to.insert(0, msg['originator'])
            self.compose_content.delete("1.0", tk.END)
            self.compose_content.insert(tk.END, f"Ref: {msg['aftn_header']}\n\n")
    def send_message(self):
        if not all([self.compose_priority.get(), self.compose_from.get(), self.compose_to.get(), self.compose_content.get("1.0", tk.END).strip()]):
            messagebox.showerror("Error", "All fields are required")
            return
        msg = AFTNMessageBuilder.create_aftn_message(self.compose_priority.get(), self.compose_to.get().split(), self.compose_from.get(), self.compose_content.get("1.0", tk.END))
        if messagebox.askyesno("Confirm", "Send this message?"):
            config = self.db.get_network_config()
            if self.network.send_message(config['listen_ip'], config['listen_port'], msg):
                msg_id = self.db.store_raw_message(msg)
                self.db.update_message_status(msg_id, 'SENT', 'USER')
                messagebox.showinfo("Success", "Message sent")
                self.clear_compose()
                self.refresh_messages()
    def save_draft(self):
        if not all([self.compose_from.get(), self.compose_content.get("1.0", tk.END).strip()]):
            messagebox.showerror("Error", "Originator and content are required")
            return
        msg = AFTNMessageBuilder.create_aftn_message(self.compose_priority.get() or 'GG', self.compose_to.get().split() or ['DRAFT'], self.compose_from.get(), self.compose_content.get("1.0", tk.END))
        msg_id = self.db.store_raw_message(msg)
        self.db.update_message_status(msg_id, 'DRAFT', 'USER')
        messagebox.showinfo("Success", "Draft saved")
        self.clear_compose()
        self.refresh_messages()
    def clear_compose(self):
        self.compose_priority.set('GG')
        self.compose_to.delete(0, tk.END)
        self.compose_content.delete("1.0", tk.END)
    def start_server(self):
        if self.network.start_server():
            self.net_log.insert(tk.END, f"{datetime.datetime.now()}: Server started\n")
    def stop_server(self):
        if self.network.stop_server():
            self.net_log.insert(tk.END, f"{datetime.datetime.now()}: Server stopped\n")
    def save_network_config(self):
        try:
            self.db.update_network_config(self.net_station.get(), self.net_ip.get(), int(self.net_port.get()))
            messagebox.showinfo("Success", "Network config saved")
        except ValueError:
            messagebox.showerror("Error", "Port must be a number")
    def load_stations(self):
        self.stations_tree.delete(*self.stations_tree.get_children())
        for station in self.db.get_all_stations():
            self.stations_tree.insert("", tk.END, values=(station['station_code'], station['station_name'], station['country'], station['region'], "Active" if station['active'] else "Inactive" ))
    def on_close(self):
        if messagebox.askokcancel("Quit", "Are you sure?"):
            self.network.stop_server()
            self.db.close()
            self.root.destroy()
if __name__ == "__main__":
    root = tk.Tk()
    app = AFTNApp(root)
    root.mainloop()