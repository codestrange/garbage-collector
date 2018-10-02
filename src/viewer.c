#include <stdio.h>
#include "viewer.h"

void print_matrix(int size, int score, char **matrix) {
    system("clear");
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}