/*
FRP

Onur (üniversiteden) yeni mezun olmuş bir bilgisayar olimpiyatçıdır. Üniversitede hayatı boyunca FRP ve Kutu oyunlarına ilgi duymuş ve bunlarla vakit geçirip durmuştur. Burak ise Onur'un en yakın arkadaşıdır ve mezun olmasına hala 1 (bir) yıl vardır. Burak ise üniversite hayatını olimpiyat çalışmaya devam ederek geçirmiştir. Yıllar sonra Onur ve Burak buluşurlar ve Onur Burak'ın FRP oynamayı denemesi için elinden geleni yapar, Burak ise bunu tek şartla kabul eder. Onur'un Burak'ın yazdığı soruyu çözmesi gerekmektedir. Burak Onur'a şöyle bir soru hazırlamıştır:
Sadece F, R ve P harflerini içeren bir string verildiğinde;
eşit sayıda F, R ve P içeren substringlerin sayını yazdır.
Onur, tabii ki çözemediğinden değil, üşengeçliğinden bu soruyu çözmek için sizin yardımınızı istiyor.

Örnek
FPRPFR
4
FPR---
-RPF--
---PFR
FPRPRF

Girdi
Girdinin ilk ve tek satırında uzunluğu N (1 ≤ N ≤ 10e5) olan bir string yer almaktadır.

Çıktı
Çıktının ilk ve tek satırına verilen stringte eşit sayıda F, R ve P harflerni içeren
substringlerin sayısını yazdırınız.

Örnek Girdi
FPRPFR

Örnek Çıktı
4

Girdilerin %25'inde N ≤ 1000,
Girdilerin %100'ünde N ≤ 10e5 olacaktır.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char * (* argv), char * (* envp)) {
    //Tek satırda girdileri alır.
    char *g;
    g = (char *) calloc (2147483648, sizeof (char));
    scanf ("%2147483647[^\n]%*c", g);
    int a, b = 0, c, d, f, r, p;//b sonuç, f F sayısı, r R sayısı, p P sayısı
    for (a = 0; a <= (strlen (g) - 3); ++ a) {//başlangıç sıra numarası 0 ile tümden 3 eksik olasıya kadar
        for (c = a + 3; c <= (strlen (g)); ++ c) {
            f = 0;
            r = 0;
            p = 0;
            for (d = a; d < c; ++ d) {
                if (* (g + d) == 'F') {
                    ++ f;
                }
                else if (* (g + d) == 'R') {
                    ++ r;
                }
                else if (* (g + d) == 'P') {
                    ++ p;
                }
            }
            if (f == r && r == p) {
                ++ b;
            }
        }
    }
    printf ("%d\n", b);
    free (g);
    return EXIT_SUCCESS;
}
