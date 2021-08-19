#ifndef INT_ARR_LIB_H
#define INT_ARR_LIB_H


typedef struct
{
    int *data; // pointer to array data
    int size;
    int size_in_bytes;
}int_arr_t;


int ar_push(int_arr_t *arr, int val);
int ar_remove(int_arr_t *arr, int index);
int ar_find_first(int_arr_t *arr);
int ar_find_bigest(int_arr_t *arr);
void ar_kill(int_arr_t *arr);

#endif // INT_ARR_LIB_H