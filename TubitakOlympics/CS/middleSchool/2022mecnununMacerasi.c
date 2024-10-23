/*
MECNUN'UN MACERASI

Mecnun yine bir gün kendisini bir çölde bulmuş. Ancak bu çöl diğer çöllerden biraz daha farklı bir yapıdaymış. Çöl bilgisayar bilimlerindeki ağaç'lara benzer bir yapıdadır. Bilindiği üzere ağaç yapısı, n düğümden ve n - 1 kenardan oluşmaktadır ve herhangi bir düğümden başka bir düğüme tam olarak 1 tane yol bulunmaktadır. Çölümüzde de toplam n adet düğüm bulunmaktadır. Çölde düğümler 1'den n'ye kadar numaralandırılmıştır. Ayrıca çölün kök düğümü 1 numaralı düğümdür.
Mecnun'un çöldeki kök düğümde bulunmaktadır. Çölden tek çıkış ağacın yaprak düğümleridir. Kök ve yaprak düğümleri de dahil olmak üzere her düğümde Mecnun'un karşısına aksakallı dede çıkmaktadır. Aksakallı dede Mecnun'un uğradığı bütün düğümlerde ona bir görev vermektedir. Her bir görevin bir zorluk değeri vardır ve i. düğüm için bu zorluk değeri di'ye eşittir. Herhangi iki düğümdeki zorluk değerleri eşit değildir. Mecnun çölden kurtulmak istemektedir, ayrıca olabildiğince kolay bir şekilde kurtulmak istemektedir. Mecnun aşağıdaki kurallara göre ideal bir yol bulmak istiyor:
• Mecnun kökten başlayan ve bir yaprakta biten bu yolcuğu boyunca herhangi bir düğüme birden fazla kez uğramak istemiyor.
• Yolculuğu sona erdikten sonra uğradığı düğümlerdeki di değerlerini sıraladığında oluşan dizi alfabetik olarak olabildiğince küçük olsun istiyor.
Örneğin Mecnun için alternatif iki yolculuğu ele alalım.
1. Birinci yolumuzda uğradığımız düğümlerin zorlukları {4, 1, 6, 3} olsun. O zaman bu yolculuk sonrasındaki zorluk değerlerini sıralarsak {1, 3, 4, 6} dizisi elde edilir.
2. İkinci yolumuzda uğradığımız düğümlerin zorlukları {4, 1, 7, 2} olsun. O zaman bu yolculuk sonrasındaki zorluk değerlerini sıralarsak {1, 2, 4, 7} dizisi elde edilir.
Bu iki yolculuğu karşılaştırırsak; {1, 2, 4, 7} dizisi {1, 3, 4, 6} dizisinden alfabetik olarak daha küçüktür. Bu nedenle Mecnun ikinci yolu tercih etmelidir.
Mecnun yukardaki tanıma göre en ideal yolu tercih ettiğini ve yolculuğunu tamamladığını varsayalım. Sizden istenen Mecnun'un yolculuğunu tamamladıktan sonra elde ettiği sıralı diziyi bulmanız.

Girdi Biçimi
İlk satırda n tamsayısı, Ağaç şeklinde olan çölün toplam düğüm sayısı.
Devamındaki n - 1 satırda 2 adet tamsayı ui, vi, çöldeki i. kenarın bağladığı iki düğümün numarası.
Son satırda n adet tamsayı, d1, d2, ..., dn çöldeki düğümlerdeki görevlerin zorluk değerleri.

Çıktı Biçimi
Mecnun'un yolculuğunu tamamladıktan sonra elde ettiği sıralı dizi.

Örnek Girdiler

Girdi 1
6
1 2
2 3
2 4
4 5
3 6
4 1 6 7 2 3

Çıktı 1
1 2 4 7

Örnek Girdi Açıklaması
    1
    |
    2
   / \
  3   4
 /     \
6       5
Bu girdi soru metninde açıklan durum için örnek bir girdidir. Olası iki yolculuklar ({4, 1, 6, 3} ve {4, 1, 7, 2}) sıralandığında alfabetik olarak en küçük olan yol seçilmiştir.

Girdi 2
6
1 2
1 5
2 3
2 4
3 6
5 6 3 2 7 1

Çıktı 2
1 3 5 6

Örnek Girdi Açıklaması
    1
   / \
  2   5
 / \
3   4
 \
  6

Limitler
• 1 ≤ n ≤ 10e5
• 1 ≤ di ≤ 10e6
• Tüm di değerleri farklıdır.

Altgörev 1 (15 puan): n ≤ 100
Altgörev 2 (25 puan): n ≤ 2000
Altgörev 4 (60 puan): Herhangi bir kısıtlama bulunmamaktadır.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}