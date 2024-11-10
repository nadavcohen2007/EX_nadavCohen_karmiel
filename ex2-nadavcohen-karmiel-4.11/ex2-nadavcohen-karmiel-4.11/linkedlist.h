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

    void addToHead(unsigned int value);
    int removeFromHead();
    bool isEmpty() const;

private:
    Node* head;
};

#endif // LINKEDLIST_H
