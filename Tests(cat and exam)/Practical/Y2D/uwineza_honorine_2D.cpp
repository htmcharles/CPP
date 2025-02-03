#include <iostream>
using namespace std;

//********************for linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node and add it to the end of the linked list
Node* addNode(Node* head, int position) {
    int value;
    cout << "Enter value of the node " << position << ": " << endl;
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head; // Return the modified head pointer
}

//Deleting the last element
void deleteLastNode(Node* head) {
    if (head == NULL) {
        cout << "Empty!" << endl;
        return;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted the node!" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Deleted the last node!" << endl;
}

void sortLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    bool swapped;
    Node* current;
    Node* last = NULL;
    do {
        swapped = false;
        current = head;
        while (current->next != last) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

//**************************for Stack
class Stack {
private:
    static const int maxSize = 5;
    int arr[maxSize];
    int top;

public:
    Stack() : top(-1) {}
    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    // Function to check if stack is full
    bool isFull() {
        return top == maxSize - 1;
    }
    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }
    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        --top;
    }
    // Function to display the stack
    void display() {
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

//***************************for Queue
class Queue {
private:
    static const int maxSize = 6;
    int arr[maxSize];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}
    // Function to check if queue is empty
    bool isEmpty() {
        return front == rear;
    }
    // Function to check if queue is full
    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % maxSize;
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front = (front + 1) % maxSize;
    }
    // Function to display the queue
    void display() {
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int choice;
    do {
        cout << "Enter your choice: " << endl;
        cout << "1. Operate on Linked List" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit";
        cin >> choice;

        switch (choice) {
            case 1: //case on linked list operations
            {
                Node* linkedList = NULL;
                for (int i = 1; i <= 4; i++) {
                    linkedList = addNode(linkedList, i);
                }
                sortLinkedList(linkedList);
                deleteLastNode(linkedList);
                break;
            }
            case 2: //case on Stack Operations
            {
                Stack stack;
                for (int i = 0; i < 5; ++i) {
                    int value;
                    cout << "Enter value to push onto the stack: ";
                    cin >> value;
                    stack.push(value);
                }
                cout << "Stack after 5 pushing and 1 pop operations: ";
                stack.pop();
                stack.display();
                break;
            }
            case 3: // case on Queue Operations
            {
                Queue queue;
                for (int i = 0; i < 5; ++i) {
                    int value;
                    cout << "Enter value to add to queue: ";
                    cin >> value;
                    queue.enqueue(value);
                }
                cout << "Queue elements after 5 enqueue and 1 dequeue operations:";
                queue.dequeue();
                queue.display();
                break;
            }
            case 0:
                cout << "Exiting program ..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}

