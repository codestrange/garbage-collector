#include <stdbool.h>
#include "utils_list.h"

int set_garbages(char **matrix, int row, int col, List *list, int points, bool *isOk) {
    int cont = 0;
    for (int i = 0; i < list->size; ++i) {
        Position p = index_list(list, i);
        if (p.row >= row || p.col >= col) {
            *isOk = false;
            return 0;
        }
        if (matrix[p.row][p.col] == 'X') {
            cont = points;
        } else {
            matrix[p.row][p.col] = 'o';
        }
    }
    return cont;
}

int move_robot(char **matrix, int row, int col, Position *robot, int dir, int points, bool *isOk) {
    int cont = 0;
    int d_row[4] = {-1, 0, 1, 0};
    int d_col[4] = {0, 1, 0, -1};
    if (robot->row >= row || robot->col >= col || robot->row + d_row[dir] >= row || robot->col + d_col[dir] >= col) {
        *isOk = false;
        return 0;
    }
    matrix[robot->row][robot->col] = '.';
    robot->row += d_row[dir];
    robot->col += d_col[dir];
    if (matrix[robot->row][robot->col] == 'o')
        cont = points;
    matrix[robot->row][robot->col] = 'X';
    return cont;
}