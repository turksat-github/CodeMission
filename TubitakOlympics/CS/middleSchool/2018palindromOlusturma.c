/*
PALİNDROM OLUŞTURMA

Sağdan sola ve soldan okunuşu aynı olan dizgelere palindrom dizge denir. Mesela 'ses' ve 'adda' dizgeleri birer palindrom dizge oluşturmaktadır. Çünkü tersten ve düzden okunuşları aynıdır.
Fakat 'yarış' ve 'sıvı' kelimeleri palindrom dizge değildir. Çünkü 'yarış' tersten 'şıray' olarak okunur ve bu iki okunuş birbirinden farklıdır. Ayrıca 'sıvı' kelimesi de tersten 'ıvıs' diye okunur. Bu yüzden bu da palindrom olamaz.
Herkes Bera'nin palindrom dizgelere bayıldığını bilir. Annesi Bera'ya oyuncak olarak bir miktar harf almıştır. Oyuncakçıda sadece 'a' ve 'b' harfleri kaldığı için annesinin aldığı harfler sadece bu 2 harften olabilir. Bera ise bu harflerden bir palindrom dizge oluşturmak istemektedir. Uzun palindromları daha çok sevdiği için aynı zamanda bu palindrom dizgenin olabildiğince uzun olmasını istemektedir. Ama bunu nasıl yapacağını bilmiyordur. Bu yüzden en iyi arkadaşından yani sizden yardım istiyor.
Size girdide tek satırda Bera'ya annesinin aldigi 'a' harfi sayısı, ardından da 'b' harfi sayısı verilecek. Sizden istenen ise bu harflerden istediğiniz kadarını seçip, bunları istediğiniz sırada dizerek bir palindrom dizge oluşturmanız, oluşturulan bu palindromun da olabildiğince çok sayıda harf içermesidir.
Bu en uzun palindromun uzunluğunu ekrana bastırmalısınız.

Girdi Biçimi:
İlk satırda iki tam sayı: A ve B.
Bu sayılar sırasıyla annesinin Bera'ya aldığı 'a' harflerinin ve 'b' harflerinin sayıları.

Çıktı Biçimi:
Tek satırda bu harflerden elde edilebilecek en uzun palindrom dizgenin uzunluğunu bastırın.

Sınırlar:
0 ≤ A, B ≤ 1000
Alt Görev 1 (10 puan) : Girdide çift sayıda a harfi ve çift sayıda b harfli geçecektir.
Alt Görev 2 (15 puan) : Girdide tek sayıda a harfi ve tek sayıda b harfli geçecektir.
Alt Görev 3 (75 puan) : Hiçbir ek kısıtlama yoktur.

Örnek Girdi 1:
2 2

Örnek Çıktı 1:
4

Açıklama
Bera'nın elinde 4 adet harf vardır, bunlar 2 adet 'a' ve 2 adet 'b' harfidir.
Bunlardan 'baab' veya 'abba' dizgelerini oluşturursa en uzun palindromu elde etmiş olur.

Örnek Girdi 2:
1 1

Örnek Çıktı 1:
1

Açıklama
Bera'nın elinde 2 adet harf vardır, bunlar 1 adet 'a' ve 1 adet 'b' harfidir.
Bunlardan 'a' veya 'b' dizgelerini oluşturursa en uzun palindromu elde etmiş olur.
Eğer 'ab' veya 'ba' dizgelerini oluşturursa palindrom elde edemez.

Örnek Girdi:
1 2

Örnek Çıktı:
3

Açıklama
Bera'nın elinde 3 adet harf vardır, bunlar 1 adet 'a' ve 2 adet 'b' harfleridir.
Bunlardan 'bab' dizgesini oluşturursa en uzun palindromu elde etmiş olur.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a, b, c;//a a sayısı, b b sayısı, c en fazla polindrom sayısı
    scanf ("%d %d%*c", &a, &b);
    //Çift olan şeyden hepsi konulabilir.
    //Elde edilen polindrom sayısı çift ise, konulanın sayısı tek olsa bile hepsi konulabilir
    //Elde edilen polindrom sayısı tek ise, konulanın sayısı tek ise bir eksiği konulabilir
    c = 0;
    c = a;
    if ((b % 2) == 0) {
        c += b;
    }
    else {
        if ((c % 2) == 0) {
            c += b;
        }
        else {
            c += (b - 1);
        }
    }
    printf ("%d", c);
    return EXIT_SUCCESS;
}