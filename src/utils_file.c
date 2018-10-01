#include <fcntl.h>
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
    while(read(file_descriptor, &buffer, 1)) {
        line[index++] = buffer;
        if(index >= top) {
            top *= 2;
            line = realloc(line, top * sizeof(char));
        }
        if(buffer == 10) {
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