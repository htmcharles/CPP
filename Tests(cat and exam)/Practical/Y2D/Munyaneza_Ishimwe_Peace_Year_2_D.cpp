#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};
// Linked List Class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}
    // Function to add a node to the linked list
    void addNode(int value) {
        Node* newNode = new Node(value);
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
    // Function to delete the last node from the linked list
    void deleteLastNode() {
        if (head == NULL) {
            cout << "Linked List is empty!" << endl;
            return;
        } else if (head->next == NULL) {
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
    // Function to sort the linked list (bubble sort used for simplicity)
    void sortList() {
        if (head == NULL || head->next == NULL)
            return;
        bool swapped;
        Node *ptr1, *lptr = NULL;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Destructor to deallocate memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};
// Stack Class
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
// Queue Class
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
    LinkedList linkedList;
    Stack stack;
    Queue queue;
    do {
        cout << "Enter your choice" << endl;
        cout << "1. Operate on linked list" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                // Linked List Operations
                for (int i = 0; i < 4; ++i) {
                    int value;
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> value;
                    linkedList.addNode(value);
                }
                cout << "Linked list after adding 4 elements: ";
                linkedList.display();
                linkedList.sortList();
                cout << "Linked List after sorting and deletion of the last element: ";
                linkedList.deleteLastNode();
                linkedList.display();
                break;
            case 2:
                // Stack Operations
                for (int i = 0; i < 5; ++i) {
                    int value;
                    cout << "Enter value to push onto the stack: ";
                    cin >> value;
                    stack.push(value);
                }
                cout << "Stack after 5 pushing and 1 popping: ";
                stack.pop();
                stack.display();
                break;
            case 3:
                // Queue Operations
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
            case 0:
                cout << "Exiting program ..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}