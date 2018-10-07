#ifndef UTILS_LIST
#define UTILS_LIST

typedef struct Position {
    int row, col;
} Position;

typedef struct List {
    Position *array;
    int size;
    int capacity;
} List;

Position new_position(int row, int col);

List new_list(int capacity);

void insert_list(List *list, int index, Position item);

void append_list(List *list, Position item);

void clear_list(List *list);

Position remove_list(List *list, int index);

Position pop_list(List *list);

Position index_list(List *list, int index);

#endif