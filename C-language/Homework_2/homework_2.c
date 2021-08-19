#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "linked_list_lib.h"
#include "int_arr_lib.h"



int main()
{
    srand(clock());
    
    printf("\r\n\r\n----- Linked list test ----- \r\n\r\n");

    struct list *head;
    head = list_init(101);

    struct list *node1 = list_add(head, -145);
    struct list *node2 = list_add(node1, 149521);
    struct list *node3 = list_add(node2, 18);
    struct list *node4 = list_add(head, -144);
    list_contains(node3);

    printf("\r\n---> Remove node3 (item_val = 18) \r\n\r\n");
    list_remove(node3);
    list_contains(node4);
    // ===========================================================
    printf("\r\n\r\n----- Int array lib test ----- \r\n\r\n");

    int_arr_t array = { 0 }; 

    printf("\r\n--> Find first value of 'array': %d\r\n", ar_find_first(&array));
    
    printf("\r\n--> Push some values to 'array'\r\n");
    for(int j = 0; j < 10; j++)
    {
        printf("Pushed value: %d\r\n", ar_push(&array, (rand() % 100)));
    }
    printf("Array size: %d\r\n", array.size);
    printf("Array byte size: %d\r\n\r\n", array.size_in_bytes);

    for(int j = 0; j < array.size; j++)
    {
        printf("value %d: %d\r\n", j, array.data[j]);
    }

    printf("\r\n--> Remove value with index 8: %d\r\n", ar_remove(&array, 8));
    printf("Array size: %d\r\n", array.size);
    printf("Array byte size: %d\r\n\r\n", array.size_in_bytes);

    for(int j = 0; j < array.size; j++)
    {
        printf("value %d: %d\r\n", j, array.data[j]);
    }

    printf("\r\n--> Remove value with index 0: %d\r\n", ar_remove(&array, 0));
    printf("Array size: %d\r\n", array.size);
    printf("Array byte size: %d\r\n\r\n", array.size_in_bytes);

    for(int j = 0; j < array.size; j++)
    {
        printf("value %d: %d\r\n", j, array.data[j]);
    }

    printf("\r\n--> Remove value with index array.size-1: %d\r\n", ar_remove(&array, array.size - 1));
    printf("Array size: %d\r\n", array.size);
    printf("Array byte size: %d\r\n\r\n", array.size_in_bytes);

    for(int j = 0; j < array.size; j++)
    {
        printf("value %d: %d\r\n", j, array.data[j]);
    }

    printf("\r\n--> Find first value of 'array': %d\r\n", ar_find_first(&array));

    printf("\r\n--> Find bigest value of 'array': %d\r\n", ar_find_bigest(&array));

    ar_kill(&array);

    return 0;
}