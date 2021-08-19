#ifndef LINKED_LIST_LIB_H
#define LINKED_LIST_LIB_H


/*
 * @brief This is list lib for double linked linear list.
 *          This means 'next' for head is NULL
 */

struct list
{
    int list_item; // Some list item
    struct list *next; // pointer to next node
    struct list *prev; // pointer to previous node
};

struct list *list_init(int list_item_val);
struct list *list_add(struct list *next_list_node, int list_item_val);
void         list_remove(struct list *node_to_remove);
void         list_contains();



#endif // LINKED_LIST_LIB_H