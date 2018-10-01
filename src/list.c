#include "list.h"

List new_list(int capacity) {
    List list;
    list.capacity = capacity;
    list.array = malloc(capacity * sizeof(T));
    list.size = 0;
    return list;
}

void insert_list(List *list, int index, T item) {
    if (index > list->size || index < 0)
        return; // Index Out Arrange
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, list->capacity * sizeof(T));
    }
    for (int i = index; i < list->size; ++i)
        list->array[i + 1] = list->array[i];
    list->array[index] = item;
    ++list->size;
}

void append_list(List *list, T item) {
    insert_list(list, list->size, item);
}

void clear_list(List *list) {
    list->size = 0;
}

T remove_list(List *list, int index) {
    if (index >= list->size || index < 0)
        return 0; // Index Out Arrange
    T item = list->array[index];
    for (int i = index; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    --list->size;
    return item;
}

T pop_list(List *list) {
    return remove_list(list, list->size - 1);
}

T index_list(List *list, int index) {
    if (index >= list->size || index < 0)
        return 0; // Index Out Arrange
    return list->array[index];
}