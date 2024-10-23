/*
GRUPLAMA

Size koordinat düzleminde N tane nokta veriliyor. Her nokta K gruptan birine ait. Farklı gruba ait olan noktaların birbirlerine olabildiğince uzak, aynı gruba ait olanların ise birbirlerine olabildiğince yakın olmasını istiyoruz. Bu yüzden şöyle bir puanlandırma sistemi tanımlanıyor:
• Farklı gruba ait her ikilinin birbirlerine olan uzaklığı puan olarak ekleniyor.
• Aynı gruba ait her ikilinin birbirlerine olan uzaklığı puandan çıkarılıyor.

(x1, y1) ve (x2, y2) noktalarının arasındaki uzaklık |x1 − x2| + |y1 − y2| olarak tanımlanıyor. Tam olarak 1 kez, noktalardan birini seçip o noktanın grubunu değiştirebiliyoruz (aynı gruba atayabiliriz). Sizden istenen, öyle bir noktanın grubunu değiştirin ki olabilecek en yüksek puanı elde edelim.

Girdi Biçimi
İlk satırda 2 tam sayı: N ve K, nokta sayısı ve grup sayısı
Takip eden N satırda 3 tam sayı: xi, yi ve ti, ti grubuna ait (xi, yi) konumda bir nokta.

Çıktı Biçimi
Tek bir sayı: Olabilecek en yüksek puan.

Limitler
1 ≤ N ≤ 10e5
1 ≤ K ≤ 10
0 ≤ xi, yi ≤ 10e9

Girdi 1
3 2
1 1 1
5 6 1
5 5 2

Çıktı 1
16

Örnek 1 Açıklaması
Başlangıçta 1 ve 2 aynı gruptadır. Aralarındaki uzaklık d(1, 2) = |1 - 5| + |1 - 6| = 9'dur. Benzer şekilde d(1, 3) = 8 ve d(2, 3) = 1. Bu durumda puan:
• Farklı grupta olanlar: (1, 3) (2, 3), toplam uzaklık: 8 + 1 = 9
• Aynı grupta olanlar: (1, 2), toplam uzaklık: 9
• Puan: 9 - 9 = 0

Eğer 2. noktanın grubunu 2. grup olarak değiştirirsek:
• Farklı grupta olanlar: (1, 3) (1, 2), toplam uzaklık: 8 + 9 = 17
• Aynı grupta olanlar: (2, 3), toplam uzaklık: 1
• Puan: 17 - 1 = 16
Olabilecek en yüksek puanı elde ederiz.

Altgörevler
Altgörev 1 (4 puan): N ≤ 1000, xi ≤ 10e3, K = 1, yi = 0
Altgörev 2 (9 puan): N ≤ 1000, K = 1
Altgörev 3 (22 puan): N ≤ 10e5, K = 1, yi = 0
Altgörev 4 (5 puan): N ≤ 10e5, K = 1
Altgörev 5 (14 puan): N ≤ 1000, K = 2
Altgörev 6 (26 puan): N ≤ 10e5, K = 2
Altgörev 7 (12 puan): N ≤ 10e5, K ≤ 10, yi = 0
Altgörev 8 (8 puan): N ≤ 10e5, K ≤ 10
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}