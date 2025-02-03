#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
// Node structure for linked list
struct Node {
    int data;
    Node* next;
};
// Linked list class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}
    // Function to add a node to the linked list
    void addNode(int value) {
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
    }
    // Function to sort the linked list
    void sortList() {
        if (head == NULL || head->next == NULL)
            return;
        Node *i, *j;
        for (i = head; i->next != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
    // Function to delete the last element from the linked list
    void deleteLast() {
        if (head == NULL)
            return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// Stack class
class Stack {
private:
    static const int MAX_SIZE = 5;
    int top;
    int stack[MAX_SIZE];
public:
    Stack() : top(-1) {}
    // Function to push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack is full, cannot push more elements." << endl;
            return;
        }
        stack[++top] = value;
    }
    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        top--;
    }
    // Function to print the stack elements
    void printStack() {
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};
// Queue class
class Queue {
private:
    static const int MAX_SIZE = 5;
    int front, rear;
    int queue[MAX_SIZE];
public:
    Queue() : front(-1), rear(-1) {}
    // Function to add an element to the queue
    void enqueue(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
            cout << "Queue is full, cannot enqueue more elements." << endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
            queue[rear] = value;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
            queue[rear] = value;
        } else {
            queue[++rear] = value;
        }
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
    // Function to print the queue elements
    void printQueue() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; ++i) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < MAX_SIZE; ++i) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; ++i) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};
int main() {
    LinkedList linkedList;
    Stack stack;
    Queue queue;
    int choice;
    do {
        cout << "Enter your choice: \n"
             << "1. Operate on Linked List\n"
             << "2. Operate on Stack\n"
             << "3. Operate on Queue\n"
             << "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                int val;
                for (int i = 1; i <= 4; ++i) {
                    cout << "Enter value for node " << i << " : ";
                    cin >> val;
                    linkedList.addNode(val);
                }
                cout << "Linked list after adding 4 elements: ";
                linkedList.printList();
                linkedList.sortList();
                linkedList.deleteLast();
                cout << "Linked list after sorting its elements and deletion of the last element: ";
                linkedList.printList();
                break;
            case 2:
                int value;
                for (int i = 1; i <= 5; ++i) {
                    cout << "Enter value to push onto the stack : ";
                    cin >> value;
                    stack.push(value);
                }
                cout << "Stack elements after 5 pushing and 1 pop operations: ";
                stack.pop();
                stack.printStack();
                break;
            case 3:
                int val1;
                for (int i = 1; i <= 5; ++i) {
                    cout << "Enter value to add to queue : ";
                    cin >> val1;
                    queue.enqueue(val1);
                }
                cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
                queue.dequeue();
                queue.printQueue();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 0);
    return 0;
    }
