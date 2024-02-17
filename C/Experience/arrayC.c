#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp) {
    int row = 2;
    int col = 5;

    int *arr = (int *) malloc (row * col * sizeof (int));
    int k = 0;

    for (int i = 0; i < row; ++ i) {
        for (int j = 0; j < col; ++ j) {
            *(arr + i * col + j) = k;// arr [i] [j]
            ++ k;
        }
    }

    for (int i = 0; i < row; ++ i) {
        for (int j = 0; j < col; ++ j) {
            printf ("%d ", *(arr + i * col + j));// arr [i] [j]
        }
        printf ("\n");
    }

    //Code for further processing and free the dynamically allocated memory
    for (i = 0; i < row; ++ i) {
        free (arr [i]);
    }
    free (arr);

  return EXIT_SUCCESS;
}