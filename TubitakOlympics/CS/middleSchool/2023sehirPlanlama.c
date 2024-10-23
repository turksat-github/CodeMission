/*
ŞEHİR PLANLAMA

Zaman kısıtı: 1 sn
Memory kısıtı: 64 MB

Ilgınkent adlı şirin kasabada, N bölge vardır ve bunlar N-1 yol ile birbirine bağlıdır. Yani bölgeler ağaç benzeri bir yapı oluşturmaktadır. Bu kasabada komşu olan bölgeler arasındaki mesafe eşittir ve 1 birimdir. Bir i ve j bölgesinin birbirine komşu olması şu şekilde tanımlanır: Eğer i den yola çıkan bir kişi başka bir bölgeye uğramadan j ye ulaşabilirse bu durumda i bölgesi ile j bölgesi komşudur.
Belediye Başkanı Bayan Kaya, şehri karmaşık bir ağaç yapısı yerine yollar ile düzenlemenin çeşitli idari görevleri basitleştireceğine inanıyor. Bu amacı gerçekleştirmek için Bayan Kaya senin yardımına ihtiyaç duyuyor. Daha açık olarak, Bayan Kaya senden her K tamsayısı için, şehrin tam olarak K uzunluğunda yollara bölünüp bölünemeyeceğini belirleyen bir algoritma tasarlamanı istemektedir.

Girdi Formatı
Girdinin ilk satırında bölge sayısı (N) vardır.
Sonraki N − 1 satırın her biri, a ve b komşu bölgeleri arasındaki bağlantı yolunu tanımlayan, boşlukla ayrılmış iki tamsayı a ve b içerir.

Çıktı Formatı
Tek satıra N − 1 uzunluğunda 0 ve 1'lerden oluşan bit dizisi çıktısı yazdırın. Her K tam sayısı (1 ≤ K ≤ N−1) için, eğer ağacın kenarlarını tam olarak K uzunluğundaki yollara bölmek mümkünse, bu dizinin soldan K'ıncı biti bire eşit olmalıdır. Diğer türlü bu bit sıfır olacaktır.

Limitler
● 2 ≤ 𝑁 ≤ 10e5
● 1 ≤ 𝐾 ≤ 𝑁 − 1
● 1 ≤ 𝑎, 𝑏 ≤ 𝑁

Alt Görevler
Alt Görev 1 (24 Puan)
● 𝑁 ≤ 10e3
Alt Görev 3 (76 Puan)
● Ek kısıt yoktur.

Örnek Girdi
10
1 2
2 3
2 4
4 5
2 6
6 7
6 8
8 9
9 10

Örnek Çıktı
101000000

Örnek Açıklaması
Verilen ağacı K = 1 ve 3 için K uzunluğundaki yollara bölmek mümkündür. K = 3 için olası yol kümesi aşağıdaki gibidir:
1-2-4-5, 3-2-6-7, 6-8-9-10
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}