#include <iostream>

// linkedlist Node 
struct Node 
{
    unsigned int data;
    Node* next;
};

// linkedlist 
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
            return -1;
        }
        Node* temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }

    bool isEmpty() const 
    {
        return head == nullptr;
    }

private:
    Node* head;
};

// stack Struct and Function
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
    s->list = nullptr;
}

void push(Stack* s, unsigned int element) 
{
    s->list->addToHead(element);
}

int pop(Stack* s) 
{
    return s->list->removeFromHead();
}

bool isEmpty(Stack* s) {
    return s->list->isEmpty();
}

bool isFull(Stack* s) 
{
    return false;
}

// reverse the mahsanit
void reverse(int* nums, unsigned int size) 
{
    // hold the place
    for (unsigned int i = 0; i < size / 2; ++i) 
    {
        int temp = nums[i];
        nums[i] = nums[size - i - 1];
        nums[size - i - 1] = temp;
    }
}

int* reverse10() 
{
    // place the order
    static int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    return arr;
}

// the menu
void displayMenu() 
{
    std::cout << "select an option:\n";
    std::cout << "1. push a number into the stack\n";
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

        switch (choice) {
        case 1: // push
            std::cout << "enter a positive number to push: ";
            std::cin >> number;
            if (number > 0) {
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
            if (isEmpty(&stack)) 
            {
                std::cout << "the stack is empty\n"; // if the stack return -1 is not empty
            }
            else // if not return is not empty
            {
                std::cout << "the stack is not empty\n";
            }
            break;

        case 4: // exit
            std::cout << "exiting program...\n";
            break;

        default:
            std::cout << "please try again\n";
        }
    } while (choice != 4);

    cleanStack(&stack);
    return 0;
}
