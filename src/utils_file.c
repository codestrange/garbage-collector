#include <fcntl.h>
#include <stdbool.h>
#include "utils_file.h"
#include "utils_list.h"

int get_file(int file_name) {
    int file_descriptor = open(file_name, O_RDONLY, 0664);
    return file_descriptor;
}

char *get_line(int file_descriptor) {
    int index = 0;
    int top = 100;
    char *line = malloc(top * sizeof(char));
    char buffer;
    while (read(file_descriptor, &buffer, 1)) {
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
    line[index] = 0;
    return line;
}

List get_garbages(int file_descriptor) {
    char *line = get_file(file_descriptor);
    List result = parse_line(line);
    return result;
}

List parse_line(char *line) {
    int index = 0;
    bool isOk = true;
    List list = new_list(5);
    while (line[index]) {
        Position pos = parse_position(line, &index, &isOk);
        if (line[index] != ' ' && line[index] != 0)
            isOk = false;
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