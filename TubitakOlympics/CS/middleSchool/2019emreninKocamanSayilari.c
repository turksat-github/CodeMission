/*
EMRE'NİN KOCAMAN SAYILARI

Emre oldu olası sayılara derin bir ilgi beslemistir. Annesi Emre'nin doğum gününde ona n adet sayı almıştır. Emre aylarca bu sayılarla oynadıktan sonra artık canı sıkılmaya başlamıştır. Emre sayıları sevdiği gibi kocaman sayıları da sevmektedir. Bir gün elindeki n sayıyı birleştirebileceğini fark etmiştir. Bu n adet sayıyı uç uca ekleyerek yeni bir sayı oluşturmaya karar vermiştir. Bu yeni sayının da olabildiğince büyük olmasını istemektedir.
Mesela elindeki sayılar [10, 71, 5] olsun (n = 3). Emre bu sayıları 71, 5, 10 sırasıyla birlestirirse yeni sayi 71510 olur. Eğer 10, 5 ve 71 sırasıyla birleştirirse yeni sayı 10571 olur. 71510 oluşturabileceği en büyük sayıdır dolayısıyla bu sayıyı oluşturmalıdır.
Size Emre'nin kaç tane sayısının olduğu ve bu sayılar verilecek. Sonra sizden Emre'nin uç uca ekleyerek oluşturacağı en büyük sayıyı bulmanız istenmektedir. Her sayıyı tam olarak bir kere kullanmanız gerekmektedir.

Girdi Biçimi
İlk satırda: Emre'nin sayılarının sayısını temsil eden n sayısı.
İkinci satırda: Emre'nin sahip olduğu n adet pozitif tamsayı.

Çıktı Biçimi
Tek satırda Emre'nin oluşturacağı sayıyı yazdırın.

Limitler
1 ≤ n ≤ 10e5, 1 ≤ Emre'nin sayıları ≤ 10e9

Girdi 1
4
5 21 10

Çıktı 1
52110

Örnek 1 Açıklaması
Emre sırasıyla 5, 21 ve 10 sayılarını uç uca ekler.

Girdi 2
6
1 2 3 41 5 9

Çıktı 2
9541321

Altgörevler
Altgörev 1 (30 puan) : 1 ≤ n ≤ 1000 , 1 ≤ Emre'nin sayıları ≤ 9
Altgörev 2 (40 puan) : 1 ≤ N ≤ 1000 , 1 ≤ Emre'nin sayıları ≤ 10e9
Altgörev 3 (30 puan) : 1 ≤ N ≤ 10e5 , 1 ≤ Emre'nin sayıları ≤ 10e9
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char (* (* argv)), char (* (* envp))) {
    int a;//Kaç sayı var?
    scanf ("%d%*c", &a);//Kaç sayı olduğunu al
    int *b, *c, *d, **e;
    b = (int *) calloc (a, sizeof (int));//Sayıların listesi
    c = (int *) calloc (a, sizeof (int));//Sayıların sıra numaları
    d = (int *) calloc (a, sizeof (int));//Basamak sayıları
    e = (int **) calloc (a, sizeof (int *));//Rakamların listesini içeren iki boyutlu dizinin satır numarası ile...
    int f, g, h, i, j;
    for (f = 0; f < a; ++ f) {
        scanf ("%d%*c", (b + f));//Sayılar alınır
        * (c + f) = f;//Sıradan sıra numaraları verilir
        for (g = 1, h = 0; * (b + f) / g > 0; g *= 10, ++ h) {
        }//h: basamak sayısı ve g: 10'un basamak sayısı kadar üstü alınmış hali
        * (d + f) = h;//Basamak sayıları verilir
        * (e + f) = (int *) calloc (h, sizeof (int));//İki boyutlu dizinin sütün kısmı oluşturulur
        for (i = 0, g /= 10; i < h; ++ i, g /= 10) {
            * (* (e + f) + i) = (* (b + f) / g) % 10;//iki boyutlu dizi sayılarının rakamları ile doldurulur
        }
    }
    for (f = 0; f < a - 1; ++ f) {
        for (g = f + 1; g < a; ++ g) {
            if (* (d + f) < * (d + g)) {
                h = * (d + g);
            }
            else {
                h = * (d + f);
            }
            for (i = 0, j = 0; i < h; ++ i, ++ j) {
            }
        }
    }
    for (f = 0; f < a; ++ f) {
        printf ("%d", * (b + * (c + f)));//gerçek sayılar, belirlenen sıra numaralarına göre ekrana yazdırılır
    }
    free (b);
    free (c);
    for (f = 0; f < a; ++ f) {
        free (d + f);
    }
    free (d);
    return EXIT_SUCCESS;
}
