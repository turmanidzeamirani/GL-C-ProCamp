#include "linked_list_lib.h"

#include <stdlib.h>
#include <stdio.h>



/*
 * @brief Fuction to init root node
 * 
 * @param list_item_val: value to assign for list item
 * @return Returns pointer to root list node. In case of error returns NULL
 */
struct list *list_init(int list_item_val)  
{
    struct list *lst;
    // allocate memory for root node
    lst = (struct list*)malloc(sizeof(struct list));
    lst->list_item = list_item_val;
    lst->next = NULL;
    lst->prev = NULL;
    return lst;
}


/*
 * @brief Fuction to addt node
 * 
 * @param next_list_node: pointer to node after which to add new one
 * @param list_item_val: value to assign for list item
 * @return Returns pointer to newly created list node. In case of error returns NULL.
 */
struct list *list_add(struct list *next_list_node, int list_item_val)
{
    struct list *new_node; // pointer to newly created item

    new_node = (struct list*)malloc(sizeof(struct list));
    if(new_node != NULL)
    {
        new_node->list_item = list_item_val; //assign value to item
        new_node->prev = next_list_node->prev; // make new node point to previous node of next node
        new_node->next = next_list_node; // make new node point to next node
        next_list_node->prev = new_node;

    }else
        {
            return NULL;
        }
    return next_list_node->prev;
}


/*
 * @brief Fuction to remove passed node
 * 
 * @param node_to_remove: pointer to node should be removed
 * @return None
 */
void list_remove(struct list *node_to_remove)
{
    if(node_to_remove != NULL)
    {
        if(node_to_remove->next != NULL) // if next node exists
        {
            node_to_remove->next->prev = node_to_remove->prev; // here we don't care what pointer it holds
            if(node_to_remove->prev != NULL) // if previous node exists
            {
                node_to_remove->prev->next = node_to_remove->next;
            }

        }else
            {
                // there is no nex node
                if(node_to_remove->prev != NULL) // if previous node exists
                {
                    node_to_remove->prev->next = NULL;
                }
            }       
    }
    
    free(node_to_remove);
}


/*
 * @brief Fuction to remove passed node
 * 
 * @param head_node: pointer to root node
 * @return None
 */
void list_contains(struct list *head_node)
{
    struct list *head;

    head = head_node;

    if(head->next != NULL)
    {
        // it is not head pointer
        // Need to find it
        do
        {
            head = head->next;

        } while(head->next != NULL);              
    }
    printf("list_contains:\r\n");
    do
    {
        printf(": %d\r\n", head->list_item);
        head = head->prev;
    } while (head != NULL);
    printf("------\r\n");
}