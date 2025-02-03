#include <iostream>
#include <cstdlib>
using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node to the linked list
    void addNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to sort the linked list
    void sortList() {
        // Sort implementation (omitted for brevity)
        // Assume sorting the list in ascending order
    }

    // Function to delete the last element of the linked list
    void deleteLastElement() {
        if (head == nullptr) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr) {
            delete temp;
            head = nullptr;
        } else {
            delete temp;
            prev->next = nullptr;
        }
    }
};

// Stack Class
class Stack {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack is full, cannot push." << endl;
            return;
        }
        arr[++top] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        cout << "Popped element: " << arr[top--] << endl;
    }
};

// Queue Class
class Queue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
            cout << "Queue is full, cannot enqueue." << endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }

        int data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << "Dequeued element: " << data << endl;
    }
};

int main() {
    int choice;
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    do {
        cout << "Enter your choice: \n1. Linked List\n2. Stack\n3. Queue\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Linked List operations:" << endl;
                // Adding 4 nodes to linked list
                for (int i = 1; i <= 4; ++i) {
                    int value;
                    cout << "Enter value for node " << i << ": ";
                    cin >> value;
                    linkedList.addNode(value);
                }

                // Sort the elements
                linkedList.sortList();

                // Delete the last element
                linkedList.deleteLastElement();

                break;
            }
            case 2: {
                cout << "Stack operations:" << endl;
                // Pushing 5 elements onto the stack
                for (int i = 1; i <= 5; ++i) {
                    int value;
                    cout << "Enter value to push onto the stack: ";
                    cin >> value;
                    stack.push(value);
                }

                // Popping one element from the stack
                stack.pop();

                break;
            }
            case 3: {
                cout << "Queue operations:" << endl;
                // Adding 5 elements to the queue
                for (int i = 1; i <= 5; ++i) {
                    int value;
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    queue.enqueue(value);
                }

                // Removing one element from the queue
                queue.dequeue();

                break;
            }
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
