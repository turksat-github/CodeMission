/*
EŞİT YOLLAR

Utkuland kralı ölünce kralın ikiz çocukları olan Tarık ve Melih arasından kimin yeni kral olacağına bir türlü karar verilemedi. Utkuland'ı ikiye bölmekten başka çare yoktu. Utkuland'ı paylaştırması için imparatorluğun en bilge adamı olan Utku'ya danıştılar.
Bilge Utku tüm şehirleri ayrı ayrı iki parçaya ayırmaya karar verdi.
Bir bölgeden diğerine izinsiz geçişler olmasın diye Tarıkland'den Melihland'e olan neredeyse tüm yolları kapattı.
Her şehir için Tarıkland'den Melihland'e geçen tek taraflı geçiş yolu vardır.
Ayrıca Utkuland'deki tüm yolların geçiş ücreti vardır.
T1 → M1
↓↑↘↖   ↘↖
↓↑ ↘↖   ↘↖
↓↑  ↘↖   ↘↖
↓↑   ↘↖   ↘↖
↓↑    T2 → M2
↓↑       ↙↗
↓↑      ↙↗
↓↑     ↙↗
T3 → M3
Tarık 1 numaralı şehirde kendi bölgesinde yaşarken Melih N numaralı şehirde kendi bölgesinde yaşamaktadır.
Tarık imparatorluğu yönetememektedir. Bu yüzden bunu fark eden 1 numaralı şehrin Tarıkland bölgesindeki insanlar N şehrinin Melihland bölgesine göç edeceklerdir.
Utkuland insanları çok zekidir, V şehrinden U şehrine giderken her zaman en ucuz güzergahı tercih ederler. Bilge Utku, her şehirdeki Tarıkland'den Melihland'e geçiş ücretlerini öyle ayarlamalıdır ki Tarıkland'den Melihland'e olan tüm geçişler tercih edilebilir olsun. Başka bir deyişle Tarıkland'den Melihland'e geçerken kullanılan şehir ne olursa olsun 1. şehrin Tarıkland bölgesinden N. şehrin Melihland bölgesine giden en düşük ücret hepsinde eşit olmalıdır.
Bilge Utku'ın belirleyebileceği minimum geçiş ücretlerin toplamını bulunuz.

Not: Herhangi bir şehirden diğer tüm şehirlere doğrudan olmasa bile ulaşım vardır fakat Melihland'den Tarıkland'e geçiş yoktur.
Özel Not:
Şehirler T ve M diye iki kısımdan oluşuyor.
Bir T bölgesinden, bir M bölgesine tüm olası yol ücretlerinin eşit ve en az olduğu durumda;
Tüm şehirlerdeki T tarafından M tarafına geçiş ücretlerinin toplamını soruyor.
Şehirlerde T'den M'e tek yönlü geçiş olabiliyor. M'den T'ye geçilemiyor.
Bir şehirdeki T ile başka bir şehirdeki T iki yönlü bağlı olabilir. M de aynı şekilde.
Bağlantılardan da geçiş ücretli.

Girdi Biçimi
İlk satırda:
N, T, M; Utkuland'deki şehir sayısı, Tarıkland'deki yol sayısı, Melihland'deki yol sayısı
Sonraki T satırda:
i. satır Vi, Ui, Wi; Tarıkland'de Vi şehrinden Ui şehrine Wi ücretinde çift yönlü yol vardır.
Sonraki M satırda:
j. satır Vj , Uj , Wj; Melihland'de Vj şehrinden Uj şehrine Wj ücretinde çift yönlü yol vardır.

Çıktı Biçimi
Tek satırda:
1'den N'ye tüm i'ler için i. şehirdeki Tarıkland'den Melihland'e minimum geçiş ücretlerinin toplamı

Limitler
1 ≤ N ≤ 5 * 10e4
N − 1 ≤ T, M ≤ N * (N − 1) / 2
T + M ≤ 2 * 10e5
1 ≤ Vi, Vj, Ui, Uj ≤ N (Vi != Ui) (Vj != Uj) 1 ≤ Wi, Wj ≤ 10e6

Girdi 1
322 121 132 123 232

Çıktı 1
5

Örnek 1 Açıklaması
1. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 0
2. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 2
3. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 3
Tarıkland'den Melihland'e geçmek için tüm geçişler kullanılabilir. Cevap: 0 + 2 + 3 = 5

Girdi 2
466 123 131 144 231 245 349 122 136 145 233 245 348

Çıktı 2
11

Örnek 2 Açıklaması
1. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 4
2. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 2
3. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 0
4. şehirdeki Tarıkland'den Melihland'e geçiş ücreti = 5
Olarak seçilirse tüm olası güzergahlar:
• Geçiş olarak 1. şehir kullanılırsa: 1 – Melihland'e geç – 1 – 4 (4 + 5 = 9)
• Geçiş olarak 2. şehir kullanılırsa: 1 – 3 – 2 – Melihland'e geç – 2 – 4 (1 + 1 + 2 + 5 = 9)
• Geçiş olarak 3. şehir kullanılırsa: 1 – 3 – Melihland'e geç – 3 – 2 – 4 (1 + 0 + 3 + 5 = 9)
• Geçiş olarak 4. şehir kullanılırsa: 1 – 4 – Melihland'e geç – 4 (4 + 5 = 9)
Tarıkland'den Melihland'e geçmek için tüm geçişler kullanılabilir. Cevap: 4 + 2 + 0 + 5 = 11.
(Eğer 1. şehirdeki Tarıkland'den Melihland'e olan geçiş 3 ücretinde olsaydı herkes bu geçişi tercih edecekti ve diğer geçişler tercih edilmeyecekti ya da eğer 5 ücretinde olsaydı kimse bu geçişi tercih etmeyecekti.)

Altgörevler
Altgörev 1 (10 puan): 1 ≤ N ≤ 400
Altgörev 2 (10 puan): 1 ≤ N ≤ 2000
Altgörev 3 (20 puan): T = M = N − 1 (Tarıkland ve Melihland ağaç şeklindedir.)
Altgörev 4 (20 puan): Wi = Wj = 1 (tüm ücretler 1'e eşittir.)
Altgörev 5 (40 puan): Ek kısıtlama yoktur.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}