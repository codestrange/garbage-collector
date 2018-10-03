#include <stdio.h>
#include "viewer.h"

void print_matrix(int row, int col, int score, char **matrix) {
    system("clear");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Score: %d", score);
}

char **get_matrix(int row, int col) {
    char **matrix;
    matrix = malloc(row * sizeof(char *));
    for (int i = 0; i < row; ++i) {
        matrix[i] = malloc(col * sizeof(char *));
    }
    return matrix;
}