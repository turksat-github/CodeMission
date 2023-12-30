#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix (int *matrix, int row, int column) {
    for (int i = 0; i < row; ++ i) {
        for (int j = 0; j < column; ++ j) {
            printf ("%d ", matrix [i * column + j]);
        }
        printf ("\n");
    }
}

void ravel (int *matrix, int *row_address, int *column_address) {
    for (int i = 0; i < (*row_address) * (*column_address); ++ i) {
        printf ("%d ", matrix [i]);
    }
    printf ("\n");
}

void reshape (int *row_address, int *column_address) {
    scanf (" %d %d", row_address, column_address);
}

void resize (int **matrix_address, int *row_address, int *column_address) {
    int first_size = (*row_address) * (*column_address);
    scanf (" %d %d", row_address, column_address);
    *matrix_address = (int *)realloc (*matrix_address, (*row_address) * (*column_address) * sizeof(int));
    for (int iterator = first_size; iterator < (*row_address) * (*column_address); iterator++) {
        (*matrix_address)[iterator] = (*matrix_address)[iterator % first_size];
    }
}

void append_row (int **matrix_address, int *row_address, int *column_address) {
    int row [*column_address];
    for (int k = 0; k < *column_address; ++ k) {
        scanf (" %d", &row [k]);
    }
    *matrix_address = (int *)realloc (*matrix_address, ((*row_address) + 1) * (*column_address) * sizeof (int));
    for (int j = 0; j < (*column_address); ++ j) {
        (*matrix_address)[(*row_address) * (*column_address) + j] = row [j];
    }
    ++ (*row_address);
}

void insert_row (int *matrix, int **matrix_address, int *row_address,    int *column_address) {
    int insert;
    scanf (" %d", &insert);
    int row [*column_address];
    for (int k = 0; k < *column_address; ++ k) {
        scanf (" %d", &row [k]);
    }
    *matrix_address = (int *)realloc (*matrix_address, ((*row_address) + 1) * (*column_address) * sizeof(int));
    for (int i = 0; i < insert; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[i * (*column_address) + j] = matrix [i * (*column_address) + j];
        }
    }
    for (int k = 0; k < *column_address; k++) {
        (*matrix_address)[insert * (*column_address) + k] = row [k];
    }
    for (int i = insert + 1; i < *row_address + 1; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[i * (*column_address) + j] = matrix [(i - 1) * (*column_address) + j];
        }
    }
    ++ (*row_address);
}

void append_column (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    int column [*row_address];
    for (int k = 0; k < *row_address; ++ k) {
        scanf(" %d", &column [k]);
    }
    *matrix_address = (int *)realloc (*matrix_address, (*row_address) * ((*column_address) + 1) * sizeof (int));
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[i * (*column_address + 1) + j] = matrix [i * (*column_address) + j];
        }
        (*matrix_address)[i * (*column_address + 1) + (*column_address)] = column [i];
    }
    ++ (*column_address);
}

void insert_column (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    int insert;
    scanf (" %d", &insert);
    int column [*row_address];
    for (int k = 0; k < *row_address; ++ k) {
        scanf (" %d", &column [k]);
    }
    *matrix_address = (int *)realloc (*matrix_address, (*row_address) * ((*column_address) + 1) * sizeof (int));
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = 0; j < insert; ++ j) {
            (*matrix_address)[i * (*column_address + 1) + j] = matrix [i * (*column_address) + j];
        }
        (*matrix_address)[i * (*column_address + 1) + insert] = column [i];
    }
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = insert + 1; j < *column_address + 1; ++ j) {
            (*matrix_address)[i * (*column_address + 1) + j] = matrix[i * (*column_address) + j - 1];
        }
    }
    ++ (*column_address);
}

void delete_row (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    int delete;
    scanf (" %d", &delete);
    for (int i = 0; i < delete; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[i * (*column_address) + j] = matrix [i * (*column_address) + j];
        }
    }
    for (int i = delete; i < *row_address - 1; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[i * (*column_address) + j] = matrix [(i + 1) * (*column_address) + j];
        }
    }
    *matrix_address = (int *)realloc (*matrix_address, (*row_address - 1) * (*column_address) * sizeof (int));
    -- (*row_address);
}

void delete_column (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    int delete;
    scanf (" %d", &delete);
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = 0; j < delete; ++ j) {
            (*matrix_address)[i * (*column_address - 1) + j] = matrix [i * (*column_address) + j];
        }
    }
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = delete; j < *column_address - 1; ++ j) {
            (*matrix_address)[i * ((*column_address) - 1) + j] = matrix [i * (*column_address) + j + 1];
        }
    }
    *matrix_address = (int *)realloc (*matrix_address, (*row_address) * (*column_address - 1) * sizeof (int));
    -- (*column_address);
}

void tile (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    int x, y;
    scanf (" %d %d", &x, &y);
    *matrix_address = (int *)realloc (*matrix_address, ((*row_address) * y) * ((*column_address) * x) * sizeof (int));
    for (int i = 0; i < (*row_address) * y; ++ i) {
        for (int j = 0; j < (*column_address) * x; ++ j) {
            (*matrix_address)[i * (*column_address * x) + j] = matrix [(i % (*row_address)) * (*column_address) + j % (*column_address)];
        }
    }
    (*row_address) *= y;
    (*column_address) *= x;
}

void transpose (int *matrix, int **matrix_address, int *row_address, int *column_address) {
    for (int i = 0; i < *row_address; ++ i) {
        for (int j = 0; j < *column_address; ++ j) {
            (*matrix_address)[j * (*row_address) + i] = matrix [i * (*column_address) + j];
        }
    }
    // swapping row and column
    int tmp = *row_address;
    *row_address = *column_address;
    *column_address = tmp;
}

int main (int argc, char **argv, char **envp) {
    int row, column;
    scanf ("%d %d", &row, &column);
    int *matrix = (int *)malloc (row * column * sizeof (int));
    for (int i = 0; i < row * column; ++ i) {
        scanf ("%d", matrix + i);
    }

    int *copy_matrix = (int *)malloc (row * column * sizeof (int));
    for (int i = 0; i < row * column; ++ i) {
        copy_matrix [i] = matrix [i];
    }

    char instruction [20];
    while (1) {
        scanf ("%s", instruction);
        // gets (instruction);
        if (!strcmp (instruction, "exit"))
            break;
        for (int i = 0; i < row * column; ++ i) {
            copy_matrix [i] = matrix [i];
        }
        if (!strcmp (instruction, "ravel"))
            ravel (copy_matrix, &row, &column);
        else if (!strcmp (instruction, "reshape"))
            reshape (&row, &column);
        else if (!strcmp (instruction, "resize"))
            resize (&matrix, &row, &column);
        else if (!strcmp (instruction, "append_row"))
            append_row (&matrix, &row, &column);
        else if (!strcmp (instruction, "insert_row"))
            insert_row (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "append_column"))
            append_column (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "insert_column"))
            insert_column (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "delete_row"))
            delete_row (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "delete_column"))
            delete_column (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "tile"))
            tile (copy_matrix, &matrix, &row, &column);
        else if (!strcmp (instruction, "transpose"))
            transpose (copy_matrix, &matrix, &row, &column);
        if (strcmp (instruction, "ravel"))
            print_matrix (matrix, row, column);
    }

    free (matrix);
    matrix = NULL;
    free (copy_matrix);
    copy_matrix = NULL;

    return 0;
}