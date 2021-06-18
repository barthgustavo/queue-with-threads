#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct Item
{
    double value;
    struct Item *next;
};

struct Queue
{
    int size;
    int capacity;
    struct Item *head;
    struct Item *tail;
};

struct Queue* createQueue(int capacity)
{
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->size = 0;
    queue->capacity = capacity;
    
    return queue;
}

int enqueue(struct Queue *queue, double value)
{
    if(!(queue->capacity > queue->size)) return 0;

    printf("Hello, my size is: %d and i'm adding the number %f\n", queue->size, value);

    struct Item *item = malloc(sizeof(struct Item));

    item->next = 0;
    item->value = value;

    if(queue->size == 0) //if empty queue
    {
        queue->head = item;
        queue->tail = item;
    }

    //put at the end of the queue
    queue->tail->next = item;
    queue->tail = item;

    return ++queue->size;
}

double* dequeue(struct Queue *queue)
{
    if(queue->size == 0) return 0;

    double *val = &queue->head->value;

    queue->head = queue->head->next;

    printf("Hello, my size is: %d and i'm removing the number %f\n", queue->size, *val);

    queue->size--;

    return val;
}