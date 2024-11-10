/*
KOLYE

Başak'ın çeşitli renklerde boncukları olan iki adet kolyesi bulunmaktadır. Bu kolyeler N adet boncuk içermekle beraber her iki kolyenin boncuklarının renkleri 1 ile N arasındadır.
Başak kolyeleri ile oyunlar oynamayı çok sevmektedir. Yine bir gün kolyeleri ile oynarken aklına ilginç bir fikir gelir. Öncelikle her iki kolyenin kilidini açarak iki şerit haline getirir. Ardından iki kolyeyi de masasının üstüne her iki ucu birbirinin tam olarak altında olacak şekilde yerleştirir. Bu işlemleri yaptıktan sonra kolyelerine A ve B isimlerini verir ve artık A[i] yukarıdaki kolyenin soldan i. boncuğunu, B[i] ise aşağıdaki kolyenin soldan i. boncuğunu ifade eder.
Bu isimlendirmeleri de yapınca artık oyun vakti gelmiştir. Başak 1 ≤ l ≤ r ≤ n şartını sağlayan tüm l − r ikilileri için olası tüm c renklerinin sayısını hesaplamak ister öyle ki her l ≤ i ≤ r için A[i] = c veya B[i] = c olsun. Bu hesaplamalar sonrasında da bu l − r ikilileri için hesaplanan tüm değerleri toplamak ister. Fakat Başak her ne kadar azimli biri de olsa bu hesaplamaların çok vakit alacağını düşünür ve sizden bu hesaplamaları yapmanızı ister.

Girdi Biçimi
İlk satırda kolyelerdeki boncukların sayısını temsil eden N değeri verilecektir.
Takip eden iki satırda ise N uzunluğunda olan A ve B kolyelerinin boncuk dizilimleri verilecektir.

Çıktı Biçimi
Belirtilen tüm l − r ikilileri için hesaplanan değerlerin toplamını yazdırmalısınız.

Limitler
1 ≤ N ≤ 2 * 10e5
Her 1 ≤ i ≤ N için 1 ≤ A[i], B[i] ≤ N

Örnek Girdi
Aşağıdaki girdi için:
4
1 3 2 2
3 3 4 2

Doğru çıktı aşağıdaki gibidir:
8

Örnek Girdi Açıklaması
Tüm l − r ikilileri için olası c renklerini gösterelim:
• l = 1, r = 1 için c = 1, 3
• l = 2, r = 2 için c = 3
• l = 3, r = 3 için c = 2, 4
• l = 4, r = 4 için c = 2
• l = 1, r = 2 için c = 3
• l = 3, r = 4 için c = 2
Tüm değerler toplanınca, 2 + 1 + 2 + 1 + 1 + 1 = 8 bulunmaktadır.

Altgörevler
Altgörev 1 (10 puan): 1 ≤ N ≤ 400
Altgörev 2 (12 puan): 1 ≤ N ≤ 8000
Altgörev 3 (5 puan): 1 ≤ i ≤ N için A[i] = i ve B[i] = N − i + 1
Altgörev 4 (7 puan): A ve B kolyelerindeki boncukların renkleri 1'den N'e kadar olan sayıların bir permütasyonudur.
Altgörev 5 (10 puan): B kolyesindeki tüm boncuklar aynı renktedir.
Altgörev 6 (10 puan): A kolyesinde bulunan farklı renkteki boncukların sayısı en fazla 300'dür.
Altgörev 7 (46 puan): Herhangi bir kısıtlama bulunmamaktadır.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}
