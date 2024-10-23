/*
MÜZİK DELİSİ

Muko bir müzik delisidir. N gün boyunca her gün bir şarkı dinlemektedir. Tüm müziklerini dinlediği uygulama olan MukoMüzik, böyle bir müzik delisine yeni yıla girmeden önce hoşuna gidecek bilgiler sunmak istiyor. Öyle ki Muko için tüm ardışık 1 günlük, 2 günlük, 3 günlük, ... M günlük aralıklar içinde en çok dinlediği şarkıyı kaç defa dinlediğini bulmak istiyorlar. Bir MukoMüzik çalışanı olarak değerli üyeniz Muko için belirtilen şekilde en çok dinlediği şarkıyı kaç defa dinlediğini yazdırın.
Örneğin dinlenilen şarkıların numaraları 5 4 2 4 4 ve M = 2 olsun.
Bu durumda biz uzunluğu M'den küçük eşit olan tüm aralıklara bakıyoruz:
Ardışık uzunluğu 1 olan altdiziler için: {5}, {4}, {2}, {4}, {4} şeklinde ayırabiliriz.
Burada her küme içinde en çok tekrar eden eleman 1 defa tekrar etmektedir.
Ardışık uzunluğu 2 olan altdiziler için: {5, 4}, {4, 2}, {2, 4}, {4, 4} şeklinde ayırabiliriz.
Burada ise en çok tekrar eden sayı son kümedeki 4'tür ve 2 defa tekrar etmiştir.
Bundan dolayı böyle bir örnek için cevap 2 dir.

Girdi Biçimi
İlk satırda: Sırasıyle N M
İkinci satırda: Sırasıyla N tane tamsayıdan oluşan A[i], i. gün için dinlediği şarkının numarası.

Çıktı Biçimi
Tek bir sayı: Soruda istenildiği şekilde Muko tarafından en çok dinlenen şarkının kaç kez dinlenildiği.

Limitler
1 ≤ M ≤ N ≤ 10e5, 1 ≤ A[i] ≤ 10e9

Girdi 1
6 4
1 3 5 5 1 5

Çıktı 1
3

Girdi 2
5 4
1 2 2 3 1

Çıktı 2
2

Altgörevler
Altgörev 1 (9 puan): 1 ≤ M ≤ N ≤ 10e2, 1 ≤ A[i] ≤ 10e5
Altgörev 2 (14 puan): 1 ≤ M ≤ N ≤ 2 * 10e3, 1 ≤ A[i] ≤ 10e5
Altgörev 3 (18 puan): 1 ≤ M ≤ N ≤ 2 * 10e3, 1 ≤ A[i] ≤ 10e9
Altgörev 4 (39 puan): 1 ≤ M ≤ N ≤ 10e5, 1 ≤ A[i] ≤ 10e5
Altgörev 5 (20 puan): Normal sınırlar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a, b, j = 0;
    scanf ("%d %d%*c", &a, &b);
    int *c;
    c = (int *) calloc (a, sizeof (int));
    char *d;
    d = (char *) calloc (2147483648, sizeof (char));
    scanf ("%2147483647[^\n]%*c", d);
    char *e = strtok (d, " ");
    while (e != NULL) {
        * (c + j) = (int) strtol (e, (char **) NULL, 10);
        //c [e] = atoi (e);
        ++ j;
        e = strtok (NULL, " ");
    }
    free (e);
    free (d);
    int f, g, h = 0, i = 0;
    for (f = 0; f < (a - b + 1); ++ f) {
        for (g = f; g < f + b; ++ g) {
            if (* (c + f) == * (c + g)) {
                ++ i;
            }
        }
        if (i > h) {
            h = i;
        }
        i = 0;
    }
    printf ("%d\n", h);
    return EXIT_SUCCESS;
}