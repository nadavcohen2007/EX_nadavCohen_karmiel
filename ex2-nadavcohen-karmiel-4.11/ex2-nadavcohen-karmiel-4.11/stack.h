#include <iostream>

struct Node 
{
    unsigned int data;
    Node* next;
};

class LinkedList 
{
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() 
    {
        while (!isEmpty()) 
        {
            removeFromHead();
        }
    }

    void addToHead(unsigned int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    int removeFromHead() 
    {
        if (isEmpty()) 
        {
            return -1; // if the stake is empty return -1
        }

        Node* temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }

    bool isEmpty() const 
    {
        return head == nullptr; //null to the end
    }

private:
    Node* head;
};

struct Stack 
{
    LinkedList* list;
};

void initStack(Stack* s) 
{
    s->list = new LinkedList();
}

void cleanStack(Stack* s) 
{
    delete s->list;
    s->list = nullptr;// another null to the end
}

void push(Stack* s, unsigned int number) 
{
    s->list->addToHead(number);
}

int pop(Stack* s) 
{
    return s->list->removeFromHead();
}

bool isEmpty(Stack* s) 
{
    return s->list->isEmpty();
}

bool isFull(Stack* s) 
{
    return false; // linked list when stack has no limit
}

void displayMenu() 
{
    std::cout << "select an option:\n";
    std::cout << "1. push a number onto the stack\n";
    std::cout << "2. pop a number from the stack\n";
    std::cout << "3. check if the stack is empty\n";
    std::cout << "4. exit\n";
    std::cout << "enter your choice: ";
}

int main() 
{
    Stack stack;
    initStack(&stack);
    int choice;
    unsigned int number;

    do 
    {
        displayMenu();
        std::cin >> choice;

        switch (choice) 
        {
        case 1: // push
            std::cout << "enter a positive number to push: ";
            std::cin >> number;
            if (number > 0) 
            {
                push(&stack, number);
                std::cout << number << " pushed into the stack\n";
            }
            else {
                std::cout << "please enter a positive number\n";
            }
            break;

        case 2: // pop
            if (!isEmpty(&stack)) 
            {
                int poppedValue = pop(&stack);
                std::cout << "popped value: " << poppedValue << "\n";
            }
            else {
                std::cout << "stack is empty\n";
            }
            break;

        case 3: // check if empty
            if (isEmpty(&stack)) {
                std::cout << "the stack is empty\n"; // if the stake return -1
            }
            else {
                std::cout << "the stack is not empty\n"; // if not return stack is not empty
            }
            break;

        case 4: // Exit
            std::cout << "exiting program...\n";
            break;

        default:
            std::cout << "please try again\n";
        }
    } while (choice != 4);

    cleanStack(&stack);
    return 0;
}
