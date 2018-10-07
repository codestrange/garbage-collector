#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils_file.h"
#include "utils_list.h"

int get_file(const char *file_name) {
    int file_descriptor = open(file_name, O_RDWR | O_CREAT, 0664);
    return file_descriptor;
}

char *get_line(int file_descriptor, bool *isEOF) {
    int index = 0;
    int top = 100;
    char *line = malloc(top * sizeof(char));
    char buffer;
    bool _isEOF = true;
    while (read(file_descriptor, &buffer, 1)) {
        _isEOF = false;
        line[index++] = buffer;
        if (index >= top) {
            top *= 2;
            line = realloc(line, top * sizeof(char));
        }
        if (buffer == 10) {
            line[index - 1] = 0;
            return line;
        }
    }
    *isEOF = _isEOF;
    line[index] = 0;
    return line;
}

List get_garbages(int file_descriptor, bool *isEOF, bool *isOk) {
    char *line = get_line(file_descriptor, isEOF);
    List result = parse_line(line, isOk);
    return result;
}

List parse_line(char *line, bool *isOk) {
    int index = 0;
    List list = new_list(5);
    while (line[index]) {
        Position pos = parse_position(line, &index, isOk);
        if (line[index] != ' ' && line[index] != 0)
            *isOk = false;
        if (!isOk) {
            clear_list(&list);
            return list;
        }
        append_list(&list, pos);
        if (line[index] == 0)
            break;
        ++index;
    }
    return list;
}

Position parse_position(char *line, int *index, bool *isOk) {
    int row = parse_number(line, index, isOk);
    if (line[*index] != ',')
        *isOk = false;
    ++*index;
    int col = parse_number(line, index, isOk);
    return new_position(row, col);
}

int parse_number(char *line, int *index, bool *isOk) {
    int number = -1;
    while (line[*index]) {
        char c = line[*index];
        if (c >= 48 && c <= 57) {
            if (number == -1)
                number = 0;
            number = number * 10 + (c - 48);
            ++*index;
        } else
            break;
    }
    if (number == -1)
        *isOk = false;
    return number;
}