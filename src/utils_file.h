#ifndef UTILS_FILE
#define UTILS_FILE
#include "utils_list.h"

int get_file(int file_name);

char *get_line(int file_descriptor);

List get_garbages(int file_descriptor);

List parse_line(char *line);

#endif