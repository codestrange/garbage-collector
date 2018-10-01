#include <fcntl.h>
#include "utils_file.h"
#include "utils_list.h"

ArrayList parse_file(char *file_name) {
    int file_descriptor = open(file_name, O_RDONLY, 0664);
    int index = 0;
    int top = 100;
    char *line = malloc(top * sizeof(char));
    char buffer;
    ArrayList arraylist = new_arraylist(10);
    while(read(file_descriptor, &buffer, 1)) {
        line[index++] = buffer;
        if(index >= top) {
            top *= 2;
            line = realloc(line, top * sizeof(char));
        }
        if(buffer == 10) {
            List list = parse_line(line);
            append_arraylist(&arraylist, list);
            index = 0;
        }
    }
    line[index] = 0;
    List list = parse_line(line);
    append_arraylist(&arraylist, list);
    return arraylist;
}

List parse_line(char *line) {
    List list = new_list(10);
    int val = 0;
    int row = 0;
    int ok = 0;
    while(*line) {
        if(*line >= '0' && *line <= '9') {
            val = val * 10 + (*line - '0');
            ok = 0;
        }
        else if(*line == ','){
            row = val;
            val = 0;
        }
        else {
            Position p = new_position(row, val);
            append_list(&list, p);
            val = 0;
            ok = 1;
        }
        ++line;
    }
    if(!ok) {
        Position p = new_position(row, val);
        append_list(&list, p);
    }
    return list;
}