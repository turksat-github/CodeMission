/*
MERAKLI BAHADIR

Eski olimpiyatçılardan Bahadır'ın elinde N uzunluğunda bir dizi vardır. Bahadır bu dizide bazı aralıklar seçmiştir.
Her bir aralık için, aralıktaki sayıların çarpımının 0 olup olmadığını merak etmektedir. Bahadır'a yardımcı olabilir misin?

Girdi Formatı
İlk satırda N (1 <= N <= 10e5) Tam sayı dizisinin uzunluğu.
İkinci satırda N uzunluğunda tam sayı dizisi. A[i] (0 <= A[i] <= 10e5) Dizideki değerler.
Üçüncü satırda Q (1 <= Q <= 10e5) sorgulanacak aralıkların sayısı.
Takip eden Q satırın her birinde L ve R değerleri (1 <= L <= R <= N).
Sorgulanacak aralığın başı (L) ve sonu (R).
Not: Sorgularda indisler 1'den başlayacak şekilde ayarlanmıştır.

Çıktı Formatı
Q satırda her bir satır için o sorguda verilen aralığın çarpımı 0'a eşitse "Yes" değilse "No" yazdırılacak.
(Parantezler/tırnak olmadan yalın şekilde)

Örnek Girdi 1
10
0 5 1 0 9 2 6 3 0 7
5
1 3
2 3
5 8
1 10
2 4

Örnek Çıktı 1
Yes
No
No
Yes
Yes

Örnek Girdi 2
5
1 0 1 0 1
5
1 2
1 1
3 3
1 5
3 5

Örnek Çıktı 2
Yes
No
No
Yes
Yes

Alt Görev 1 - 12 Puan : N <= 10, Q <= 10
Alt Görev 2 - 24 Puan : N <= 100, Q <= 100
Alt Görev 3 - 13 Puan : N <= 1000, Q <= 1000
Alt Görev 4 - 51 Puan : Hiçbir ek kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a;//dizi uzunluğu
    scanf ("%d%*c", &a);
    int *b;//dizideki sayılar
    b = (int *) calloc (a, sizeof (int));
    int c = 0;
    char d;
    do {
        scanf ("%d%c", (b + c), &d);
        ++ c;
    } while (d != '\n');
    int e;
    scanf ("%d%*c", &e);
    int **f;
    f = (int **) calloc (e, sizeof (int *));
    for (c = 0; c < e; ++ c) {
        *(f + c) = (int *) calloc (2, sizeof (int));
    }
    for (c = 0; c < e; ++ c) {
        scanf ("%d %d%*c", (*(f + c) + 0), (*(f + c) + 1));
    }
    int g;
    for (c = 0; c < e; ++ c) {
        for (g = *(*(f + c) + 0) - 1; g <= *(*(f + c) + 1) - 1; ++ g) {
            if (*(b + g) == 0) {
                printf ("yes\n");
                g = -1;
                break;
            }
        }
        if (g != -1) {
            printf ("no\n");
        }
    }
    for (c = 0; c < e; ++ c) {
        free (*(f + c));
    }
    free (f);
    free (b);
    return EXIT_SUCCESS;
}