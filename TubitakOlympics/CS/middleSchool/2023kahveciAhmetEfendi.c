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
int compare (const void * a, const void * b) {
    long long diff = * (long long *) b - * (long long *) a;
    return (diff > 0) ? 1 : ((diff < 0) ? - 1 : 0);
}
int main (int argc, char * (* argv), char * (* envp)) {
    int N, K;
    scanf ("%d %d", &N, &K);
    long long * T = (long long *) malloc (N * sizeof (long long));
    for (int i = 0; i < N; ++ i) {
        scanf ("%lld", &T [i]);
    }

    long long original_duration = (T [N - 1] + 1) - T [0];

    if (N == 1) {
        printf ("%lld\n", original_duration);
        free (T);
        return 0;
    }

    int num_gaps = N - 1;
    long long * gaps = (long long *) malloc (num_gaps * sizeof (long long));
    for (int i = 0; i < num_gaps; ++ i) {
        gaps [i] = T [i + 1] - T [i] - 1;
    }

    qsort (gaps, num_gaps, sizeof (long long), compare);

    int take = K - 1;
    if (take > num_gaps) {
        take = num_gaps;
    }

    long long sum_gaps = 0;
    for (int i = 0; i < take; ++ i) {
        sum_gaps += gaps [i];
    }

    long long result = original_duration - sum_gaps;
    printf ("%lld\n", result);

    free (T);
    free (gaps);
    return EXIT_SUCCESS;
}

/*
Explanation

1. Reading Input: The code reads the number of orders N and the maximum number of on/off cycles K, followed by the times at which each order is received.
2. Initial Duration Calculation: The initial duration is calculated as if all orders are processed in a single continuous session, from the first order's start time to the delivery time of the last order.
3. Gap Calculation: Gaps between consecutive orders are computed. These gaps represent the time the machine can be turned off between groups of orders.
4. Sorting Gaps: The gaps are sorted in descending order to prioritize the largest gaps, which are then used to split the orders into groups.
5. Summing Gaps: The sum of the largest K − 1 gaps is subtracted from the initial duration to get the minimum total running time required.

This approach ensures that the machine is used efficiently, minimizing the total running time while respecting the constraint on the number of on/off cycles.
*/
