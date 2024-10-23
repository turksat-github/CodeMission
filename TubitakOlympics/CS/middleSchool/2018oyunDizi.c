/*
OYUN DİZİ

Ayşe ve Bora'nın elinde N uzunluğunda iki dizi vardır. Bu iki dizi üzerinde aşağıda kuralları verilen oyunu oynamaktadırlar:
Ayşe'nin dizisi A ve Bora'nın dizisi B olsun. 1 den N'ye kadar her i için
eğer A[i] > B[i] ise Ayşe A[i] - B[i]; B[i] > A[i] ise Bora B[i] - A[i] kadar puan almaktadır.
Eğer A[i] = B[i] ise bu durumda 1'den i'ye kadar az puan alan kişi 1 puan almaktadır
(İkisinin de i ye kadar eşit puanlı olması durumunda 1 puanı Ayşe alacaktır).
Verilen iki dizi için kimin kazandığını bulan programı yazın.

Girdi Formatı
İlk satırda Ayşe ve Bora'nın dizilerinin uzunluğu olan N tamsayısı (1 ≤ N ≤ 10e5).
Sonraki N satır için i. satır sırasıyla A[i] ve B[i] den oluşacak iki tam sayı içerecektir (0 ≤ A[i], B[i] ≤ 10e9).

Çıktı Formatı
Tek bir satır halinde oyunu yukarıdaki kurallara göre Ayşe kazandıysa "ayse", Bora kazandıysa "bora",
eğer ikisi de eşit puan topladıysa "berabere" yazdırınız.

Örnek Girdi:
5
1 2
1 3
10 4
9 8
5 12

Örnek Çıktı:
bora

Açıklama:
1. hamlede Ayşe'nin 1, Bora'nın 2'si vardır. 2 > 1 olduğu için Bora 2 - 1 = 1 puan alır.
2. hamlede Ayşe'nin 1, Bora'nın 3'ü vardır. 3 > 1 olduğu için Bora 3 - 1 = 2 puan alır.
3. hamlede Ayşe'nin 10, Bora'nın 4'ü vardır. 10 > 4 olduğu için Ayşe 10 - 4 = 6 puan alır.
4. hamlede Ayşe'nin 9, Bora'nın 8'i vardır. 9 > 8 olduğu için Ayşe 9 - 8 = 1 puan alır.
5. hamlede Ayşe'nin 5, Bora'nın 12'si vardır. 12 > 5 olduğu için Bora 12 - 5 = 7 puan alır.
Sonuç olarak Ayşe 6 + 1 = 7 ve Bora 1 + 2 + 7 = 10 puan topladığından Bora kazanır.

Örnek Girdi:
3
4 2
1 1
1 2

Örnek Çıktı:
berabere

Açıklama:
1. hamlede Ayşe'nin 4, Bora'nın 2'si vardır. 4 > 2 olduğu için Ayşe 4 - 2 = 2 puan alır.
2. hamlede Ayşe'nin 1, Bora'nın 1'i vardır.
İkisi de eşit olduğu için ve şuana kadar az puan alan Bora olduğu için, Bora 1 puan alır.
3. hamlede Ayşe'nin 1, Bora'nın 2'si vardır. 2 > 1 olduğu için Bora 2 - 1 = 1 puan alır.
Sonuç olarak Ayşe 2 puan ve Bora da 2 puan topladığından oyun berabere bitmiştir.

Puanlandırma
Alt Görev 1 (17 Puan) : N = 1, 1 ≤ A[i], B[i] ≤ 10
Alt Görev 2 (32 Puan) : 1 ≤ N ≤ 10e3, 1 ≤ A[i], B[i] ≤ 10e5
Alt Görev 3 (51 Puan) : 1 ≤ N ≤ 10e5, 1 ≤ A[i], B[i] ≤ 10e9
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a;//a dizi uzunluğu
    scanf ("%d%*c", &a);
    int * b, * c;//diziler; b ayşe ve c ise bora
    b = (int *) calloc (a, sizeof (int));
    c = (int *) calloc (a, sizeof (int));
    int d;
    for (d = 0; d < a; ++ d) {
        scanf ("%d %d%*c", (b + d), (c + d));
    }
    int e = 0, f = 0;//Ayşe (e) ile Bora'nın (f) puanları
    for (d = 0; d < a; ++ d) {
        if (*(b + d) > *(c + d)) {
            e += *(b + d) - *(c + d);
        }
        else if (*(c + d) > *(b + d)) {
            f += *(c + d) - *(b + d);
        }
        else {
            if (e < f) {
                ++ e;
            }
            else if (f < e) {
                ++ f;
            }
            else {
                ++ e;
            }
        }
    }
    if (e > f) {
        printf ("ayse");
    }
    else if (f > e) {
        printf ("bora");
    }
    else {
        printf ("berabere");
    }
    free (b);
    free (c);
    return EXIT_SUCCESS;
}