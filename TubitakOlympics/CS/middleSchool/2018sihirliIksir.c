/*
SİHİRLİ İKSİR

Ahmet Bey yeni bir bahçe oluşturmaktadır. Ahmet Bey'in bahçesinde şu an N adet ağaç bulunmaktadır. Ayrıca Ahmet Bey'in elinde bu ağaçları uzatmaya yardımcı olan K damlalık sihirli iksir bulunmaktadır. Sihirli iksirin bir damlası Ahmet Bey'in seçtiği bir ağacın boyunu 1 birim uzatmaktadır. Kuşlar ağaçlara rahatça yuva yapabilsin diye Ahmet Bey bahçesindeki en kısa ağacın boyunun bile çok uzun olmasını istemektedir. Bu yüzden Ahmet Bey elindeki sihirli iksiri ağaçlara en kısa ağacı olabildiğince uzun yapacak şekilde dağıtmak istemektedir. Ahmet Bey, aynı ağaca birden fazla kez sihirli iksir damlatabilirken bazı ağaçlara hiç damlatmayabilir de. Sizin çok iyi bir programcı olduğunuzu bilen Ahmet Bey size elindeki K damlalık iksiri kullanarak en kısa ağacı en fazla kaç birim uzunluğunda yapabileceğini soruyor.
Tek satırda bu istenen uzunluğu yazdırınız.

Girdi Biçimi:
İlk satırda iki tam sayı: N ve K, bu sayılar sırasıyla Ahmet Bey'in bahçesindeki ağaç sayısı ve sihirli iksirin miktarıdır.
Sıradaki satırda N adet tam sayı, bu sayılar Ahmet Bey'in bahçesindeki ağaçların başlangıç durumundaki uzunluklarını temsil etmektedir.

Bu uzunluklar 0 ile 10.000 arasındaki tam sayılardan oluşacaktır.

Çıktı Biçimi:
K damla iksiri en kısa ağacı olabildiğince uzun yapacak şekilde kullanılıra bu en kısa ağacın uzunluğu ne olur.

Sınırlar:
1 ≤ N ≤ 10e5
0 ≤ K ≤ 1e9

Alt Görev 1 (10 puan) : Bütün ağaçların ilk uzunlukları 0 olarak verilecektir, ayrıca 1 ≤ N ≤ 1.000 şartı sağlanır.
Alt Görev 2 (20 puan) : N = 2 şartı sağlanır.
Alt Görev 3 (40 puan) : 1 ≤ N ≤ 10e3 şartı sağlanır.
Alt Görev 4 (30 puan) : 1 ≤ N ≤ 10e5 şartı sağlanır.

Örnek Girdi 1:
2 2
1 0

Örnek Çıktı 1:
1

Açıklama
Ahmet Bey, 0 uzunluğundaki ağaca 1 damla damlatır. Sonra 1 uzunluğunda 2 ağacı olmuş olur.
Kalan damlayı da bu 2 ağaçtan birine damlatır.
Bunun sonunda da 2 uzunluğunda ve 1 uzunluğunda birer ağacı olur.
Bu ağaçlardan kısa olanın uzunluğu 1 olduğu için cevap 1 olur.

Örnek Girdi 2:
4 7
1 1 3 1

Örnek Çıktı 1:
3

Açıklama
Ahmet Bey, 1 uzunluğundaki 3 ağacın her birine 2'şer damla damlatır.
6 damlayı kullanmış olur ve tüm ağaçlar 3 uzunluğundadır. Son damlayı da bu ağaçlardan birine damlatır.
Son durumda ağaçlar [3, 3, 3, 4] uzunluklarında olur.
Bu ağaçlardan en kısası 3 uzunluğundadır, bu yüzden cevap 3 olur.

Örnek Girdi:
5 10
0 0 0 0 0

Örnek Çıktı:
2

Açıklama
Ahmet Bey, 0 uzunluğundaki 5 ağacın her birine 2'şer damla damlatır.
10 damlayı da kullanmış olur ve son durumda tüm ağaçlar 2 uzunluğundadır. Bu yüzden cevap 2 olur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a, b;//a ağaç sayısı, b damlalık
    scanf ("%d %d%*c", &a, &b);
    int *c;//ağaçların uzunlukları
    c = (int *) calloc (a, sizeof (int));
    int e;
    e = 0;

    /*
    char d;
    //Tek satırda girdileri alır.
    //başta ve sonda boşluk yok ve sayılar arasında bir boşluk var.
    do {
        scanf ("%d%c", &c [e], &d);
        ++ e;
    } while (d != '\n');
    */

    //Tek satırda girdileri alır.
    //boşluklardan ayırıp tek tek dönüştürür.
    char *g;
    g = (char *) calloc (2000001, sizeof (char));
    scanf ("%200000[^\n]%*c", g);
    char *h = strtok (g, " ");
    while (h != NULL) {
        c [e] = (int) strtol (h, (char **) NULL, 10);
        //c [e] = atoi (h);
        ++ e;
        h = strtok (NULL, " ");
    }
    free (g);
    free (h);

    int f;
    while (b > 0) {
        f = 0;
        for (e = 1; e < a; ++ e) {
            if (* (c + e - 1) > * (c + e)) {
                f = e;
            }
        }
        * (c + f) += 1;
        -- b;
    }
    /*
    //ağaçların son hallerinin uzunlukları
    for (e = 0; e < a; ++ e) {
        printf ("%d ", * (c + e));
    }
    printf ("\n");
    */
    f = * (c + 0);
    for (e = 1; e < a; ++ e) {
        if (* (c + e - 1) > * (c + e)) {
            f = * (c + e);
        }
    }
    printf ("%d", f);
    free (c);
    return EXIT_SUCCESS;
}