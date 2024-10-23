/*
MARSUPİLAMİLER

Brezilya'nın el değmemiş Amazon ormanları günümüzde pek çok canlı türüne ev sahipliği yapmaktadır. Bu canlılardan biri de herkesin çok sevdiği Marsupilamilerdir! Marsupilamiler asırlardır bu ormanlarda huzur içerisinde yaşamaktadırlar. Günün birinde Marsupilamilerin lideri olan Marsu'nun dikkatini çeken bir olay yaşanır. Marsu'nun oğlu Bobo sayı saymayı bilmiyordur! Evet, daha doğrusu, Bobo'nun bildiği en büyük sayı 3'tür. Yani, Bobo'nun bildiği yalnızca üç tam sayı vardır: 1, 2 ve 3. Dahası, Bobo'ya göre 3'ten büyük olan bütün sayılar "COK" olarak isimlendirilmiştir. Yani, Bobo'nun sayılara dair bildiği şeyler şunlardır: 1, 2, 3, COK. Bobo, 0 sayısını bile bilmemektedir. Marsupilamiler ormandaki mahallelerinde bir düzen içerisinde yaşamaktadırlar. Ormanda toplamda N adet aile oturmaktadır ve bu aileler arasında toplamda N - 1 adet 1 kilometre uzunluğunda çift yönlü yollar bulunmaktadır. Bu yapı bilgisayar bilimindeki bir “ağaç” yapısına benzemektedir. Ormandaki düzende herhangi bir döngü yoktur ve isteyen istediği evi ziyaret edebilmektedir. Aşağıdaki görselde 13 evden oluşan örnek bir ormanı görebilirsiniz.

     4
      \
       \
        \
13       2
  \     /|\
   \   / | \
    \ /  |  \
12   5   8   1
  \  |       |
   \ |       |
    \|       |
     3       7
    /\
   /  \
  /    \
10      9
       /
      /
     /
   11
Görsel 1: 13 evden oluşan bir Marsupilami mahallesi.

Yılbaşı gecesi Bobo, en yakın arkadaşı Bebe'nin evine gitmek istemektedir. Bobolar 1 numaralı apartmanda oturmaktadır. Arkadaşı Bebe ve ailesi ise N numaralı apartmanda oturmaktadır. Bobo, yılbaşı gecesi Bebe'nin evinde gitmek için Marsu'dan izin ister. Marsu, arabasında yeterince benzin olup olmadığından emin değildir. Bu yüzden Bobo'ya Bebe'nin evine ne kadar uzaklıkta oturduklarını sorar. Bobo'ya Bebe ile aralarındaki uzaklığı bulması için yardımcı olabilir misiniz?

Limitler
2 ≤ N ≤ 10e5

Girdi Biçimi
İlk satırda toplam apartman (aile) sayısı olan N verilecektir. Sonraki N - 1 satırın her birinde iki adet sayı, x ve y verilecektir. Bu satır, x'ten y'ye giden ve y'den x'e giden birer kilometrelik sokakların bulunduğunu ifade etmektedir.

Çıktı Biçimi
Bobo ile Bebe'nin evleri arasındaki mesafeyi yazdırınız. Dört farklı cevap olabilir: 1, 2, 3, COK.

COK ÖNEMLİ NOT:
Cevap ÇOK çıkarsa Ç harfi yerine C harfini kullanın. Yani, COK yazdırın.

Örnek Girdiler

Girdi 1
6
1 2
2 3
2 5
3 4
2 6

Çıktı 1
2

        1
       /
      /
4    2----6
 \  /\
  \/  \
  3    5
Görsel 2: Bobo (1) ile Bebe (6) arasındaki uzaklık 2 kilometre: Önce 1'den 2'ye 1 km, sonra 2'den 6'ya 1 km.

Girdi 2
6
1 2
2 3
2 5
3 4
4 6

Çıktı 2
COK

   6    1
  /    /
 /    /
4    2
 \  /\
  \/  \
  3    5
Görsel 3: Bobo (1) ile Bebe (6) arasındaki uzaklık 4 kilometre: COK.

Girdi 3
6
1 2
2 3
2 5
3 4
5 6

Çıktı 3
3

Girdi 4
6
1 2
2 3
2 5
3 4
1 6

Çıktı 4
1

Altgörevler
Altgörev 1 (10 puan): Mahallede en fazla 3 ev bulunmaktadır.
Altgörev 2 (10 puan): Mahallede bir adet merkez ev vardır ve kalan bütün evler bu merkez eve doğrudan bağlıdır.
Altgörev 3 (10 puan): Mahalledeki evler bir ip gibi dizilidir. Baştaki ve sondaki iki ev hariç bütün evlerin iki komşusu vardır.
Altgörev 4 (10 puan): Bebe ile Bobo'nun evleri arasındaki mesafe en çok 3'tür.
Altgörev 5 (60 puan): Limitler dahilinde herhangi bir durum olabilir.
Altgörev 4 (37 puan): Herhangi bir kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}