#include <stdlib.h>
#include <stdio.h>

typedef struct element{
    struct element *next;
    int data;
}element;

typedef struct queue{
    struct element *head;
} queue;

int isempty(queue *q){
    if(q->head == NULL){
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int val){
    element *elem = malloc(sizeof(element));
    
    elem->data = val;
    elem->next = NULL;

    // if queue is empty, append elem to the head
    if(q->head == NULL){
        q->head = elem;
    }else{
        element *tail = q->head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = elem;
    }
}

void dequeue(queue *q){
    element *garbage = q->head;
    q->head = garbage->next;
    free(garbage);
}

void print(queue *q){
    for (element *tmp = q->head; tmp != NULL; tmp=tmp->next){
        printf("%d -> \t", tmp->data);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    queue q = {NULL};

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    print(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    print(&q);

    return 0;
}
