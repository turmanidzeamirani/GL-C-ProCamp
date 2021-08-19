#include "int_arr_lib.h"

#include <stdlib.h>
#include <string.h>



/*
 * @brief Fuction to append value to array
 * 
 * @param arr: pointer to array 
 * @param val: value to append
 * @return Returns append value on success. Otherwise '-1'
 */
int ar_push(int_arr_t *arr, int val)
{
    if(arr != NULL)
    {
        if(arr->data == NULL)
        {
            // allocate firs item
            arr->data = (int*)malloc(sizeof(int));
            if(arr->data != NULL)
            {
                arr->data[0] = val;
                arr->size++;
                arr->size_in_bytes = arr->size * sizeof(int);

                return  arr->data[0];
            }

        }else
            {
                // increase array by 1 item
                arr->data = (int*)realloc(arr->data, (arr->size_in_bytes + sizeof(int)));
                if(arr->data != NULL)
                {
                    arr->data[arr->size] = val;
                    arr->size++;
                    arr->size_in_bytes = arr->size * sizeof(int);

                    return  arr->data[arr->size - 1];
                }
            }
    }

    return -1;
}

/*
 * @brief Fuction to remove value by array index
 * 
 * @param arr: pointer to array 
 * @param index: index of value to remove
 * @return Returns removed value. If index out 
 *          of array or other error occurred returns '-1'
 */
int ar_remove(int_arr_t *arr, int index)
{
    if((index >= arr->size) || (index < 0))
    {
        return -1;
    }

    int val_to_rem = arr->data[index];

    // create new array

    int *new = (int*)malloc((arr->size - 1) * sizeof(int));
    if(new != NULL)
    {
        // coppy data before index
        if((index != 0) && (index != (arr->size - 1)))
        {
            // Copy data before index value
            // Gen num of bytes before index value
            int bytes_before_indx = index * sizeof(int);
            memcpy(new, arr->data, bytes_before_indx);
            int bytes_after_indx = (arr->size - index - 1) * sizeof(int);
            memcpy(&new[index], &arr->data[index + 1], bytes_after_indx);
            free(arr->data);
            arr->data = new;
            arr->size--;
            arr->size_in_bytes = bytes_before_indx + bytes_after_indx;
            return val_to_rem;

        }else if(index == 0)
                {
                    memcpy(new, &arr->data[1], (arr->size_in_bytes - sizeof(int)));
                    free(arr->data);
                    arr->data = new;
                    arr->size--;
                    arr->size_in_bytes = arr->size * sizeof(int);
                    return val_to_rem;

                }else if(index == (arr->size - 1))
                        {
                            memcpy(new, arr->data, (arr->size_in_bytes - sizeof(int)));
                            free(arr->data);
                            arr->data = new;
                            arr->size--;
                            arr->size_in_bytes = arr->size * sizeof(int);
                            return val_to_rem;
                        }
    }

    return -1;
}


/*
 * @brief Fuction to get value with index 0
 * 
 * @param arr: pointer to array 
 * @return Returns value with index 0. If not found '-1'
 */
int ar_find_first(int_arr_t *arr)
{
    if(arr->data != NULL)
    {
        return arr->data[0];
    }

    return -1;
}


/*
 * @brief Fuction returns biggest value in array
 * 
 * @param arr: pointer to array 
 * @return If not found '-1'
 */
int ar_find_bigest(int_arr_t *arr)
{
    if(arr->data != NULL)
    {
        int bigest = arr->data[0];
        for(int i = 1; i < arr->size; i++)
        {
            if(arr->data[i] > bigest)
                    bigest = arr->data[i];
        }
        
        return bigest;
    }

    return -1;
}


void ar_kill(int_arr_t *arr)
{
    free(arr->data);
}