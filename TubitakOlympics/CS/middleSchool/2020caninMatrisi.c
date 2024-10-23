/*
CAN'IN MATRİSİ

Can matrisin karelerinde dolaşmayı çok sevmektedir. N satır ve M sütundan oluşan büyük bir matriste dolaşacaktır. Başlangıç noktası olarak matrisin sol üst noktası olan (1, 1) noktasını tercih etmektedir. Her hamlede ya sağdaki kareye ya da aşağıdaki kareye ilerleyerek (N, M) noktasına ulaşmak istemektedir. Ayrıca Can'ın sevmediği K tane kare vardır. Öyle ki bu K tane kareye asla uğramayacaktır. Anlatılan bu koşullar altında Can (1, 1) noktasından (N, M) noktasına kaç farklı şekilde gidebilir?

Not 1: Cevap çok büyük olabilir bu yüzden cevabın (10e9 + 7) ile bölümünden kalanını yazdırınız. Bir başka deyişle cevabın mod (10e9 + 7)'sını yazdırınız.
Not 2: (1, 1) ve (N, M) Can'ın hep sevdiği karelerdir.

Girdi Biçimi
Tek satırda: N, M ve K – Sırasıyla; Satır sayısı, Sütun sayısı ve Sevilmeyen Kare sayısı
Sonraki K satırda: Xi, Yi – Xi. satır, Yi. sütundaki sevilmeyen bir kare

Çıktı Biçimi
Tek bir sayı: Can'ın (1, 1) noktasından (N, M) noktasına gidebileceği farklı yolların sayısı

Limitler
1 ≤ N, M ≤ 10e5, 1 ≤ K ≤ 20

Daha ayrıntılı bilgi için altgörevler kısmına bakınız.

Girdi 1
3 3 1
2 2

Çıktı 1
2

Örnek 1 Açıklaması
B: Başlangıç
X: Yasak
H: Hedef
--------------
| B | → | ↓ |
--------------
| ↓ | X | ↓ |
--------------
| ↓ | → | H |
--------------
2 farklı şekilde 3. satır 3. sütundaki kareye ulaşabilir.

Girdi 2
4 4 4
2 2
2 3
3 2
3 3

Çıktı 2
2

Girdi 3
3 3 0

Çıktı 3
6

Altgörevler
Altgörev 1 (12 puan): 1 ≤ N, M ≤ 6, 1 ≤ K ≤ 20
Altgörev 2 (6 puan): 1 ≤ N, M ≤ 100, K = 0
Altgörev 3 (6 puan): 1 ≤ N, M ≤ 10e5, K = 0
Altgörev 4 (10 puan): 1 ≤ N, M ≤ 100, K = 1
Altgörev 5 (10 puan): 1 ≤ N, M ≤ 10e5, K = 1
Altgörev 6 (6 puan): 1 ≤ N, M ≤ 100, K = 2
Altgörev 7 (6 puan): 1 ≤ N, M ≤ 10e5, K = 2
Altgörev 8 (22 puan): 1 ≤ N, M ≤ 500, 1 ≤ K ≤ 20
Altgörev 9 (22 puan): 1 ≤ N, M ≤ 10e5, 1 ≤ K ≤ 20
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}