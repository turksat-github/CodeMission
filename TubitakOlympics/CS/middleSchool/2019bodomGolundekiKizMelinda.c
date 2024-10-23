/*
BODOM GÖLÜNDEKİ KIZ MELİNDA

Yıllar yıllar önce Bodom Gölü'ne yakın bir yerleşkeye kurulmuş köyde bir kız yaşarmış. Köyün sevimli kızı Melinda ve onun hayali arkadaşı Eddie'nin canları çok sıkılmış ve Bodom gölünün yanına kamp ateşi yakıp birlikte oyun oynamaya karar vermişler. Eddie sırayla Melinda'ya sayılar söylemiş ve şuana kadar söylediği sayılardan iki tanesini seçmesini istemiştir. Oyun kurallarına göre Melinda'nın o turu kazanabilmesi için seçtiği sayıların farkları ile toplamlarının çarpımı seçilebilecek tüm ikiler arasında maksimum olmalıydı. Tabii ki de Melinda çok zeki bir kız olduğu için tüm turları kazanmıştır. Size Eddie'nin söylediği sayılar sırası ile verilmektedir ve sizden istenilen her turda Melinda'nın hangi iki sayıyı seçtiğini yazdırmanız.

Girdi Biçimi
İlk satırda: Eddie'nin söylediği sayıların sayısını temsil eden N sayısı.
İkinci satırda: Eddie'nin söylemiş olduğu N adet tamsayı.

Çıktı Biçimi
Alt alta N satırda, i. satırda Melinda'nın i. turda seçmiş olduğu sayıları temsil eden ai ve bi sayıları.

NOT: Bu sayılar ise Melinda'nın o turda seçtiği sayıların
Eddie'nin söylediği sayılar arasında kaçıncı sırada söylenmiş olduğunu temsil etmektedir.
Dolayısıyla ai ≤ bi ≤ i olmalıdır. Ayrıca her turda sadece bir adet cevap olduğu garanti edilmektedir.

Limitler
1 ≤ N ≤ 10e5, 1 ≤ Eddie'nin söylediği sayılar ≤ 10e50

Girdi 1
4
5 2 7 3

Çıktı 1
1 1
1 2
2 3
2 3

Örnek 1 Açıklaması
İlk tur : Melinda'nın seçebileceği başka seçenek olmadağından 5 ve 5 seçer.
İkinci tur : 5 ve 2'yi seçer. (5 − 2) * (5 + 2) = 21
Üçüncü tur : 7 ve 2'yi seçer. (7 − 2) * (7 + 2) = 45
Dördüncü tur : 7 ve 2'yi seçer. (7 − 2) * (7 + 2) = 45
Eğer 5 ve 3'ü seçmiş olsaydı. (5 − 3) * (5 + 3) = 16 daha küçük bir değer olduğundan turu kaybetmiş olurdu.

Girdi 2
5
3 10 2 11 1

Çıktı 2
1 1
1 2
2 3
3 4
4 5

Altgörevler
Altgörev 1 (13 puan) : 1 ≤ N ≤ 100, 1 ≤ Eddie'nin söylediği sayılar ≤ 10e9
Altgörev 2 (17 puan) : 1 ≤ N ≤ 2000, 1 ≤ Eddie'nin söylediği sayılar ≤ 10e9
Altgörev 3 (42 puan) : 1 ≤ N ≤ 10e5, 1 ≤ Eddie'nin söylediği sayılar ≤ 10e9
Altgörev 4 (28 puan) : 1 ≤ N ≤ 10e5, 1 ≤ Eddie'nin söylediği sayılar ≤ 10e50
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}