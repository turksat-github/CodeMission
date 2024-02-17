// C Program to show allocation of data items
// in multidimensional array

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp) {
    // Declaring the dimension of 2-Dimension array
    int row = 2;
    int col = 5;

    // Creating an array arr with size row * col
    int *arr = (int *)malloc (row * col * sizeof (int));
    int k = 0;

    // Inserting values in the array
    for (int i = 0; i < row; ++ i) {
        for (int j = 0; j < col; ++ j) {
            // The memory address of arr [i] [j]
            // is equal to (arr + i * col + j)
            *(arr + i * col + j) = k;
            ++ k;
        }
    }

    // Printing the multidimensional array
    for (int i = 0; i < row; ++ i) {
        for (int j = 0; j < col; ++ j) {
            printf ("%d ", *(arr + i * col + j));
        }
        printf ("\n");
    }
    return EXIT_SUCCESS;
}