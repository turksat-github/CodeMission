/*
SUNUCU ETKİLEŞİMİ

Zaman kısıtı: 1 sn
Hafıza kısıtı: 64 MB

Bir şehirde, altyapı ağını sürdürmek için hayati önem taşıyan N adet bilgisayar sunucu bulunmaktadır. Şehirdeki bilgisayar sunucuları, hızlı güncellemeleri paylaşmak için bir iletişim sistemi kurmak istemektedir.
Her bir sunucu, iletileri belirli bir yarıçapa kadar iletebilen bir iletişim modülüne sahiptir. İletim yarıçapı, R olarak gösterilir ve bir sunucunun iletim mesajının ulaşabileceği maksimum mesafeyi belirler. Ancak, donanım ve teknolojideki farklılıklar nedeniyle iletim yetenekleri tüm sunucular arasında aynı değildir.
Sunucular, birbirlerine mesajları iletme yeteneği sayesinde iletişim kurabilir, böylece doğrudan iletişim kurma zorunluluğu olmadan sunucular birbirleriyle haberleşebilir. Örnek olarak A sunucu B sunucu ile doğrudan iletişim kuramasa bile eğer A mesajını başka bir C sunucuya ve C'de B'ye gönderebilirse o zaman A sunucu B sunucu ile iletişim kurabilir.
Bu kurulum göz önüne alındığında, sunucular iletişim sistemlerini optimize etmek istiyor. Bu amaçla, tek bir sunucudan iletilen bir mesajla ulaşılabilecek maksimum sunucu sayısını belirlemek istiyorlar. Daha açık olarak, sizden N tane sunucudan hangisinden ulaşılabilecek maksimum sunucu sayısı en fazla ise o sayıyı bulmanız istenmektedir.
Her bir sunucunun iletim mesafesinin (R) tamsayı olacağını ve sunucuların, birden çok iletim yolunu kullanarak mesajları birbirlerine iletebileceklerini göz önüne alın.

Girdi Formatı
Girdinin ilk satırında sunucu sayısı (N) vardır.
Takip eden N satırda, her bir sunucunun tam sayı x ve y koordinatı ile bu sunucunun iletim mesafesi (R) vardır.

Çıktı Formatı
Tek bir sunucudan yapılan mesajın ulaşabileceği maksimum sunucu sayısını içeren tek bir çıktı satırı yazın. Bu sayıya mesajın ilk gönderileceği sunucu da dahildir.

Limitler
● 1 ≤ 𝑁 ≤ 200
● 1 ≤ 𝑥, 𝑦 ≤ 200 (x, y sunucuların koordinatlarıdır).

Alt Görevler
Alt Görev 1 (14 Puan)
● 1 ≤ 𝑁 ≤ 50
Alt Görev 2 (37 Puan)
● 1 ≤ 𝑁 ≤ 100
Alt Görev 3 (49 Puan)
● Ek kısıt yoktur.

Örnek Girdi
6
6 1 2
9 3 1
5 4 2
1 5 5
10 9 1
3 2 1

Örnek Çıktı
3

Örnek Açıklaması
4. sunucudan gönderilen mesaj toplam 3 sunucuya ulaşmaktadır (Bu sayıya 4. sunucu dahildir).
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}