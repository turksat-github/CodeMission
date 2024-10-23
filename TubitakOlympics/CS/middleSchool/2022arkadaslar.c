/*
ARKADAŞLAR

Zaman Sınırı: 3 saniye 
Hafıza Sınırı: 1024 MB 

Soru Metni
Olimpiya şehri çok büyük ve ilginç bir şehirdir. Bu şehirde yollar Kuzey-Güney veya Doğu-Batı yönünde sonsuza kadar uzanan doğrular şeklindedir. Kuzey-Güney yönünde N adet, Doğu-Batı yönünde M adet yol bulunmaktadır. Kuzey-Güney yönünde uzanan yollar x = ai (1 ≤ i ≤ N) doğruları şeklinde, Doğu-Batı yönünde uzanan yollar y = bj (1 ≤ j ≤ M) doğruları şeklinde gösterilmektedir.
Örneğin x = 3 ve y = 2 yolları için Olimpiya şehri aşağıdaki gibidir:
            N    x=3
            ┊     ╬
            ┊     ╬
            ┊     ╬
            ┊     ╬
  ╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬ y=2
            ┊     ╬ 
W┈┈┈┈┈┈┈┈┈┈┈┼┈┈┈┈─╬┈┈┈┈ E
            ┊     ╬
            ┊     ╬
            ┊     ╬
            ┊ 
            S
Bu N + M tane yollardan K tanesinin üzerinde evi bulunan birbiriyle arkadaş K kişi bulunmaktadır. Bu arkadaşlardan k'inci (1 ≤ k ≤ K) arkadaşın evinin konumu (pk, qk) şeklide gösterilmektedir. Olimpiya şehrindeki her bir yol doğrusuna ait en fazla bir kişinin evi bulunmaktadır. Bazı yolların üzerinde hiç ev bulunmuyor olabilir. Örneğin; x = 3 yolu üzerinde evi (3, −2) noktasında bulunan ve y = 2 yolu üzerinde evi (−4, 2) noktasında bulunan iki arkadaşın bulunduğu Olimpiya şehri aşağıdaki gibidir:
            N    x=3
            ┊     ╬
            ┊     ╬
            ┊     ╬
            ┊     ╬
 ═╬═◆═╬═╬═╬═╬═╬═╬═╬═╬═╬═y=2
            ┊     ╬
W┈┈┈┈┈┈┈┈┈┈┈┼┈┈┈┈┈╬┈┈┈┈ E
            ┊     ╬
            ┊     ◆
            ┊     ╬
            ┊ 
            S
Olimpiya şehrinde yaşayan bu arkadaşlar olimpiyat çalışmak için sık sık birbirlerinin evlerinde buluşmaktadır. Bu buluşmalarda arkadaşlar evleri arasındaki en kısa yolu kullanmaktadır. Örneğin yukarıdaki iki arkadaş birbirlerinin evinde buluşabilmek için gitmeleri gereken en kısa yol mesafesi 11 birimdir:
◆(-4, 2) ile ◆(3, -2) arasında yatay ve dikey yönleri kullanılarak ve aynı zamanda verilen yollardan gidildiğinde 11 birim mesafe vardır.

Bu soruda sizden K arkadaşın evleri arasında bulunan bütün alt ikililer için toplam en kısa mesafeyi hesaplamanız istenmektedir.
Örneğin; N = 2 ve M = 2 yol bulunan, K = 3 tane arkadaşın evinin bulunduğu Olimpiya şehri için
   x=-4     N    x=3
    ╬       ┊     ╬
    ╬       ┊     ╬
    ╬       ┊     ╬
    ╬       ┊     ╬
    ◆═╬═╬═╬═╬═╬═╬═╬═╬═╬═ y=2
    ╬       ┊     ╬  
W┈┈┈╬┈┈┈┈┈┈┈┿┈┈┈┈┈╬┈┈┈┈┈ E
    ◆       ┊     ╬
    ╬       ┊     ◆
    ╬       ┊     ╬ 
╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═ y=-4
            ┊
            S
y = 2 ve x = -4 yollarında evi bulunan arkadaşların evleri arasındaki en kısa mesafe 3 birimdir.
y = 2 ve x = 3 yollarında evi bulunan arkadaşların evleri arasındaki en kısa mesafe 11 birimdir.
x = -4 ve x = 3 yollarında evi bulunan arkadaşların evleri arasındaki en kısa mesafe 12 birimdir.
Bütün ikililer için toplam en kısa mesafe 3 + 11 + 12 = 26 birimdir. 

Not: Yukarıdaki örnekte evlerinin x koordinatı -4 olan iki arkadaş bulunmaktadır. Ancak evi (-4, 2) koordinatlarında olan y = 2 doğrusunda, evi (-4, -1) koordinatlarında olan da x = -4 doğrusunda bulunan ev olduğu için her bir yol doğrusuna ait en fazla bir ev bulunmaktadır şartını bozmamaktadır.

Kısıtlamalar
• Verilen tüm sayılar tam sayıdır.
• 1 ≤ N ≤ 100.000
• 1 ≤ M ≤ 100.000
• 2 ≤ K ≤ N + M
• −100.000 ≤ ai ≤ 100.000 (1 ≤ i ≤ N)
• −100.000 ≤ bj ≤ 100.000 (1 ≤ j ≤ M)
• −100.000 ≤ pk, qk ≤ 100.000 (1 ≤ k ≤ K)
• Aynı yerde birden fazla yol veya ev bulunmamaktadır. Diğer bir değişle;
  o a1, a2, · · ·, aN sayıları birbirinden farklıdır.
  o b1, b2, · · ·, bM sayıları birbirinden farklıdır.
  o (p1, q1), (p2, q2), · · ·, (pK, qK) ikilileri birbirinden farklıdır. 
• Aynı yola ait birden fazla ev bulunmamaktadır.

Alt Görevler
1. (14 puan) M = 1.
2. (11 puan) Tüm evler sadece kesişim noktalarında olabilmektedir.
3. (20 puan) 1 ≤ N, M ≤ 20.
4. (25 puan) 1 ≤ N, M ≤ 1 000.
5. (30 puan) Ek kısıtlama yok.

Girdi Formatı
• İlk satırda N, M ve K tam sayıları aralarında bir boşluk olacak şekilde verilmektedir.
• İkinci satırdan N tane a1, a2, · · ·, aN tam sayıları aralarında bir boşluk olacak şekilde verilmektedir.
• Üçüncü satırdan M tane b1, b2, · · ·, bM tam sayıları aralarında bir boşluk olacak şekilde verilmektedir.
• Sonraki K satırda, her bir satırda k'ıncı evin koordinatları (pk, qk) aralarında bir boşluk olacak şekilde verilmektedir.

Çıktı Formatı
• Tek satırda bütün ikililer için toplam en kısa mesafeyi yazdırınız.

Örnek Girdi 1
2 2 3
-4 3
2 -4
-4 2
-4 -1
3 -2

Örnek Çıktı 1
26

Örnek Girdi 2
2 3 5
-2 5
5 -3 2
-1 5
0 2
4 -3
5 4
-2 -2

Örnek Çıktı 2
88
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}