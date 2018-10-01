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