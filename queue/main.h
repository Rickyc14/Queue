#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>

#define QUEUE_CAPACITY 20

typedef struct {
    void* value[QUEUE_CAPACITY];
    size_t head;
    size_t tail;
    size_t size;
} Queue;

bool initQueue(Queue* ptr_queue)
{
    if (!ptr_queue)
    {
        return false;
    }

    ptr_queue->head = 0;
    ptr_queue->tail = 0;
    ptr_queue->size = 0;
    return true;
}

int isEmpty(Queue* ptr_queue)
{
    return ptr_queue && ptr_queue->size == 0;
}

bool enqueue(Queue* ptr_queue, void* item)
{
    if (!ptr_queue || ptr_queue->size == QUEUE_CAPACITY)
    {
        return false;
    }

    ptr_queue->value[ptr_queue->tail] = item;
    ptr_queue->tail = (ptr_queue->tail + 1) % QUEUE_CAPACITY;
    ptr_queue->size++;
    return true;
}

void* dequeue(Queue* ptr_queue)
{
    void* item;

    if (!ptr_queue || isEmpty(ptr_queue))
    {
        return NULL;
    }

    item = ptr_queue->value[ptr_queue->head];
    ptr_queue->head = (ptr_queue->head + 1) % QUEUE_CAPACITY;
    ptr_queue->size--;
    return item;
}

void debug_print(Queue* ptr_queue)
{
    size_t index;
    size_t tmp;

    if (!ptr_queue)
    {
        printf("null");
        return;
    }
    getchar();
    printf("[");

    if (ptr_queue->size >= 1)
    {
        printf("%d", (int) ptr_queue->value[ptr_queue->head]);
    }

    for (index = 1; index < ptr_queue->size; ++index)
    {
        tmp = (ptr_queue->head + index) % QUEUE_CAPACITY;
        printf(", %d", (int) ptr_queue->value[tmp]);
    }

    printf("]");
}

#endif
