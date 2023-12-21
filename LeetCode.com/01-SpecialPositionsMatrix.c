int numSpecial (int **mat, int matSize, int *matColSize) {
    int i, j, result;
    for (i = 0; i < matSize; ++ i) {
        for (j = 0; j < *(matColSize + i); ++ j) {
            printf ("%d\t", *(*(mat + i) + j));
        }
        printf ("\n");
    }
    return 0;
}