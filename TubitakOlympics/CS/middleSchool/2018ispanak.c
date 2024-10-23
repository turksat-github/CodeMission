/*
ISPANAK

TÜBİTAK adasında N tane öğrenci yaşamaktadır. Artık soru çözmekten sıkılan öğrenciler bir oyun oynamaya karar verirler. Öğrenciler bir çember etrafına dizilip her koltuğa 1'den başlayarak numara verilir (saat yönünde).
Oyun 1. sırada oturan kişinin ıspanak yemeye gönderilmesiyle başlar. Ondan sonraki ıspanak yemeye gönderilecek kişi ise son gönderilen kişiden iki sonraki öğrencidir (saat yönünde ve ıspanak yemeye gönderilen öğrenciler sayılmıyor). Bahadır ıspanaktan nefret ediyor, o yüzden ıspanak yemek zorunda kalmamak için kaçıncı sıradaki koltuğa oturması gerektiğini size soruyor.

Girdi Biçimi:
İlk satırda bir adet tam sayı N verilecektir. Bu sayı adadaki öğrenci sayısıdır.

Çıktı Biçimi:
Oyun başında Buğdayın ıspanak yemek zorunda kalmaması için oturması gereken koltuğun numarası

Sınırlar:
1 ≤ N ≤ 10e9
Alt Görev 1 (10 puan):
1 ≤ N ≤ 10
Alt Görev 2 (20 puan):
1 ≤ N ≤ 100
Alt Görev 3 (40 puan):
1 ≤ N ≤ 100000
Alt Görev 4 (30 puan):
Hiçbir ek kısıtlama yok.

Örnek Girdi 1:
4

Örnek Çıktı 1:
4

Açıklama 1
İlk turda 1. koltukta oturan kişi ıspanak yemeye gönderiliyor. Ardından ondan iki sonraki yani 3. koltukta
oturan ıspanak yemeye gönderiliyor. Geriye 4 numaralı koltuktaki öğrenci ve 2 numaralı koltuktaki öğrenci
kalıyor. En son turda da 2 numaralı koltuktaki öğrenci ıspanak yemeye gönderiliyor.
Sonuç olarak eğer Bahadır oyun başlamadan 4 numaralı koltuğa oturursa ıspanak yemek zorunda kalmaz.

Örnek Girdi 2:
11

Örnek Çıktı 2:
6

Açıklama 2
İlk turda 1. koltuktaki öğrenci ıspanak yemeye gönderiliyor. Sonraki turda 3. koltuktaki,
ondan sonraki turda 5. koltuktaki, ondan sonraki turda 7. koltuktaki, sonraki turda 9. turdaki, sonraki turda
11. koltuktaki, sonraki turda 4. koltuktaki, sonraki turda 8. koltuktaki öğrenci, sonraki turda 2. koltuktaki,
en son turda da 10. koltuktaki öğrenci ıspanak yemek zorunda kalıyor.
Bahadır 6 numaralı koltuğa oturmalı ki ıspanak yemek zorunda kalmasın.
*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * (* argv), char * (* envp)) {
    int a, b = 0, c, d = 0, f;//a koltuk sayısı, b sonuncu koltuk, c'yi b'ye atamak için geçici, d heryer doldu mu diye sayıcı
    scanf ("%d%*c", &a);
    int *e;//koltuklar, başlangıçta içlerinde 0 var. O demek birisi oturuyor demek.
    e = (int *) calloc (a, sizeof (int));
    while (d < a) {//dolu koltuk sayısı sınırdan küçük olduğu sürece
        *(e + b) = 1;//buraya her geldiğinde b doğru yerdeki koltuğu gösterir.
        c = b;//sonuncu koltuğun ne olduğunu hatırlamak için
        for (f = 0; f < 2; ++ f) {//iki anlamlı koltuk ilerlemek için döngü
            ++ b;//sıradaki koltuk
            b %= a;//sıralı listeyi döner yapıya dönüştürüyoruz
            if (*(e + b) == 1) {//baktığımız koltuk boş ise
                -- f;//bu sayılmaz diyoruz
                ++ d;//kaç defa başarısızlıkla ilerlediğimiz burada artıyor
                if (d == a) {//başarısız saymalar sınıra ulaştı mı?
                    break;//başarısız ilerlemeler sınır sayıya ulaştıysa ilerleme döngüsünden çıkalım
                }
            }
            else {//baktığımız koltuk dolu ise
                d = 0;//başarısızlık sayacını sıfırlayalım
            }
        }
        /*for (int f = 0; f < a; ++ f) {
            printf ("%d ", *(e + f));
        }
        printf ("\n");*/
    }
    printf ("%d", c + 1);//soruda ilk sıra 1'den başlıyor, 0'dan değil
    free (e);
    return EXIT_SUCCESS;
}