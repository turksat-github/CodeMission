/*
ARALIKTAKİ ÖZEL SAYI

Size N sayıdan oluşan bir sayı dizisi verilecektir. Ama bu sıradan bir sayı dizisi değildir. Bazı indisteki (sıradaki) sayılar özeldir. Sizin hedefiniz öyle bir alt dizi seçmektir ki alt dizide tam olarak 1 tane özel sayı geçsin ve alt dizideki sayıların toplamı maksimum olsun. Bu özelliği sağlayan ve elemanları toplamı maksimum olan alt dizinin elemanları toplamını ekrana yazdırınız.
Not: Bir dizinin en sağından ve en solundan ardışık elemanlar silerek elde edilebilen dizilere denilebilir.
Mesela |1, 2, 3, 4| dizisinin alt dizileri |1|, |1, 2|, |1, 2, 3|, |1, 2, 3, 4|, |2|, |2, 3|, |2, 3, 4|, |3|, |3, 4|, |4|

Girdi Biçimi
N - Dizinin eleman sayısı
A1, A2, A3, ... Ai, ..., An (N elemanlı dizi)
S1, S2, S3, ... Si, ..., Sn (Si, i. sayının özel olup olmadığını belirtir)
Si = 1 => Ai özeldir. Si = 0 => Ai özel değildir.

Çıktı Biçimi
Tek bir tam sayı yazdırmanız gerekiyor. Uygun alt dizinin elemanları toplamını yazdırınız.

Örnek Girdiler

Girdi 1
5
5 5 -12 2 2
0 0 0 1 0

Çıktı 1
4

Çıktı 1 Açıklaması
4. sırada bulunan sayı özel bir sayıdır ve diğerleri 0 ile belirtildiğinden özel sayı değildir. Bu yüzden alt dizimiz 4. sayıyı (2 sayısını) içermelidir. 2'yi içeren alt dizilerin toplamları maksimum olan alt dizi |2, 2| −> (2 + 2) = 4.

Girdi 2
5
5 5 -12 2 2
0 0 1 0 0

Çıktı 2
2

Çıktı 2 Açıklaması
3. sırada bulunan sayı (-12) özel bir sayıdır ve diğerleri 0 ile belirtildiğinden özel sayı değildir. Bu yüzden alt dizimiz 3. sayıyı (-12 sayısını) içermelidir. -12 yi içeren alt dizilerin toplamları maksimum olan alt dizi |5, 5, −12, 2, 2| −> (5 + 5 − 12 + 2 + 2) = 2.

Girdi 3
5
1 2 3 4 5
0 1 0 1 0

Çıktı 3
12

Çıktı 3 Açıklaması
2 ve 4 ikisi de özel olduğu için, alt dizimizde sadece biri yer alabilir |3, 4, 5| −> (3 + 4 + 5) = 12.

Limitler
1 ≤ N ≤ 10e5
−10e4 ≤ Ai ≤ 10e4
0 ≤ Bi ≤ 1
Bütün girdilerde en az bir tane özel sayı bulunacaktır.

Altgörev 1 (27 puan): 1 ≤ N ≤ 100
Altgörev 2 (18 puan): 1 ≤ N ≤ 10e5, Bi = 1 bu altgörevde bütün sayılar özeldir.
Altgörev 3 (18 puan): 1 ≤ N ≤ 10e5, 0 ≤ Ai ≤ 10e4 bu altgörevde negatif sayı yoktur.
Altgörev 4 (37 puan): Herhangi bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}