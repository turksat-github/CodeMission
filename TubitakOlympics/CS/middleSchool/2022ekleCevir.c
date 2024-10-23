/*
EKLE-ÇEVİR

Limitler
Zaman Sınırı: 2 saniye
Hafıza Sınırı: 256 MB

Soru Metni
Sayılarla oynamayı çok seven Ahmet, Ekle-Çevir adında yeni bir oyun keşfetmiştir. Bu oyunda verilen N adet tamsayı için aşağıdaki adımlar uygulanmaktadır.
Oyun boş bir dizi ile başlar ve her ai sayısı için i'inci işlemde;
1. ai sayısını dizinin sonuna ekle.
2. Dizinin elemanlarını ters çevir.
adımları yapılır.
Verilen N adet tamsayı için Ekle-Çevir oyunu sonunda oluşacak diziyi bulmasında Ahmet'e yardım ediniz.

Kısıtlamalar
1 <= N <= 200.000
0 <= ai <= 10e9
N ve ai sayıları tam sayıdır.

Alt Görevler
30 puan için N <= 1.000
70 puan için her ek kısıtlama yok.

Örnek Girdi 1
4
1 2 3 4

Örnek Çıktı 1
4 2 1 3

Örnek Çıktı 1 Açıklaması
● 1. işlemde sayı eklendikten sonra dizi: 1.
● 1. işlemde dizi ters çevrildikten sonra dizi: 1.
● 2. işlemde sayı eklendikten sonra dizi: 1,2.
● 2. işlemde dizi ters çevrildikten sonra dizi: 2,1.
● 3. işlemde sayı eklendikten sonra dizi: 2,1,3.
● 3. işlemde dizi ters çevrildikten sonra dizi: 3,1,2.
● 4. işlemde sayı eklendikten sonra dizi: 3,1,2,4.
● 4. işlemde dizi ters çevrildikten sonra dizi: 4,2,1,3.

Örnek Girdi 2
3
1 2 3

Örnek Çıktı 2
3 1 2

Örnek Girdi 3
1
1000000000

Örnek Çıktı 3
1000000000

Örnek Girdi 4
6
0 6 7 6 7 0

Örnek Çıktı 4
0 6 6 0 7 7
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}