#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    unsigned int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList();                  
    ~LinkedList();                 

    void addToHead(unsigned int value); // add a new node to the head of the list
    int removeFromHead();               // remove the head node and return its value, or -1 if the list is empty
    bool isEmpty() const;               // check if the list is empty

private:
    Node* head;
};

#endif // LINKEDLIST_H
