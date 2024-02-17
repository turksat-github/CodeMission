#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp) {
    int i, j, count, r = 3, c = 4;
    //int (*arr) [col] = calloc (row, sizeof (*arr));
    int points [] [4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 11, 12}};
    //int arr [r] [c] = {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}};
    int (*ptr) [c] = points;
    printf ("%d\n", *(*(ptr + 2) + 3));

    int **matrix = (int **) malloc (r * sizeof (int *));
    for (i = 0; i < r; ++ i) {
        matrix [i] = (int *) malloc (c * sizeof (int));
    }

    //Code for further processing and free the dynamically allocated memory
    for (i = 0; i < r; ++ i) {
        free (matrix [i]);
    }
    free (matrix);
    return EXIT_SUCCESS;
}