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
from dateutil.relativedelta import relativedelta
import threading
class AFTNDatabase:
    def __init__(self, db_path: str = "aftn_messages.db"):
        self.db_path = db_path
        self.conn = None
        self.lock = threading.Lock() # Thread safety
        self.conn = self.initialize_database()
    def initialize_database(self) -> sqlite3.Connection:
        with self.lock: #Wrap in lock
            new_db = not os.path.exists(self.db_path)
            conn = sqlite3.connect(self.db_path)
            conn.row_factory = sqlite3.Row #Dictionary-like row access
            cursor = conn.cursor()
        if new_db:
            cursor.executescript(''' CREATE TABLE messages (message_id INTEGER PRIMARY KEY AUTOINCREMENT, aftn_header TEXT NOT NULL, priority_id INTEGER NOT NULL, filing_time DATETIME NOT NULL, originator TEXT NOT NULL, content TEXT NOT NULL, status TEXT NOT NULL, created_at DATETIME DEFAULT CURRENT_TIMESTAMP, FOREIGN KEY (priority_id) REFERENCES priorities(priority_id)); CREATE TABLE addresses (address_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, address_type TEXT NOT NULL, address_value TEXT NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE priorities (priority_id INTEGER PRIMARY KEY AUTOINCREMENT, priority_code TEXT NOT NULL UNIQUE, description TEXT NOT NULL); CREATE TABLE message_types (type_id INTEGER PRIMARY KEY AUTOINCREMENT, type_code TEXT NOT NULL UNIQUE, description TEXT NOT NULL); CREATE TABLE message_type_mapping (mapping_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, type_id INTEGER NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id), FOREIGN KEY (type_id) REFERENCES message_types(type_id)); CREATE TABLE routing_info (routing_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER NOT NULL, route_point TEXT NOT NULL, timestamp DATETIME NOT NULL, status TEXT NOT NULL, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE station_directory (station_id INTEGER PRIMARY KEY AUTOINCREMENT, station_code TEXT UNIQUE NOT NULL, station_name TEXT NOT NULL, country TEXT NOT NULL, region TEXT NOT NULL, coordinates TEXT, ip_address TEXT, port INTEGER, active BOOLEAN DEFAULT TRUE); CREATE TABLE audit_log (log_id INTEGER PRIMARY KEY AUTOINCREMENT, message_id INTEGER, action TEXT NOT NULL, performed_by TEXT NOT NULL, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, details TEXT, FOREIGN KEY (message_id) REFERENCES messages(message_id)); CREATE TABLE network_config (config_id INTEGER PRIMARY KEY AUTOINCREMENT, local_station_code TEXT NOT NULL, listen_ip TEXT NOT NULL, listen_port INTEGER NOT NULL, last_updated DATETIME DEFAULT CURRENT_TIMESTAMP); ''')
            cursor.executescript(''' CREATE INDEX idx_messages_filing_time ON messages(filing_time); CREATE INDEX idx_addresses_message_id ON addresses(message_id); CREATE INDEX idx_routing_info_message_id ON routing_info(message_id); ''')
            priorities = [ ('SS', 'Distress'), ('DD', 'Urgency'), ('FF', 'Flight Safety'), ('GG', 'Meteorological'), ('KK', 'Administrative') ]
            cursor.executemany('INSERT INTO priorities (priority_code, description) VALUES (?, ?)', priorities)
            message_types = [('FPL', 'Filed Flight Plan - Contains details of intended flight'), ('CHG', 'Modification Message - Changes to previously filed flight plan'), ('CNL', 'Cancellation Message - Cancels previously filed flight plan'), ('DLA', 'Delay Message - Reports delay to previously announced departure time'), ('DEP', 'Departure Message - Reports actual departure of aircraft'), ('ARR', 'Arrival Message - Reports actual arrival of aircraft'), ('NOTAM', 'Notice to Airmen - Essential information for flight operations'), ('METAR', 'Meteorological Aerodrome Report - Routine weather observation'), ('TAF', 'Terminal Aerodrome Forecast - Airport weather forecast'), ('SIGMET', 'Significant Meteorological Information - Weather hazard warnings'), ('ATIS', 'Automatic Terminal Information Service - Airport information'), ('ATC', 'Air Traffic Control Messages - Clearances, instructions, and advisories'), ('ALR', 'Alerting Message - Regarding aircraft in emergency'), ('RQP', 'Request Flight Plan - Request for flight plan information'), ('RQS', 'Request Supplementary Flight Plan Information')]
            cursor.executemany('INSERT INTO message_types (type_code, description) VALUES (?, ?)', message_types)
            cursor.execute('INSERT INTO network_config (local_station_code, listen_ip, listen_port) VALUES (?, ?, ?)', ('LTAATCXX', '135.0.10.15', 50160))
            self._populate_sample_stations(cursor)
            conn.commit()
            print(f"New database created at {self.db_path}")
        else:
            print(f"Connected to existing database at {self.db_path}")
        return conn
    def _populate_sample_stations(self, cursor):
        stations = [('KJFK', 'John F. Kennedy International Airport', 'United States', 'North America', '40.6413° N, 73.7781° W', '127.0.0.1', 5003, True), ('EGLL', 'London Heathrow Airport', 'United Kingdom', 'Europe', '51.4700° N, 0.4543° W', '127.0.0.1', 5003, True), ('RJTT', 'Tokyo Haneda Airport', 'Japan', 'Asia', '35.5494° N, 139.7798° E', '127.0.0.1', 5003, True), ('YSSY', 'Sydney Kingsford Smith Airport', 'Australia', 'Oceania', '33.9399° S, 151.1753° E', '127.0.0.1', 5003, True), ('FAJS', 'O.R. Tambo International Airport', 'South Africa', 'Africa', '26.1325° S, 28.2425° E', '127.0.0.1', 5003, True), ('SBGL', 'Rio de Janeiro/Galeão International Airport', 'Brazil', 'South America', '22.8100° S, 43.2500° W', '127.0.0.1', 5003, True), ('OMDB', 'Dubai International Airport', 'United Arab Emirates', 'Middle East', '25.2528° N, 55.3644° E', '127.0.0.1', 5003, True), ('CYYZ', 'Toronto Pearson International Airport', 'Canada', 'North America', '43.6777° N, 79.6248° W', '127.0.0.1', 5003, True), ('LIRF', 'Rome Fiumicino Airport', 'Italy', 'Europe', '41.8003° N, 12.2389° E', '127.0.0.1', 5003, True), ('VHHH', 'Hong Kong International Airport', 'Hong Kong', 'Asia', '22.3080° N, 113.9185° E', '127.0.0.1', 5003, True), ('EDDF', 'Frankfurt Airport', 'Germany', 'Europe', '50.0379° N, 8.5622° E', '127.0.0.1', 5003, True), ('LFPG', 'Paris Charles de Gaulle Airport', 'France', 'Europe', '49.0097° N, 2.5479° E', '127.0.0.1', 5003, True), ('LEMD', 'Adolfo Suárez Madrid–Barajas Airport', 'Spain', 'Europe', '40.4983° N, 3.5676° W', '127.0.0.1', 5003, True), ('LTBA', 'Istanbul Airport', 'Turkey', 'Europe/Asia', '41.2608° N, 28.7418° E', '127.0.0.1', 5003, True), ('WMKK', 'Kuala Lumpur International Airport', 'Malaysia', 'Asia', '2.7456° N, 101.7099° E', '127.0.0.1', 5003, True), ('VABB', 'Chhatrapati Shivaji Maharaj International Airport', 'India', 'Asia', '19.0896° N, 72.8656° E', '127.0.0.1', 5003, True), ('VIDP', 'Indira Gandhi International Airport', 'India', 'Asia', '28.5561° N, 77.1000° E', '127.0.0.1', 5003, True), ('ZBAA', 'Beijing Capital International Airport', 'China', 'Asia', '40.0799° N, 116.6031° E', '127.0.0.1', 5003, True), ('ZGGG', 'Guangzhou Baiyun International Airport', 'China', 'Asia', '23.3959° N, 113.3080° E', '127.0.0.1', 5003, True), ('VTBS', 'Suvarnabhumi Airport', 'Thailand', 'Asia', '13.6900° N, 100.7501° E', '127.0.0.1', 5003, True), ('WADD', 'Ngurah Rai International Airport', 'Indonesia', 'Asia', '8.7481° S, 115.1672° E', '127.0.0.1', 5003, True), ('WSSS', 'Singapore Changi Airport', 'Singapore', 'Asia', '1.3644° N, 103.9915° E', '127.0.0.1', 5003, True), ('KLAX', 'Los Angeles International Airport', 'United States', 'North America', '33.9416° N, 118.4085° W', '127.0.0.1', 5003, True), ('KORD', 'O\'Hare International Airport', 'United States', 'North America', '41.9742° N, 87.9073° W', '127.0.0.1', 5003, True), ('KATL', 'Hartsfield–Jackson Atlanta International Airport', 'United States', 'North America', '33.6407° N, 84.4277° W', '127.0.0.1', 5003, True), ('KDFW', 'Dallas/Fort Worth International Airport', 'United States', 'North America', '32.8998° N, 97.0403° W', '127.0.0.1', 5003, True), ('KDEN', 'Denver International Airport', 'United States', 'North America', '39.8561° N, 104.6737° W', '127.0.0.1', 5003, True), ('MMGL', 'Guadalajara International Airport', 'Mexico', 'North America', '20.5218° N, 103.3112° W', '127.0.0.1', 5003, True), ('MMMX', 'Mexico City International Airport', 'Mexico', 'North America', '19.4363° N, 99.0721° W', '127.0.0.1', 5003, True), ('SCEL', 'Santiago International Airport', 'Chile', 'South America', '33.3930° S, 70.7858° W', '127.0.0.1', 5003, True), ('SAEZ', 'Ministro Pistarini International Airport', 'Argentina', 'South America', '34.8222° S, 58.5358° W', '127.0.0.1', 5003, True), ('NZAA', 'Auckland Airport', 'New Zealand', 'Oceania', '37.0082° S, 174.7850° E', '127.0.0.1', 5003, True), ('YPPH', 'Perth Airport', 'Australia', 'Oceania', '31.9385° S, 115.9672° E', '127.0.0.1', 5003, True), ('FACT', 'Cape Town International Airport', 'South Africa', 'Africa', '33.9648° S, 18.6017° E', '127.0.0.1', 5003, True), ('HECA', 'Cairo International Airport', 'Egypt', 'Africa', '30.1219° N, 31.4056° E', '127.0.0.1', 5003, True), ('DNMM', 'Murtala Muhammed International Airport', 'Nigeria', 'Africa', '6.5774° N, 3.3216° E', '127.0.0.1', 5003, True), ('DAAG', 'Houari Boumediene Airport', 'Algeria', 'Africa', '36.6910° N, 3.2154° E', '127.0.0.1', 5003, True), ('OJAI', 'Queen Alia International Airport', 'Jordan', 'Middle East', '31.7225° N, 35.9933° E', '127.0.0.1', 5003, True), ('OKBK', 'Kuwait International Airport', 'Kuwait', 'Middle East', '29.2267° N, 47.9689° E', '127.0.0.1', 5003, True), ('OBBI', 'Bahrain International Airport', 'Bahrain', 'Middle East', '26.2708° N, 50.6336° E', '127.0.0.1', 5003, True)]
        cursor.executemany('INSERT INTO station_directory (station_code, station_name, country, region, coordinates, ip_address, port, active) VALUES (?, ?, ?, ?, ?, ?, ?, ?)', stations)
    def close(self):
        if self.conn:
            self.conn.close()
            print("Database connection closed.")
    def store_message(self, aftn_header: str, priority_code: str, filing_time: datetime.datetime, originator: str, addressees: List[str], content: str, message_type: str) -> int:
        with self.lock:
            cursor = self.conn.cursor()
            cursor.execute('INSERT INTO messages (aftn_header, priority_id, filing_time, originator, content, status) VALUES (?, (SELECT priority_id FROM priorities WHERE priority_code = ?), ?, ?, ?, ?)', (aftn_header, priority_code, filing_time, originator, content, 'RECEIVED'))
            msg_id = cursor.lastrowid
            for addr in addressees:
                cursor.execute('INSERT INTO addresses (message_id, address_type, address_value) VALUES (?, "ADDRESSEE", ?)', (msg_id, addr))
            cursor.execute('INSERT INTO message_type_mapping (message_id, type_id) VALUES (?, (SELECT type_id FROM message_types WHERE type_code = ?))', (msg_id, message_type))
            self.conn.commit()
            return msg_id
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
    def station_exists(self, station_code: str) -> bool: #Validation method
        with self.lock:
            cursor = self.conn.cursor()
            cursor.execute('SELECT 1 FROM station_directory WHERE station_code = ?', (station_code,))
            return cursor.fetchone() is not None
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
        return dict(row) if row else {'local_station_code': 'LTAATCXX', 'listen_ip': '135.0.10.15', 'listen_port': 50160}
    def update_network_config(self, local_station_code: str, listen_ip: str, listen_port: int) -> bool:
        cursor = self.conn.cursor()
        try:
            cursor.execute('INSERT INTO network_config (local_station_code, listen_ip, listen_port) VALUES (?, ?, ?)', (local_station_code, listen_ip, listen_port))
            self.conn.commit()
            return True
        except Exception as e:
            self.conn.rollback()
            raise Exception(f"Failed to update network config: {e}")
    def parse_aftn_message(self, raw_message: str) -> dict:
        # Clean and split lines
        cleaned = raw_message.strip('\x01\x02\x0b\x03').replace('\r\n', '\n')
        lines = [line.strip() for line in cleaned.split('\n') if line.strip()]
        if len(lines) < 3:
            raise ValueError("Incomplete AFTN message")
        # Skip header line (e.g., CBX3638 27102533)
        aftn_start = 1
        priority_codes = ['FF', 'GG', 'SS', 'DD', 'KK', 'LL']
        if not any(lines[aftn_start].startswith(code) for code in priority_codes):
            raise ValueError(f"No valid AFTN priority found in line: {lines[aftn_start]}")
        # Parse priority and addressees
        priority_line = lines[aftn_start].split()
        priority = priority_line[0]
        addressees = priority_line[1:]
        # Parse filing time and originator
        originator_line = lines[aftn_start + 1]
        match = re.match(r'^(\d{6})\s+(\w+)$', originator_line)
        if not match:
            raise ValueError(f"Invalid originator line: {originator_line}")
        filing_time, originator = match.groups()
        # Content (everything after originator line)
        content = '\n'.join(lines[aftn_start + 2:]).strip()
        # Determine message type from content
        message_type = 'GEN'  # Default
        if content.startswith('(FPL'):
            message_type = 'FPL'
        elif content.startswith('(NOTAMN') or content.startswith('(NOTAMC'):
            message_type = 'NOTAM'
        elif content.startswith('(DEP'):
            message_type = 'DEP'
        elif content.startswith('(ARR'):
            message_type = 'ARR'
        # Add more types as needed
        # Filing time as datetime (assuming DDHHMM format)
        now = datetime.datetime.now()
        day, hour, minute = int(filing_time[:2]), int(filing_time[2:4]), int(filing_time[4:])
        filing_datetime = now.replace(hour=hour, minute=minute, second=0, microsecond=0)
        if day > now.day:
            filing_datetime = filing_datetime - relativedelta(months=1)
        filing_datetime = filing_datetime.replace(day=day)
        return {
            'aftn_header': lines[0],
            'priority_code': priority,
            'filing_time': filing_datetime,
            'originator': originator,
            'addressees': addressees,
            'content': content,
            'message_type': message_type
        }
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
    def __init__(self, db: AFTNDatabase, ui_callback):
        self.db = db
        self.ui_callback = ui_callback # This should be something like AFTNApp.refresh_messages
        self.client_socket = None
        self.is_running = False
        self.client_thread = None
        self.config = self.db.get_network_config()
    def start_con(self) -> bool:
        if self.is_running:
            return False
        try:
            self.config = self.db.get_network_config()
            self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client_socket.connect((self.config['listen_ip'], self.config['listen_port']))
            self.is_running = True
            self.client_thread = threading.Thread(target=self._handle_stream)
            self.client_thread.daemon = True
            self.client_thread.start()
            print(f"Connection started on {self.config['listen_ip']}:{self.config['listen_port']}")
            return True
        except Exception as e:
            print(f"Failed to start connection: {e}")
            if self.client_socket:
                self.client_socket.close()
            self.is_running = False
            return False
    def stop_con(self) -> bool:
        if not self.is_running:
            return False
        try:
            self.is_running = False
            if self.client_socket:
                self.client_socket.close()
                self.client_socket = None
            print("Connection stopped")
            return True
        except Exception as e:
            print(f"Failed to stop connection: {e}")
            return False
    def _handle_stream(self):
        try:
            buffer = ""
            print(f"Starting handle stream on {self.config['listen_ip']}:{self.config['listen_port']}")
            while self.is_running:
                data = self.client_socket.recv(1024).decode('utf-8')
                if not data:
                    print("No data received; server may have closed the connection")
                    break
                print(f"Received data: {repr(data)}")
                buffer += data
                # Normalize line endings and split on message boundaries
                buffer = buffer.replace('\r\n', '\n')
                if '\x03' in buffer:  # Use \x03 as message end marker
                    messages = buffer.split('\x03')
                    buffer = messages.pop()  # Keep incomplete message
                    for msg in messages:
                        if msg.strip():
                            # Strip control characters before processing
                            msg = msg.strip('\x01\x02\x0b')
                            if msg:
                                try:
                                    msg_id = self.db.store_raw_message(msg)
                                    print(f"Stored message with ID: {msg_id}")
                                    self.ui_callback()
                                except Exception as e:
                                    print(f"Error storing message: {e}")
                else:
                    print(f"No complete message yet; current buffer: {repr(buffer)}")
            print("Handle stream ended")
        except Exception as e:
            print(f"Handle stream error: {e}")
        finally:
            self.is_running = False
    def send_message(self, message: str) -> bool:
        try:
            if not message.endswith("\n\n"):
                message += "\n\n"
            self.client_socket.sendall(message.encode('utf-8'))
            print(f"The \"message\" is sent")
            return True
        except Exception as e:
            print(f"Message sending error: {e}")
            return False
class AFTNApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("AFTN Message System")
        self.root.geometry("1024x768")
        self.db = AFTNDatabase()
        self.network = AFTNNetworkHandler(self.db, lambda: self.root.after(0, self.refresh_messages))
        self.main_frame = ttk.Frame(root, padding="10")
        self.main_frame.pack(fill=tk.BOTH, expand=True)
        self.notebook = ttk.Notebook(self.main_frame)
        self.notebook.pack(fill=tk.BOTH, expand=True)
        self.create_tabs()
        self.status_var = tk.StringVar(value="Ready")
        ttk.Label(root, textvariable=self.status_var, relief=tk.SUNKEN, anchor=tk.W).pack(side=tk.BOTTOM, fill=tk.X)
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.load_initial_data()
        self.network = AFTNNetworkHandler(self.db, lambda: self.root.after(0, self._refresh_with_log))
    def _refresh_with_log(self):
        print("Callback triggered: Refreshing messages...")
        self.refresh_messages()
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
        config_frame = ttk.LabelFrame(self.net_tab, text="Connection Config")
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
        ttk.Button(btn_frame, text="Start", command=self.start_connection).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Stop", command=self.stop_connection).pack(side=tk.LEFT, padx=5)
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
        print("Starting refresh_messages...")
        self.msg_tree.delete(*self.msg_tree.get_children())
        self.inbox_tree.delete(*self.inbox_tree.get_children())
        messages = self.db.search_messages()
        print(f"Fetched {len(messages)} messages from the database")
        for msg in messages:
            time_str = msg['filing_time'].strftime("%Y-%m-%d %H:%M") if isinstance(msg['filing_time'], datetime.datetime) else msg['filing_time']
            values = (msg['message_id'], msg['priority_code'], time_str, msg['originator'], msg.get('type_code', 'GEN'), msg['status'])
            self.msg_tree.insert("", tk.END, values=values)
            print(f"Inserted message {msg['message_id']} into msg_tree")
            if msg['status'] in ['RECEIVED', 'READ']:
                self.inbox_tree.insert("", tk.END, values=values)
                print(f"Inserted message {msg['message_id']} into inbox_tree")
        # Force GUI update
        self.msg_tree.update_idletasks()
        self.inbox_tree.update_idletasks()
        self.root.update()
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
        if not self.db.station_exists(self.compose_from.get()): #Validate stations
            messagebox.showerror("Error", f"Invalid originator station: {self.compose_from.get()}")
            return
        for addr in self.compose_to.get().split():
            station_info = self.db.get_station_network_info(addr)
            if not station_info:
                messagebox.showerror("Error", f"No network info for {addr}")
                return
            if not self.db.station_exists(addr):
                messagebox.showerror("Error", f"Invalid addressee station: {addr}")
                return
        msg = AFTNMessageBuilder.create_aftn_message(self.compose_priority.get(), self.compose_to.get().split(), self.compose_from.get(), self.compose_content.get("1.0", tk.END))
        if messagebox.askyesno("Confirm", "Send this message?"):
            def send_async(): #Run in background thread
                try:
                    recipients = self.compose_to.get().split()
                    for addr in recipients:
                        station_info = self.db.get_station_network_info(addr)
                        if not station_info:
                            continue  # Already validated earlier
                        if self.network.send_message(msg): # Send to recipient's IP/port
                            msg_id = self.db.store_raw_message(msg)
                            self.db.update_message_status(msg_id, 'SENT', 'USER')
                    self.root.after(0, lambda: messagebox.showinfo("Success", "Message sent"))
                    self.root.after(0, self.clear_compose)
                    self.root.after(0, self.refresh_messages)
                except Exception as e:
                    self.root.after(0, lambda: messagebox.showerror("Error", str(e)))
            threading.Thread(target=send_async, daemon=True).start()
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
    def start_connection(self):
        if self.network.start_con():
            self.net_log.insert(tk.END, f"{datetime.datetime.now()}: Connection started\n")
    def stop_connection(self):
        if self.network.stop_con():
            self.net_log.insert(tk.END, f"{datetime.datetime.now()}: Connection stopped\n")
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
            self.network.stop_con()
            self.db.close()
            self.root.destroy()
if __name__ == "__main__":
    root = tk.Tk()
    app = AFTNApp(root)
    root.mainloop()