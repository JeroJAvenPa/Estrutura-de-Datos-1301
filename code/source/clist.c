/*
    clist.c
*/
#include <stdlib.h>
#include <string.h>

#include "clist.h"

/*
    Initialize the circular list
*/
void clist_init (CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;    
}

/*
    Destroying the circular list
*/
void clist_destroy (CList *list) {
    void *data;

    while(clist_size(list) > 0) {
        if (clist_rem_next(list, list->head, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }    
    memset(list, 0, sizeof(CList));
    return;
}

/*
    Insert next node at the circular list
*/
int clist_ins_next (CList *list, CListNode *node, const void *data ) {
    CListNode    *new_node;

    if ((new_node = (CListNode *)malloc(sizeof(CListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    // Handle insertion from head at the circular list
    // The list is empty
    if (clist_size(list) == 0) {
        new_node->next = new_node;
        list->head = new_node;
        
    } else {
        // Handle insertion when the circular list is not empty
        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;

    return 0;
}

/*
    Remove next node at the circular list
*/
int clist_rem_next (CList *list, CListNode *node, void **data) {
    CListNode *old_node;

    // Check if is not empty the list
    if (clist_size(list) == 0)
        return -1;
    
    *data = node->next->data;
    
    // Handle removal head from the circular list 
    if (node->next == node) {
        old_node = node->next;
        list->head = NULL;

    } else {
        // Handle removal from somewhere other than at the last element 

        old_node = node->next;
        node->next = node->next->next;

        if (old_node == clist_head(list))
            list->head = old_node->next;
    }

    free(old_node);
    list->size--;

    return 0;
}

