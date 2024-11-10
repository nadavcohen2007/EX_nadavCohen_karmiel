#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue
{
    unsigned int* data;
    unsigned int capacity;  // max numbers of queue
    unsigned int front;  // the index of the front number
    unsigned int rear;   // the index of the rear number
    unsigned int size;   // current number of numbers in the queue
} Queue;

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q);  // return front or -1 if empty

bool isEmpty(Queue* q);
bool isFull(Queue* q);

#endif 

