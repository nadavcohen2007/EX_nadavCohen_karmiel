#include "queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size)
{
    q->data = new unsigned int[size];
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void cleanQueue(Queue* q)
{
    delete[] q->data;
    q->data = nullptr;
    q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q)) {
        std::cerr << "queue is full\n";
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = newValue;
    q->size++;
}

int dequeue(Queue* q)
{
    if (isEmpty(q)) 
    {
        std::cerr << "queue is empty\n";
        return -1;
    }
    int front_Value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return front_Value;
}

bool isEmpty(Queue* q)
{
    return q->size == 0;
}

bool isFull(Queue* q)
{
    return q->size == q->capacity;
}



