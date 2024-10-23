/*
MELİS'İN LİSTESİ

Melis listeleri çok sevmektedir. Melis'in elinde bir sürü tam sayı var (N adet). Bu sayılardan bazılarını belki tamamını seçmek istiyor. Bu seçtiği sayıları kendi listesine ekliyor. Ama listeye eklerken bazı şartları sağlaması gerekiyor. Öncelikle bir elemanı birden fazla ekleyemiyor. Ama o eleman verilen dizide birden fazla kez varsa ekleyebilir.
Örneğin [2, 3, 4] listesinden [3, 3] gibi bir liste türetemez. Ancak [2, 3, 3, 4] listesinden [3, 3] üretebilir.
Bir diğer şart ise Melis'in listesindeki hiç bir ikilinin farkı K'dan büyük olamaz.
Yani bütün Ai ve Aj ikilileri için |Ai − Aj| ≤ K olmak zorunda.
Melis, bu şartları sağlayan en uzun diziyi oluşturmak istiyor.
Ancak programlama bilgisi sizin kadar iyi olmadığı için bunu tek başına yapamıyor.
Sizden istenen verilen N adet tam sayı ve K sayısını göz önünde bulundurarak en uzun listenin eleman sayısını ekrana yazdırmanız.

Girdi Biçimi
Birinci satırda: Sırasıylar N ve K; ikinci satırda: N adet tam sayı.

Çıktı Biçimi
Tek bir sayı: Melis'in oluşturabileceği şartlara uygun en uzun dizinin eleman sayısı.

Limitler
1 ≤ N, K ≤ 10e5, 0 ≤ Ai ≤ 10e5

Girdi 1
5 10
1 2 3 12 15

Çıktı 1
3

Örnek 1 Açıklaması
Melis'in şartlara uygun oluşturabileceği dizilerden bazıları:
[1, 2, 3]
[12, 15]
En uzunu olan [1, 2, 3] olduğu için ve bu dizinin uzunluğu 3 olduğu için cevap 3 olacaktır.

Girdi 2
5 20
34 33 32 31 30

Çıktı 2
5

Altgörevler
Altgörev 1 (12 puan): 1 ≤ N, K ≤ 10
Altgörev 2 (14 puan): 1 ≤ N ≤ 10e5, 1 ≤ K ≤ 10
Altgörev 3 (10 puan): 1 ≤ N ≤ 10e5, K = 0
Altgörev 4 (14 puan): 1 ≤ N, K ≤ 1000
Altgörev 5 (8 puan): 1 ≤ N ≤ 10e5, K = 1
Altgörev 6 (42 puan): Ek bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}