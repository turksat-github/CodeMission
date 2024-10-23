/*
KAHVECİ AHMET EFENDİ

Zaman kısıtı: 1 sn
Memory kısıtı: 64 MB

Kahveci Ahmet Efendi çok cimri biridir. Kahve dükkanında neyden ne kadar kısacağına şaşıran Ahmet Efendi, şimdi de kafayı elektrikli kahve makinasına takmıştır. Çok elektrik tüketmesin diye kahve makinasını, kahve hazırlamadığı zamanlarda kapatmaya karar vermiştir. Bir sipariş geldiği zaman, Ahmet Efendi makinayı açıp kahve hazırlayıp makinayı kapatmaktadır.
Ahmet Efendi, N tane kahve siparişi almaktadır. i. (1 ≤ 𝑖 ≤ 𝑁) kahve siparişini 𝑇(𝑖) zamanında alıp 𝑇(𝑖 + 1) zamanında teslim etmektedir. Herhangi bir zamanda Ahmet Efendi en fazla bir sipariş almaktadır.
Bununla birlikte Ahmet Efendi makinayı bu kadar fazla aç kapa yapmanın makinayı bozmasından da korkmaktadır. Bu nedenle, en fazla K defa makinayı açıp kapatmaya karar verir.
Kahve makinası açık olduğu sürece elektrik tüketmektedir. Ahmet Efendi'nin bütün siparişleri karşılayacak şekilde kahve makinasını en az ne kadar süre çalıştırması gerektiğini bulunuz.

Girdi:
Girdinin ilk satırda 2 tamsayı verilmektedir: N ve K
Takip eden N satırdan i. (1 ≤ 𝑖 ≤ 𝑁) satırda i. siparişin geldiği 𝑇(𝑖) zamanı tamsayı olarak verilmektedir.

Çıktı:
Ahmet Efendi'nin kahve makinasını en az ne kadar süre çalıştırması gerektiğini yazdırınız.

Kısıtlar
● 1 ≤ 𝑁 ≤ 100.000
● 1 ≤ 𝐾 ≤ 𝑁
● 1 ≤ 𝑇𝑖 ≤ 1.000.000.000 (1 ≤ 𝑖 ≤ 𝑁)
● 𝑇𝑖 < 𝑇(𝑖 + 1) (1 ≤ 𝑖 ≤ 𝑁 − 1)

Alt Görevler
Alt Görev 1 [20 puan]
𝑁 ≤ 20
1 ≤ 𝑇𝑖 ≤ 20 (1 ≤ 𝑖 ≤ 𝑁)
Alt Görev 2 [30 puan]
𝑁 ≤ 5000
Alt Görev 3 [50 puan]
Ek kısıt yoktur.

Örnek Girdi 1
3 2
1
4
7

Örnek Çıktı 1
5

Açıklama:
Bu örnekte Ahmet Efendi 3 sipariş almaktadır. En fazla 2 defa aç kapat yapacak şekilde bütün siparişleri hazırlayabilmesi için Ahmet Efendi'nin en az 5 süre boyunca makinayı çalıştırması gerekmektedir.
Birinci aç kapa için:
Birinci siparişin geldiği 1 zamanında makinayı açıyor.
İkinci siparişin teslim edildiği 5 zamanında makinayı kapatıyor.
İkinci aç kapa için:
Üçüncü siparişin geldiği 7 zamanında makinayı açıyor.
Üçüncü siparişin teslim edildiği 8 zamanında makinayı kapatıyor.
(5 − 1) + (8 − 7) = 5.

Örnek Girdi 2
3 1
1
4
7

Örnek Çıktı 2
7

Açıklama:
Ahmet Efendi en fazla 1 defa aç kapat yapabileceği için makinayı, 1 zamanında açıp 8 zamanında kapatması gerekmektedir. En az 7 süre boyunca makinayı çalıştırması gerekmektedir.

Örnek Girdi 3
3 3
1
4
7

Örnek Çıktı 3
3

Açıklama:
Ahmet Efendi en fazla 3 defa aç kapat yapabileceği için her siparişte makinayı aç kapat yapabilir. Bu nedenle, en az 3 süre boyunca makinayı çalıştırması gerekmektedir.

Örnek Girdi 4
10 5
1
2
5
6
8
11
13
15
16
20

Örnek Çıktı 4
12
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}