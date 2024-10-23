/*
İKİ SİLO

Bir buğday fabrikasında iki tane silo bulunmaktadır. İkisinin de kapasitesi N tondur ve başlangıçta bunların ikisi de boştur. Fabrikaya buğday getiren ve fabrika önünde tek bir sıra halinde bekleyen M tane kamyon vardır. Sırada bekleyen kamyonların sırası sabittir yani sıra ile iki silodan birine yüklerini boşaltmaları gerekmektedir. Sıradaki kamyon yükünün tamamını boşaltıp gitmektedir. i. kamyonun yükü Ki kilo buğdaydır ve bu değer kamyondan kamyona değişebilir. Bir kamyon yükünü iki silodan sadece birisine tek bir seferde boşaltabilir ve bunun için en az bir siloda, yeterince boş yer olması gerekmektedir. Bütün kamyonların sıralı listesi ve yük miktarları verildiğinde hedefimiz en fazla sayıda kamyonu boşaltmaktır. Bunun için sırayla her bir kamyonun hangi siloya boşaltım yapması gerektiğini bulunuz.

Girdi Biçimi
İlk satırda iki tamsayı olarak N ve M vardır. N siloların kapasitesini ton olarak ve M de sırada bekleyen kamyonların sayısını göstermektedir.
Devam eden M satırda sırayla her bir kamyonun taşıdığı buğday miktarı kilo olarak belirtilmektedir.

Çıktı Biçimi
İlk satırda en fazla kaç tane kamyonun boşaltılabileceği yer almalıdır. Bu sayıya A diyelim. Devam eden A satırda 1 ya da 2 değerleri olmalıdır. 1 değeri o kamyonun 1. siloya, 2 değeri de 2. siloya boşaltıldığını belirtmektedir.

Not: Sorunun birden fazla cevabı olması durumunda herhangi birisini çıktı olarak verebilirsiniz.

Örnek Girdiler

Girdi 1
5 7
2500
3000
1000
1000
1500
700
800

Çıktı 1
6
1
2
2
2
1
1

Girdi 2
1 2
2000
1000

Çıktı 2
0

Örnekler için Açıklama

Girdi 1:
İlk kamyon birinci siloya boşaltılınca birinci silonun yarısı dolmuş olur. Sonraki kamyon birinci siloya sığmaz. Devam eden 3 kamyon ikinci siloya boşaltılır ve ikinci silo dolmuş olur. Daha sonraki 1500 ve 700 kiloluk kamyonlar birinci siloya boşaltılınca birinci siloda 300 kiloluk yer kalmış olur. Sıradaki son kamyon hiçbir siloya sığmayacağından en fazla 6 kamyon bu şekilde boşaltılmış olur.

Girdi 2:
Siloların kapasitesi 1 tondur fakat sıradaki ilk kamyonda 2 ton buğday vardır. Bu nedenle hiçbir kamyonu boşaltmak mümkün değildir. Çıktı olarak sadece 0 basılır.

Limitler
1 ≤ N ≤ 100,
1 ≤ M ≤ 200,
10 ≤ Ki ≤ 10e5, her bir 1 ≤ i ≤ M için

Altgörev 1 (15 puan): Bütün kamyonlarda eşit ağırlıkta buğday vardır.
Altgörev 2 (30 puan): 1 ≤ M ≤ 20
Altgörev 3 (55 puan): Ek kısıt bulunmamaktadır.
NOT: Eğer çıktıdaki ilk satırı yani kamyon sayısını ilgili altgörevin tüm test case'lerinde doğru yazdırıp devam eden satırlardaki silolara dağıtmada hata yaparsanız o altgörevin puanının yarısını alırsınız.
Altgörev 4 (37 puan): Herhangi bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}