#ifndef LIST
#define LIST
#ifndef T
#define T char
#endif
typedef struct List {
    T *array;
    int size;
    int capacity;
} List;
List new_list(int capacity);
void insert_list(List *list, int index, T item);
void append_list(List *list, T item);
void clear_list(List *list);
T remove_list(List *list, int index);
T pop_list(List *list);
T index_list(List *list, int index);
#endif