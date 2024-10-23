/*
ZIPZIP'IN PARTİSİ

Sevimli tavşanımız Zıpzıp, monoton geçen hayatından çok sıkılmış ve bir parti düzenlemeye karar vermiştir. Bunun için orman halkına haber yaymış ve partiye hazır olan evinde beklemeye başlamıştır. Partiye gelen misafirler tek başlarına ve sırasıyla gelmektedirler. Her gelen misafirin belli bir yaşı vardır. Gelen misafirler parti bitene kadar partiyi terk etmezler. Çok boş bir tavşan olan Zıpzıp da arada sırada partisi hakkındaki istatistiklere göz atmak istemektedir. Bunu da sorgulamak istediği anda partide belli bir yaştan küçük eşit yaştaki kişilerin sayısını sorgulayarak yapmaktadır. Zıpzıp'ın sorguladığı her bir sayı değeri bir önceki sorgudaki sayı değerinden büyüktür. Sizden istenen sorgulandığı anda partideki belli bir yaştan küçük eşit yaştaki katılımcıların sayısını yazdırmanızdır.

Girdi Biçimi
Tek satırda sorgu sayısı olan Q
Ardından gelen Q satırda 2 çeşit komuttan bir tanesi:
1 x -> Partiye x yaşında birinin geldiğini gösterir.
2 y -> Partide bulunan kişiler arasından y yaşından küçük eşit yaşta kaç kişinin olduğunu sorgular.
NOT: Her bir y değeri bir önceki y değerinden büyüktür.

Çıktı Biçimi
Tüm 2 y tipindeki sorgular için o anda y yaşından küçük eşit yaştaki kişilerin sayısı.

Limitler
2 ≤ Q ≤ 10e6
1 ≤ Katılımcıların yaşları ≤ 10e9
1 ≤ Yaş sorgusu < Bir sonraki yaş sorgusu ≤ 10e9

Örnek Girdi
7
1 3
1 1
2 2
1 6
1 2
2 5
2 9

Örnek Çıktı
1
3
4

Örnek Girdinin Açıklaması
Partiye önce 3 yaşında biri ardından da 1 yaşında biri geliyor ve Zıpzıp 2 yaşından küçük eşit yaştaki
kişilerin sayısını sorguluyor (Cevabımız da 1). Ardından 6 ve 2 yaşlarında kişiler de geldikten sonra
5 yaşından küçük eşit yaştaki kişilerin sayısını sorguluyor (Cevabımız 3).
Son olarak 9 yaşından küçük eşit yaştaki kişilerin sayısını sorguluyor (Cevabımız 4).
Yaş sorguları olan 2, 5 ve 9 sayılarından her birinin bir öncekinden büyük olduğuna dikkat ediniz.

Altgörevler
Altgörev 1 (10 puan): 1 ≤ Q ≤ 10e3
Altgörev 2 (15 puan): 1 ≤ Q ≤ 5 * 10e5 1 ≤ Katılımcıların yaşları ≤ 10e2
Altgörev 3 (30 puan): Her bir katılımcının yaşı bir önce gelen katılımcının yaşından büyük eşittir
Altgörev 4 (45 puan): Herhangi bir kısıtlama bulunmamaktadır.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a;//a dizi uzunluğu
    scanf ("%d%*c", &a);
    int * b, * c;//diziler; b emir türü (gelenin yaşı mı yoksa sorgulama mı), c veri
    b = (int *) calloc (a, sizeof (int));
    c = (int *) calloc (a, sizeof (int));
    int d;
    for (d = 0; d < a; ++ d) {
        scanf ("%d %d%*c", (b + d), (c + d));
    }
    int e, f = 0;
    for (e = 0; e < a; ++ e) {
        if (* (b + e) == 1) {
            continue;
        }
        for (d = 0; d < e; ++ d) {
            if ((* (b + d) == 1) && (* (c + d) <= * (c + e))) {
                ++ f;
            }
        }
        printf ("%d\n", f);
        f = 0;
    }
    free (b);
    free (c);
    return EXIT_SUCCESS;
}