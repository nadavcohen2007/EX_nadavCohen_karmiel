#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (!isEmpty()) {
        removeFromHead();
    }
}

void LinkedList::addToHead(unsigned int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

int LinkedList::removeFromHead() {
    if (isEmpty()) {
        return -1;
    }

    Node* temp = head;
    int data = temp->data;
    head = head->next;
    delete temp;
    return data;
}

bool LinkedList::isEmpty() const 
{
    return head == nullptr;
}
