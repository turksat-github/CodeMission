/*
PARTİ

Zaman kısıtı: 1 sn
Memory kısıtı: 128 MB

Elmashan, N tane arkadaşına bir parti vermek ister. Ancak bu partinin yapılması için arkadaşları Elmashan'a M tane kural verir. Her bir kural şunu belirtir: Eğer A arkadaşını partiye davet edersen, B arkadaşını da davet etmen gerek (ve aynı zamanda B'yi davet edersen A'yi da davet etmen lazım). Elmashan'ın bütçesi kısıtlı olduğundan partisine davet edeceği sıfırdan büyük minimum arkadaş sayısını bulmak istemektedir. Elmashan, çok başarılı bir mimar olmasına karşın bilgisayarcı olmadığı için ona bu görevinde yardımcı olmanızı bekliyoruz.

Girdi:
Girdinin ilk satırında N ve M vardır. Bunlar sırasıyla Elmashan'ın arkadaş ve kural sayılarıdır. Takip eden M satırın her birinde davet edilmesi zorunlu iki arkadaş (A, B) ile verilmektedir.

Çıktı:
Elmashan'ın davet edeceği minimum arkadaş sayısını yazın.

Kısıtlar
● Davetliler 1, 2, ..., 𝑁 şeklinde etiketlenmiştir.
● 𝑁 ≤ 10e5
● 𝑀 ≤ 3 * 10e5
● 𝐴 ≠ 𝐵
● A B sırasız ikilisi en fazla bir defa görünür.

Alt Görevler
Alt Görev 1 [40 puan]
𝑀 ≤ 1000
Alt Görev 2 [60 puan]
Ek kısıt yoktur

Örnek Girdi 1
5 3
1 2
2 3
4 5

Örnek Çıktı 1
2

Örnek Girdi 2
10 7
2 5
1 4
3 6
1 2
6 7
8 9
9 10

Örnek Çıktı 2
3

Örnek Girdi 3
11 9
2 6
9 7
3 5
1 4
5 4
2 7
8 10
3 1
11 1

Örnek Çıktı 3
2

Örnek Girdi 4
18 13
1 18
2 17
3 16
4 15
5 14
6 13
7 12
8 11
9 10
1 2
3 4
5 6
7 8

Örnek Çıktı 4
2
*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char (* (* argv)), char (* (* envp))) {
    int a, b;//Kaç sayı ve kaç kural var?
    scanf ("%d %d%*c", &a, &b);//Kaç sayı ve kaç kural olduğunu al
    int * c, ** d;//Sayıları test alanı, kurallar
    c = (int *) calloc (a, sizeof (int));//Kişilerin olup olmadığını tutacak
    d = (int **) calloc (b, sizeof (int *));//Kuralları tutan double pointer to int
    int e, f, g, h;
    for (e = 0; e < b; ++ e) {//Kurallar alınır
        *(d + e) = (int *) calloc (2, sizeof (int));
        scanf ("%d %d%*c", &*(*(d + e) + 0), &*(*(d + e) + 1));//Kuralları alıyorum
        -- *(*(d + e) + 0);//Kurallar 1'den başladığı için 0'dan başlara dönüştürmek için
        -- *(*(d + e) + 1);//index 0 kullanacağım için index 1 verilenleri 1 eksiltiyorum
    }
    h = a;//davet edilebilecek en büyük sayı kişi sayısıdır
    for (e = 0; e < a; ++ e) {//Tek tek bütün kişileri deniyorum
        *(c + e) = 1;//Denediğim kişiyi işaretliyorum. 0: Gelmiyor, 1: Geliyor
        for (f = 0; f < b; ++ f) {//Bütün kuralları deniyorum
            if ((*(c + *(*(d + f) + 0)) + *(c + *(*(d + f) + 1))) == 1) {//Kuraldaki ikiliden biri boş diğeri dolu ise
                *(c + *(*(d + f) + 0)) = 1;//İlkini dolu olarak işaretle
                *(c + *(*(d + f) + 1)) = 1;//İkinciyi dolu olarak işaretle
                f = 0;//Kurallara tekrar baştan bakmamı sağla
            }
        }
        for (f = 0, g = 0; f < a; ++ f) {//Kaç kişi davetli olarak işaretlenmiş sayalım
            if (*(c + f) == 1) {//Davetli olarak işaretlenmişse
                ++ g;//Davetli kişi sayısını 1 artır
            }
        }
        if (g < h) {//Davet edilebilecek en az kişi sayımız, şimdi bulduğumuzdan çoksa
            h = g;//Davet edilecek kişi sayısını güncelle
        }
        for (f = 0; f < a; ++ f) {//tüm kişileri davetsiz olarak işaretle
            *(c + f) = 0;
        }
    }
    printf ("%d", h);//En az olan sonuç kaçsa ekrana yazılır
    free (c);
    for (e = 0; e < b; ++ e) {
        free (*(d + e));
    }
    free (d);
    return EXIT_SUCCESS;
}
