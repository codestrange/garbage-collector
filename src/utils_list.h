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

typedef struct ArrayList {
    List* array;
    int size;
    int capacity;
} ArrayList;

Position new_position(int row, int col);

List new_list(int capacity);

void insert_list(List *list, int index, Position item);

void append_list(List *list, Position item);

void clear_list(List *list);

Position remove_list(List *list, int index);

Position pop_list(List *list);

Position index_list(List *list, int index);

ArrayList new_arraylist(int capacity);

void insert_arraylist(ArrayList *arraylist, int index, List item);

void append_arraylist(ArrayList *arraylist, List item);

void clear_arraylist(ArrayList *arraylist);

List remove_arraylist(ArrayList *arraylist, int index);

List pop_arraylist(ArrayList *arraylist);

List index_arraylist(ArrayList *arraylist, int index);

#endif