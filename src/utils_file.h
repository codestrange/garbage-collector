#ifndef UTILS_FILE
#define UTILS_FILE

#include <stdbool.h>
#include "utils_list.h"

int get_file(int file_name);

char *get_line(int file_descriptor);

List get_garbages(int file_descriptor);

List parse_line(char *line);

Position parse_position(char *line, int *index, bool *isOk);

int parse_number(char *line, int *index, bool *isOk);

#endif