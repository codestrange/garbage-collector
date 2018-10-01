#include "utils_list.h"

Position new_position(int row, int col) {
    Position position;
    position.row = row;
    position.col = col;
    return position;
}

List new_list(int capacity) {
    List list;
    list.capacity = capacity;
    list.array = malloc(capacity * sizeof(Position));
    list.size = 0;
    return list;
}

void insert_list(List *list, int index, Position item) {
    if (index > list->size || index < 0)
        return; // Index Out Arrange
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, list->capacity * sizeof(Position));
    }
    for (int i = index; i < list->size; ++i)
        list->array[i + 1] = list->array[i];
    list->array[index] = item;
    ++list->size;
}

void append_list(List *list, Position item) {
    insert_list(list, list->size, item);
}

void clear_list(List *list) {
    list->size = 0;
}

Position remove_list(List *list, int index) {
    if (index >= list->size || index < 0)
        return; // Index Out Arrange
    Position item = list->array[index];
    for (int i = index; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    --list->size;
    return item;
}

Position pop_list(List *list) {
    return remove_list(list, list->size - 1);
}

Position index_list(List *list, int index) {
    if (index >= list->size || index < 0)
        return; // Index Out Arrange
    return list->array[index];
}

ArrayList new_arraylist(int capacity) {
    ArrayList arraylist;
    arraylist.capacity = capacity;
    arraylist.array = malloc(capacity * sizeof(List));
    arraylist.size = 0;
    return arraylist;
}

void insert_arraylist(ArrayList *arraylist, int index, List item) {
    if (index > arraylist->size || index < 0)
        return; // Index Out Arrange
    if (arraylist->size == arraylist->capacity) {
        arraylist->capacity *= 2;
        arraylist->array = realloc(arraylist->array, arraylist->capacity * sizeof(List));
    }
    for (int i = index; i < arraylist->size; ++i)
        arraylist->array[i + 1] = arraylist->array[i];
    arraylist->array[index] = item;
    ++arraylist->size;
}

void append_arraylist(ArrayList *arraylist, List item) {
    insert_arraylist(arraylist, arraylist->size, item);
}

void clear_arraylist(ArrayList *arraylist) {
    arraylist->size = 0;
}

List remove_arraylist(ArrayList *arraylist, int index) {
    if (index >= arraylist->size || index < 0)
        return; // Index Out Arrange
    List item = arraylist->array[index];
    for (int i = index; i < arraylist->size - 1; ++i)
        arraylist->array[i] = arraylist->array[i + 1];
    --arraylist->size;
    return item;
}

List pop_arraylist(ArrayList *arraylist) {
    return remove_arraylist(arraylist, arraylist->size - 1);
}

List index_arraylist(ArrayList *arraylist, int index) {
    if (index >= arraylist->size || index < 0)
        return; // Index Out Arrange
    return arraylist->array[index];
}
