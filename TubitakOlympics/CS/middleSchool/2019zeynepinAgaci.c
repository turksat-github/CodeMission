/*
ZEYNEP'İN AĞACI

Zeynep, doğayı çok sevmektedir. Ağaçlara olan ilgisi bilgisayar bilimlerinde kullanılan Ağaç yapılarına da yansımıştır. Bilgisayarda bildiğiniz üzere bazı özel ağaç yapıları var. Zeynep, "Her ağaç bir kenera, Binary Search Tree bir kenara" diyerek Binary Search Tree'lere olan özel ilgisini göstermiştir. Zeynep'e herhangi bir özelliği bulunmayan ağaç veriliyor. Bu ağacın root'u 1 ve her node'un bir tamsayı değeri bulunmakta. Zeynep bu ağaçtan root'u içeren bir altağaç seçmek istiyor öyle ki bu ağaç Binary Search Tree özelliklerini sağlayan en büyük altağaç olsun.
Biraz daha açık olmak gerekirse verilen ağaçta rootu içeren ve size'ı en büyük olan BST'nin size'ını ekrana yazdırmak. Yanlış anlaşılmayı engellemek için, sizden istenen node değerleri toplamını değil BST'deki node sayısını maksimize etmeniz.
Bir ağacın Binary Search Tree (BST) olması için gereken şartlar:
Her node'un (düğüm) en fazla 2 çocuğu olabilir.
Her node için sol tarafındaki bütün node'lar kendi değerinden küçük eşit olmalı. Her node için sağ tarafındaki bütün node'lar kendi değerindein büyük olmalı.

Örnek1:
     7
   /   \
  5     10
 / \   / \
2   6 8   20
Bu ağaç yukarıdaki tüm şartları sağladığı için bir BST'dir.

Örnek2:
     2
   /   \
  1     5
 / \   / \
0   3 4   6
Ancak bu ağaç değildir. Çünkü 2'nin sol tarafında bulunan 3 değeri 2'den büyüktür.

Girdi Biçimi
Birinci satırda: Ağaçtaki toplam node sayısını belirten N
İkinci satırda N adet tamsayı: i. sayı i. node'un değerini belirtmektedir.
Takip eden N - 1 satırda yolları belirten u ve v. u'dan v'ye ve v'den u'ya yol olduğunu belirtmektedir.

Çıktı Biçimi
Tek bir sayı: Ağaçtaki, root'u içeren en büyük BST'nin size'ı.

Limitler
1 ≤ N ≤ 5 * 10e4
0 ≤ NodeDegeri ≤ 10e9

Girdi 1
5
12 2 3 11 15 12
1 3
2 4
1 5

Çıktı 1
4

Örnek 1 Açıklaması
    *12
  /  |  \
*2   3   *15
  \
  *11
Soluna yıldız konulan sayıların oluşturduğu bu ağaç en büyük BST'dir.
En uzunu olan [1, 2, 3] olduğu için ve bu dizinin uzunluğu 3 olduğu için cevap 3 olacaktır.

Girdi 2
6
10 7 4 5 3 2 12
1 3
1 4
2 5
3 6

Çıktı 2
3

Örnek 2 Açıklaması
      *10
     / | \
   *7  4  5
  /   /
*3   2
Soluna yıldız konulan sayıların oluşturduğu bu ağaç en büyük BST'sidir.
Aynı şekilde 10, 4, 2 de cevaplardan birisidir.
    *10
   / | \
  7  *4  5
 /  /
3 *2

Altgörevler
Altgörev 1 (12 puan): 1 ≤ N ≤ 10
Altgörev 2 (14 puan): 1 ≤ N ≤ 2000
Altgörev 3 (10 puan): 1≤ N ≤ 5*10e4, 0 ≤ NodeDegeri ≤ 1
Altgörev 4 (14 puan): 1≤ N ≤ 5*10e4, 0 ≤ NodeDegeri ≤ 10
Altgörev 5 (50 puan): Ek bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}