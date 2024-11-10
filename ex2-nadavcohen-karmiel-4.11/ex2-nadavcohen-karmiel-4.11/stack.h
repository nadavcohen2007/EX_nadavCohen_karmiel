#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

struct Stack {
    LinkedList* list;
};

void initStack(Stack* s);
void cleanStack(Stack* s);
void push(Stack* s, unsigned int element);
int pop(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);

#endif // STACK_H
