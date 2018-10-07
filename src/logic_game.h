#ifndef LOGIT_GAME
#define LOGIT_GAME

#include <stdbool.h>
#include "utils/utils_list.h"

int set_garbages(char **matrix, int row, int col, List *list, int points, bool *isOk);

int move_robot(char **matrix, int row, int col, Position *robot, int dir, int points, bool *isOk);

#endif