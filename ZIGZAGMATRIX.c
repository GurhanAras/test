 
#include <stdio.h>
#include <stdlib.h> 

void fill_matrix(int **matrix, int row, int column);
void print_matrix(int **matrix, int row, int column);
void convert_to_zigzag(int **matrix, int row, int column);

int main() 
{
    int row;
    int column;

    printf("Enter the number of rows of the matrix: ");

    if(scanf("%d", &row) != 1 || row <= 0) {
        fprintf(stderr, "Input error! Expected a positive integer value.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the number of the columns of the matrix: ");

    if(scanf("%d", &column) != 1 || column <= 0) {
        fprintf(stderr, "Input error! Expected a positive integer value.\n");
        exit(EXIT_FAILURE);
    }

    int **matrix;

    matrix = (int**) malloc(row * sizeof(int*));

    if(matrix == NULL) {
        fprintf(stderr, "Error! Memory allocation was unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < row; i++) {
        matrix[i] = (int*) malloc(column * sizeof(int));
        if(matrix[i] == NULL) {
            fprintf(stderr, "Error! Memory allocation was unsuccessful.\n");
            for(int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nEnter the elements in the matrix:\n");
    fill_matrix(matrix, row, column);

    printf("\nInitial state of the matrix:\n");
    print_matrix(matrix, row, column);

    convert_to_zigzag(matrix, row, column);

    printf("\nZigzag version of the matrix:\n");
    print_matrix(matrix, row, column);

    for(int i = 0; i < row; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}

void fill_matrix(int **matrix, int row, int column) {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("matrix[%d][%d] = ", i, j);
            if(scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Input error! Expected an integer value.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void print_matrix(int **matrix, int row, int column) {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }
}

void convert_to_zigzag(int **matrix, int row, int column) {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column / 2; j++) {
            if(i % 2 != 0) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][column - j - 1];
                matrix[i][column - j - 1] = temp;    
            }
        }
    }
}
