#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "logic_game.h"
#include "movement.h"
#include "utils/utils_file.h"
#include "utils/utils_list.h"
#include "utils/utils_matrix.h"

void print_error(char* error) {
    system("clear");
    printf("Error: %s\n", error);
}

int main(int argc, const char **argv) {
    switch (argc) {
        case 1:
            printf("Error: Tiene que introducir la dirección del archivo de basuras y la dirección de la libreria que contiene la función de movimiento.\n");
            return 0;
        case 2:
            printf("Error: Tiene que introducir la dirección de la libreria que contiene la función de movimiento.\n");
            return 0;
    }
    const char *fn_garbages = argv[1];
    int fd = get_file(fn_garbages);
    int turns = 1000;
    int frequency = 10;
    int temp_frequency = frequency;
    char **matrix = get_matrix(15, 15);
    int score = 0;
    int points = 10;
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            matrix[i][j] = '.';
    matrix[0][0] = 'X';
    Position robot = new_position(0, 0);
    print_matrix(15, 15, score, matrix);
    while (turns--) {
        char c;
        scanf("%c", &c);
        bool isEOF = false, isOk = true;
        if (temp_frequency-- == frequency) {
            List garbages = get_garbages(fd, &isEOF, &isOk);
            if (isEOF) {
                print_error("El archivo de basura se termino antes que la cantidad de turnos.");
                break;
            } else if(!isOk) {
                print_error("El archivo de basura esta mal construido.");
                break;
            } else if(garbages.size != 5) {
                print_error("Tiene que haber 5 basuras por línea en el archivo de basuras.");
                break;
            }
            int temp_score = set_garbages(matrix, 15, 15, &garbages, points, &isOk);
            if (!isOk) {
                print_error("La posición de una basura en el archivo de basuras está fuera de la matrix.");
                break;
            }
            score += temp_score;
        }
        if (temp_frequency == 0)
            temp_frequency = frequency;
        int dir = fmd(matrix);
        int temp_score = move_robot(matrix, 15, 15, &robot, dir, points, &isOk);
        if (!isOk) {
            print_error("El robot ha salido de la matrix.");
            break;
        }
        score += temp_score;
        print_matrix(15, 15, score, matrix);
    }
    close(fd);
}