#include <stdio.h>
#include <stdlib.h>

int numSpecial (int **, int, int *);

int main (int argc, char **argv, char **envp) {
    int colSize [] = {3, 3, 3};
    int **thePtr;
    thePtr = malloc (sizeof (int *) * 3/*rows*/);
    thePtr [0] = malloc (sizeof (int) * 3/*cols*/);
    thePtr [1] = malloc (sizeof (int) * 3/*cols*/);
    thePtr [2] = malloc (sizeof (int) * 3/*cols*/);
    thePtr [0] [0] = 1;
    thePtr [0] [1] = 0;
    thePtr [0] [2] = 0;
    thePtr [1] [0] = 0;
    thePtr [1] [1] = 0;
    thePtr [1] [2] = 1;
    thePtr [2] [0] = 1;
    thePtr [2] [1] = 0;
    thePtr [2] [2] = 0;
    printf ("%d", numSpecial (thePtr, 3, colSize));
    return EXIT_SUCCESS;
}

int numSpecial (int **mat, int matSize, int *matColSize) {
    int i, j, result = 0, temp = 0;
    for (i = 0; i < matSize; ++ i) {
        for (j = 0; j < *(matColSize + i); ++ j) {
            //printf("%d ", *((int *)mat + i * cols + j));
            //printf ("%d\t", *(*(mat + i) + j));
            if (*(*(mat + i) + j) == 1) {
                temp = 0;
                for (int k = 0; k < matSize; ++ k) {
                    if ((k != i) && (*(*(mat + k) + j) == 1)) {
                        temp = 1;
                        break;
                    }
                }
                for (int k = 0; k < *(matColSize + i); ++ k) {
                    if ((k != j) && (*(*(mat + i) + k) == 1)) {
                        temp = 1;
                        break;
                    }
                }
                if (temp == 0) {
                    result += 1;
                }
            }
        }
        //printf ("\n");
    }
    return result;
}