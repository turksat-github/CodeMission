/*
PAPATYA NEREDE?

Zaman kısıtı: 1 sn
Hafıza kısıtı: 64 MB

Yağmur ve Begüm sıkıcı bir günü renklendirmek amacıyla kendi tasarladıkları “Papatya Nerede?” adlı eğlenceli bir oyun oynar. Oyun şu şekildedir: Yağmur elinde bulunan 3 tane içi görünmez kutunun birinin içine papatya, birine gül ve diğerine menekşe koyar ve kutuları kapatır. Begüm bu çiçeklerin hangi kutuların içinde olduğunu bilmez. Yağmur daha sonra her hamlesinde bu kutulardan iki tanesinin yerini değiştirir ve Begüm'e papatya nerede diye sorar. Begüm bir tahminde bulunur. Yani Begüm tahmininde papatyanın 1, 2 ya da 3 numaralı yerde bulunan kutuların içinde olup olmadığını söyler. Yağmur oyunda toplam N tane hamle yapar ve her hamlede iki kutunun yerini değiştirerek Begüm'ün tahminini sorar.
Yağmur'un her hamlesinde hangi iki kutunun değiştiği ve Begüm'ün tahminleri verildiğinde ancak papatyanın ilk nerede olduğu verilmediğinde, sizden Begüm'ün kazanabileceği mümkün olan en yüksek puanı belirlemeniz istenmektedir. Begüm doğru bildiği her tahmini için 1 puan alır.

Girdi Formatı
Girdinin ilk satırında kutu çiftlerinin değişim sayısı (N) vardır.
Sonraki N satırının her biri oyunun bir hamlesini tanımlayan x, y ve z tam sayılarını içerir. İlk iki tam sayı (x ve y) yerleri değişen iki kutunun pozisyonlarını gösterir. Üçüncü tam sayı (z) ise Begüm'ün tahminidir.

Çıktı Formatı
Çıktı tek bir tam sayı içerecektir. Bu Begüm'ün alabileceği en yüksek puandır.

Limitler
● 1 ≤ 𝑁 ≤ 100
● 1 ≤ 𝑥, 𝑦, 𝑧 ≤ 3
● 𝑥 ≠ 𝑦

Alt Görevler
Alt Görev 1 (15 Puan)
● 𝑁 ≤ 20
Alt Görev 2 (22 Puan)
● 𝑁 ≤ 50
Alt Görev 3 (63 Puan)
● Ek kısıt yoktur.

Örnek Girdi
4
1 2 1
3 2 1
1 3 1
2 3 3

Örnek Çıktı
2

Örnek Açıklaması
Bu örnekte Begüm en fazla 2 puan kazanabilir. Eğer papatya ilk durumda 1. konumdaki kutunun içinde ise, o zaman Begüm bir kez doğru tahminde bulunur (üçüncü tahmini). Eğer papatya ilk durumda 2. konumdaki kutunun içinde ise, o zaman iki kez doğru tahminde bulunur (ilk iki tahmini). Eğer papatya ilk durumda 3. konumdaki kutunun içinde ise Begüm bir kez doğru tahminde bulunur (son tahmini).
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    
    return EXIT_SUCCESS;
}