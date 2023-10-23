#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    struct element *next;
    int data;
}element;

typedef struct linked_list{
    struct element *head;
}linked_list;

void append_list(linked_list *list, int val){
    element *elem = (element *)malloc(sizeof(element));

    elem->data = val;
    elem->next = NULL;  // Really important to explicitly set this to null. Malloc does not zero memory

    if(list->head == NULL){
        // Empty list, we need to append to head
        list->head = elem;
    }else{
        // List has some elements, find the end and append to that
        element *tail = list->head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = elem;
    }
}

void prepend_list(linked_list *list, int val){
    element *elem = (element *)malloc(sizeof(element));
    
    elem->data = val;
    elem->next = list->head;
    list->head = elem;
    printf("insert, %d, next-%d\n", elem->data, elem->next->data);

}

void remove_from_head(linked_list *list){
    element *garbage = list->head;

    list->head = garbage->next;
    free(garbage);
}

void print_list(linked_list *list){
    element *cur = list->head;

    while(cur != NULL){
        printf("{%d} -> ", cur->data);
        cur = cur->next;
    }
}

int main(int argc, char const *argv[])
{
    linked_list list = {NULL};

    append_list(&list, 1);
    append_list(&list, 2);
    append_list(&list, 3);
    prepend_list(&list, 4);
    prepend_list(&list, 5);
    remove_from_head(&list);

    print_list(&list);
    /* code */
    return 0;
}
