#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp) {
  int i, j, count, r = 5, c = 2;
  int **mat = (int **) malloc (r * sizeof (int *));
  for (i = 0; i < r; ++ i) {
    mat [i] = (int *) malloc (c * sizeof (int));
  }
  count = 0;
  for (i = 0; i < r; ++ i) {
    for (j = 0; j < c; ++ j) {
      mat [i] [j] = ++ count; //OR *(*(arr + i) + j) = ++ count
    }
  }

  for (i = 0; i < r; ++ i) {
    for (j = 0; j < c; ++ j) {
      printf ("%d ", mat [i] [j]); //printf ("%d", *(*(mat + 2) + 0));
    }
    printf ("\n");
  }

  //Code for further processing and free the dynamically allocated memory
  for (i = 0; i < r; ++ i) {
    free (mat [i]);
  }
  free (mat);

  return EXIT_SUCCESS;
}
/*
[[1, 2, 3], [4, 5], [6], [7, 8, 9, 10], [11, 12, 13, 14]]
**mat = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
matSize = 5
*matColSize = {3, 2, 1, 4, 4}
*/