#ifndef UTILS_FILE
#define UTILS_FILE

#include <stdbool.h>
#include "utils_list.h"

int get_file(const char *file_name);

char *get_line(int file_descriptor, bool *isEOF);

List get_garbages(int file_descriptor, bool *isEOF, bool *isOk);

List parse_line(char *line, bool *isOk);

Position parse_position(char *line, int *index, bool *isOk);

int parse_number(char *line, int *index, bool *isOk);

#endif