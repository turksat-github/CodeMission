#include <stdio.h>
#include <stdlib.h>// bu kütüphaneyi de ekleyelim (NULL ve EXIT_SUCCESS için gerekli)
#include <string.h>// strcpy fonksiyonu için lazım

struct z {
    char a [10];
    char b [10];
    int c;
    char * d;
};

int main (int argc, char ** argv) {
    struct z * p;
    char * input = NULL;
    size_t size = 0;
    int ch;

    // struct z için bellekte 10 tanelik yer açalım
    p = (struct z *) calloc (10, sizeof (struct z));
    if (p == NULL) {// bellekte yer açarken bir sorun oldu mu? olduysa hata ver ve çık
        printf ("Memory allocation failed.\n");
        return 1;
    }

    input = (char *) calloc (1, sizeof (char));
    if (input == NULL) {
        printf ("Memory allocation failed.\n");
        free (p);
        return 1;
    }

    printf ("Please enter student name: ");

    while ((ch = getchar ()) != '\n' && ch != EOF) {
        char * temp = realloc (input, size + 2);
        if (temp == NULL) {
            printf ("Memory reallocation failed.\n");
            free (input);
            free (p);
            return 1;
        }
        input = temp;
        input [size] = (char) ch;// Corrected: Increment after assignment
        input [++ size] = '\0';// Proper null-termination
    }

    // struct pointer değişkenimizin içindeki pointer değişkeni için bellekte yer açalım
    (p + 7) -> d = (char *) calloc (size + 1, sizeof (char));// başında asterisk yok. Dikkat edelim.
    if ((p + 7) -> d == NULL) {// ! işareti olumsuzluk anlamındadır.
        printf ("Memory allocation failed for string.\n");
        free (input);
        free (p);
        return 1;
    }

    strcpy ((p + 7) -> d, input); // verilen yazı, belirtilen char * değişkenine yazılır

    printf ("Adınızı giriniz (max 9 karakter):\n");
    scanf ("%9s", (p + 7) -> a); // Taşmayı önlemek için 9 karakter ile sınırlandırıldı

    printf ("Soyadınızı giriniz (max 9 karakter):\n");
    scanf ("%9s", (p + 7) -> b); // Taşmayı önlemek için 9 karakter ile sınırlandırıldı

    printf ("Numaranızı giriniz:\n");
    scanf ("%d", & ((p + 7) -> c)); // c değeri için ampersand kullanmayı unutma &(...)

    printf ("Öğrencimizin adı: %s\n", (p + 7) -> a);
    printf ("Öğrencimizin soyadı: %s\n", (p + 7) -> b);
    printf ("Öğrencimizin numarası: %d\n", (p + 7) -> c);
    printf ("Şu öğrenci için yazdırılmıştır: %s\n", (p + 7) -> d);

    // Belleği boşaltalım
    free (input);
    free ((p + 7) -> d);
    free (p);

    return EXIT_SUCCESS;
}
