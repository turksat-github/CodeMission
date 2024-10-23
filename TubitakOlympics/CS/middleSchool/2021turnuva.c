/*
TURNUVA

Dünya şampiyonluğu yolunda emin adımlarla ilerleyen Büyükusta Vahap Şanal'ın yolunda artık sadece Carlsen kalmıştır. Onu da yenip dünya şampiyonu olmak için kimsenin bilmediği gizli bir taktik geliştirmiştir. Vahap'ın oynayabileceği N adet hamle vardır ve Vahap bunlara birer puan vermiştir. Vahap bu N hamleden birini oynayacak, ardından da Carlsen aynı N hamleden birini oynayacaktır. Vahap'ın taktiği şöyledir:
Eğer Vahap ve Carlsen'in oynadığı hamlelerin puanlarının toplamı K sayısını bölüyorsa Vahap öne geçecek ve maçı kazanacaktır. Vahap öyle bir hamle yapmak istiyor ki kazanma ihtimali en fazla olsun. Bunun için sizden yardım istiyor. Carlsen ile yapılacak olan T adet maç için bu soruyu cevaplamanız beklenmektedir.

Girdi Biçimi
İlk satırda maç sayısı olan T değeri
Her maç için ilk satırda N ve K değerleri
Sonraki satırda artan sırada N adet sayı

Çıktı Biçimi
Her maç için Vahap'ın oynaması gereken hamlenin puanı
Eğer kazanma ihtimali en fazla olan birden fazla hamle varsa puanı en küçük olanı yazdırınız.

Örnek Girdiler

Girdi 1
1
7 70
1 2 4 6 7 8 11

Çıktı 1
1

Örnek 1 için Açıklama
Eğer Vahap 1 hamlesini oynarsa kazandığı 3 durum var:
1 (1 + 1 = 2, 70'i böler)
4 (1 + 4 = 5, 70'i böler)
6 (1 + 6 = 7, 70'i böler)
Eğer Vahap 2 hamlesini oynarsa kazandığı 1 durum var:
8 (2 + 8 = 10, 70'i böler)
Eğer Vahap 4 hamlesini oynarsa kazandığı 2 durum var:
1 (4 + 1 = 5, 70'i böler)
6 (4 + 6 = 10, 70'i böler)
Eğer Vahap 6 hamlesini oynarsa kazandığı 3 durum var:
1 (6 + 1 = 7, 70'i böler)
4 (6 + 4 = 10, 70'i böler)
8 (6 + 8 = 14, 70'i böler)
Eğer Vahap 7 hamlesini oynarsa kazandığı 1 durum var:
7 (7 + 7 = 14, 70'i böler)
Eğer Vahap 8 hamlesini oynarsa kazandığı 2 durum var:
2 (8 + 2 = 10, 70'i böler)
6 (8 + 6 = 14, 70'i böler)
Eğer Vahap 11 hamlesini oynarsa kazandığı 0 durum var.
Kazanma ihtimali en yüksek olan hamleler 1 ve 6, bu sebeple cevap 1.

Girdi 2
1
9 10
2 3 3 3 3 5 5 5 5

Çıktı 2
2

Örnek 2 için Açıklama
Eğer Vahap 2 hamlesini oynarsa kazandığı 4 durum var:
3 (4 tane var) (2 + 3 = 5, 10'u böler)
Eğer Vahap 3 hamlesini oynarsa kazandığı 1 durum var:
2 (3 + 2 = 5, 10'u böler)
Eğer Vahap 5 hamlesini oynarsa kazandığı 4 durum var:
5 (4 tane var) (5 + 5 = 10, 10'u böler)
Kazanma ihtimali en yüksek olan hamleler 2 ve 5, bu sebeple cevap 2.

Limitler
1 ≤ N ≤ 5 * 10e4
1 ≤ K ≤ 10e7
1 ≤ Hamle Puanları ≤ 10e9

Altgörevler dahil her maç için N sayılarının toplamı N'nin maksimum değerini geçmeyecektir.
Altgörevler dahil her maç için K sayılarının toplamı K'nin maksimum değerini geçmeyecektir.
Altgörev 1 (15 puan): N ≤ 10e3
Altgörev 2 (35 puan): K ≤ 10e4
Altgörev 3 (25 puan): Her hamlenin puanı farklı.
Altgörev 4 (25 puan): Ek kısıt yok
Altgörev 4 (37 puan): Herhangi bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}