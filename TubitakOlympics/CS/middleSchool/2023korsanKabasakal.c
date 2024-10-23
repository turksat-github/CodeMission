/*
KORSAN KABASAKAL

Zaman kısıtı: 1 sn
Memory kısıtı: 64 MB

Korsan Kabasakal bir gün okyanusta ilerlerken Uçan Hollandalı gemisi tarafından esir alınıyor. Uçan Hollandalı'nın kaptanı Davy Jones, Kabasakal'a onu yapacağı yarışmayı kazanması durumunda serbest bırakacağını söylüyor. Bu yarışma bir sayı tahmin etme yarışması. Davy Jones aklından 1'den N'ye (sınırlar dahil) kadar olan tam sayılardan bir sayı tutuyor, bu sayı X olsun. Kabasakal'ın bu sayıyı tahmin edip yarışmayı kazanmak için tek bir hakkı var. Ama Davy Jones Kabasakal'a istediği kadar soru sorma hakkı veriyor. Kabasakal sorularında Davy Jones'a bir M veriyor, Davy Jones'da aklındaki sayının M'den küçük veya eşit olup olmadığını yani (X <= M) şartının sağlanıp sağlanmadığını söylüyor.
Yarışmayı kazanıp bu sayede köpekbalıklarına yem olmak istemeyen Kabasakal, bu yarışmada kullanmak için bir algoritma geliştiriyor.
Algoritmanın özellikleri şu şekilde:
1. L = 1, R = N olarak L ve R değişkenleri tanımla.
2. Eğer L = R ise Davy Jones'in aklındaki sayıyı L olarak tahmin et ve algoritmayı sonlandır.
3. (L <= M < R) koşulunu sağlayan herhangi bir M tam sayısı seç ve yarışmada belirtilen soruyu sor.
4. Eğer 3. adımda alınan cevaba göre (X <= M) ise R = M olarak güncelle. (X <= M) değil ise L = M + 1 olarak güncelle. Sonra 2. adıma dön.
Kabasakal'ın algoritmasının ne kadar iyi çalıştığını analiz etmek için bazı değerlere ihtiyacı var.
Sizin göreviniz Kabasakal'ın Q adet sorgusuna doğru cevap vermek.
Her sorgu T N formatında iki tam sayıdan oluşmaktadır. Ayrıca (1 <= T <= 2) şartı her sorguda sağlanmaktadır.
T = 1 ise N Davy Jones'in 1'den N'ye (sınırlar dahil) kadar bir sayı tuttuğunu ifade ediyor. Sorguda bu durumda algoritmanın bir çalışmasında oluşan tüm farklı (L, R) ikililerini bir kümeye eklemiş olsaydık elde edebileceğimiz farklı küme sayısını hesaplamamızı istiyor.
T = 2 ise N Davy Jones'in 1'den N'ye (sınırlar dahil) kadar bir sayı tuttuğunu ifade ediyor.
Sorguda bu durumda algoritmanın bir çalışmasında oluşan tüm farklı (L, R) ikililerini bir kümeye eklemiş olsaydık elde edebileceğimiz farklı kümelerin boyutlarının toplamını hesaplamamızı istiyor.

Not1: Algoritmanın son durumda farklı bir kümeyle sonlanabilmesinin sebebi Davy Jones'in aklından farklı bir sayı tutabilmesi ayrıca Kabasakal'ın algoritmasının da 3. adımda farklı M değerleri seçebilmesidir. Farklı durumların örnekleri için Örnek Açıklama'ya bakabilirsiniz.

Not2: Hesaplanan değerler çok büyük olabileceğinden cevapların 𝑚𝑜𝑑 37373737'deki değerini bulun.

Girdi:
1. satırda bir adet tam sayı, Q. (sorgu sayısı)
Takip eden Q adet satırın her birinde 2 adet tam sayı T ve N. (sorgu içeriği)

Çıktı:
Q tane tam sayı yazdırın — Sorgular için cevabın 𝑚𝑜𝑑 37373737'deki değeri.

Kısıtlar
1 ≤ 𝑄 ≤ 500000
1 ≤ 𝑇 ≤ 2
1 ≤ 𝑁 ≤ 10e9

Alt Görevler
Alt Görev 1 [14 puan]
Q, N <= 15
Alt Görev 2 [8 puan]
N, Q <= 500, T = 1
Alt Görev 3 [8 puan]
N, Q <= 500, T = 2
Alt Görev 4 [13 puan]
N <= 500000, T = 1
Alt Görev 5 [17 puan]
N <= 500000, T = 2
Alt Görev 6 [10 puan]
N <= 10e9, T = 1
Alt Görev 7 [30 puan]
N <= 10e9, T = 2

Örnek Girdi
8
1 1
1 2
1 3
2 3
1 37
2 37
1 37373737
2 37373737

Örnek Çıktı
1
2
6
16
19842447
16816743
30540670
32818359

Örnek Açıklama
Sorgu T = 1, N = 1 için tüm farklı durumlar {(1, 1)} toplam 1 küme içerdiğinden cevap 1.
Sorgu T = 1, N = 2 için tüm farklı durumlar {(1, 2), (1, 1)}, {(1, 2), (2, 2)} toplam 2 adet küme içerdiğinden cevap 2.
Sorgu T = 2, N = 3 için tüm farklı durumlar {(1, 3), (1, 1)}, {(1, 3), (1, 2), (1, 1)}, {(1, 3), (1, 2),
(2, 2)}, {(1, 3), (2, 3), (2, 2)}, {(1, 3), (2, 3), (3, 3)}, {(1, 3), (3, 3)} toplam 6 küme içerdiği ve boyutları 2 + 3 + 3 + 3 + 3 + 2 = 16 olduğu için cevap 16.
Not: {(1, 3), (1, 2), (1, 1)} kümesi N = 3 iken Davy Jones'in aklından 1 seçmesi ve Kabasakal'ın algoritmasının sırasıyla, M = 2 ve M = 1 seçmesi sonucu oluşmuştur.
{(1, 3), (1, 1)} kümesi N = 3 iken Davy Jones'in aklından 1 seçmesi ve Kabasakal'ın algoritmasının M = 1 seçmesi sonucu oluşmuştur.
{(1, 3), (2, 3), (2, 2)} kümesi N = 3 iken Davy Jones'in aklından 2 seçmesi ve Kabasakal'ın algoritmasının sırasıyla, M = 1 ve M = 2 seçmesi sonucu oluşmuştur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}