#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv, char ** envp) {
    int i, j, rSize = 5, * cSize;
    cSize = (int *) calloc (rSize, sizeof (int));
    * (cSize + 0) = 3;
    * (cSize + 1) = 2;
    * (cSize + 2) = 1;
    * (cSize + 3) = 4;
    * (cSize + 4) = 4;
    int ** a = (int **) calloc (rSize, sizeof (int *));
    for (i = 0; i < rSize; ++ i) {
        * (a + i) = (int *) calloc (* (cSize + i), sizeof (int));
    }
    * (* (a + 0) + 0) = 11;
    * (* (a + 0) + 1) = 12;
    * (* (a + 0) + 2) = 13;
    * (* (a + 1) + 0) = 21;
    * (* (a + 1) + 1) = 22;
    * (* (a + 2) + 0) = 31;
    * (* (a + 3) + 0) = 41;
    * (* (a + 3) + 1) = 42;
    * (* (a + 3) + 2) = 43;
    * (* (a + 3) + 3) = 44;
    * (* (a + 4) + 0) = 51;
    * (* (a + 4) + 1) = 52;
    * (* (a + 4) + 2) = 53;
    * (* (a + 4) + 3) = 54;
    for (i = 0; i < rSize; ++ i) {
        for (j = 0; j < * (cSize + i); ++ j) {
            printf ("%d ", * (* (a + i) + j));
        }
        printf ("\n");
    }
    for (i = 0; i < rSize; ++ i) {
        free (* (a + i));
    }
    free (a);
    return EXIT_SUCCESS;
}
/*
** a = {[11, 12, 13], [21, 22], [31], [41, 42, 43, 44], [51, 52, 53, 54]}
rSize = 5
* cSize = {3, 2, 1, 4, 4}

int points [] [4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 11, 12}};
int (* ptr) [c] = points;
*/
