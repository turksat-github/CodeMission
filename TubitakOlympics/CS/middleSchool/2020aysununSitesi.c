/*
AYSU'NUN SİTESİ

Zengin müteahhitlerden olan Aysu elindeki yeni arsaya büyük bir site yapmak istemektedir. Bu arsa, koruma bölgesinde olduğu için ev yapılacak yerler daha önceden belirlenmiştir. Aysu'nun elinde mimarlarından gelen apartmanlarının kaç katlı olduğunu gösteren bir liste vardır. Bu listedeki apartmanları tam olarak birer kez kullanmalıdır.
Devletin belirlediği ev yapılabilir bölgeler ise Bilgisayar Bilimlerindeki ağaç veri tipindedir. 1. arsa her zaman kök (root) olacak şekildedir. Bunun yanı sıra N adet arsa N - 1 yol ile birbirine bağlıdır.
N adet arsaya yapılan N adet apartmandan oluşan sitenin maliyeti şu şekilde hesaplanmaktadır: Her bir apartman için o apartmanın kat sayısı ile ağaçta bulunduğu derinliğinin çarpımı bütün apartmanlar için hesaplanıp toplanır.
Not: 1 numaralı arsanın yani root'un derinliği 1'dir. 1'e bağlı arsaların derinliği 2'dir onun altındakiler 3 olacak şekilde birer birer artmaktadır.
Aysu olabildiğince fazla kâr etmek istediği için apartmanları verilen N adet arsaya minimum maliyetle yerleştirmek istemektedir. Unutmayın ki Aysu N adet arsaya tam olarak N adet apartman inşa etmek zorundadır ve size verilen her apartmanı yalnızca 1 kez kullanabilir.
Aysu'nun kodlama bilgisi yetersiz olduğu için sizden yardım istemektedir.
Verilen ağaç yapısı ve apartmanların katlarını kullanarak minimum kaç maliyetle site inşa edilebileceğini hesaplayabilir misiniz?

Girdi Biçimi
İlk satırda N sayısı: Kaç adet boş arsa ve kaç adet apartman olduğu
İkinci satırda N adet tamsayı: Elindeki apartmanların kaç katlı oldukları
Daha sonra gelen N - 1 satırda ise arsaları birbirine bağlayan yolları ifade eden 2 tamsayı U ve V:
U'dan V'ye ve V'den U'ya yol olduğunu gösterir.

Çıktı Biçimi
Tek satırda N adet apartman ile oluşturulabilecek sitenin minimum maliyeti.

Limitler:
1 ≤ N ≤ 10e5
1 ≤ Kat sayısı ≤ 10e5

Girdi 1
4
5 10 1 2
1 2
1 3
1 4

Çıktı 1
26

Örnek 1 Açıklaması:
1 numaralı arsaya yani root'a 10 katlı apartman yapılır. 2, 3 ve 4. arsalar 2. derinlikte olduğu için sırası fark etmeksizin diğer apartmanlar dikilir.
(10 * 1) + (5 * 2) + (1 * 2) + (2 * 2) = 26

Altgörevler:
Altgörev 1 (12 puan): 1 ≤ N ≤ 10
Altgörev 2 (35 puan): 1 ≤ N ≤ 2000
Altgörev 3 (15 puan): Kat sayısı her zaman 1'e eşittir
Altgörev 4 (38 puan): Hiçbir ek kısıtlama yoktur
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}