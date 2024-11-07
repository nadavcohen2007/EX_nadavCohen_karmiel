#include "Stack.h"

void initStack(Stack* s) 
{
    s->list = new LinkedList();
}

void cleanStack(Stack* s) 
{
    delete s->list;
    s->list = nullptr;
}

void push(Stack* s, unsigned int element) 
{
    s->list->addToHead(element);
}

int pop(Stack* s) {
    return s->list->removeFromHead();
}

bool isEmpty(Stack* s) {
    return s->list->isEmpty();
}

bool isFull(Stack* s) {
    return false; // A linked list-based stack has no limit
}
