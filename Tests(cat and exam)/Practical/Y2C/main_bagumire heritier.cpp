#include <iostream>
using namespace std;
// Node structure for linked list
struct Node {
    int data;
    Node* next;
};
// Linked list class
class LinkedList {
public:
	Node* head;
    LinkedList() {
        head = NULL;
    }
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
        if (head == NULL) {
            return;
        }
        Node* current = head;
        Node* index = NULL;
        int temp;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    // Function to delete the last element of the linked list
    void deleteLastNode() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            head = NULL;
        }
    }
};
// Stack class
class Stack {
private:
    int top;
    int capacity;
    int* arr;
public:
    Stack(int size) {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }
    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }
    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
    // Function to push an element into the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
        }
    }
    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            top--;
        }
    }
    // Function to display all elements in the stack
    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// Queue class
class Queue {
private:
    int front, rear, size;
    int* arr;
public:
    Queue(int capacity) {
        front = rear = -1;
        size = capacity;
        arr = new int[size];
    }
    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }
    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
        } else {
            rear = (rear + 1) % size;
            arr[rear] = value;
            if (front == -1) {
                front = rear;
            }
        }
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
        } else {
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
    }
    // Function to display all elements in the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};
// Main function
int main() {
    int choice;
    LinkedList linkedList;
    Stack stack(5);
    Queue queue(5);
    Node* temp = NULL;
    do {
        cout << "Enter your choice:\n";
        cout << "1. Operate on Linked List\n";
        cout << "2. Operate on Stack\n";
        cout << "3. Operate on Queue\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                // Linked List Operations
                int value;
                for (int i = 1; i <= 4; ++i) {
                    cout << "Enter value for node " << i << ": ";
                    cin >> value;
                    linkedList.addNode(value);
                }
                cout << "Linked List after adding 4 elements: ";
                // Display linked list before sorting
                temp = linkedList.head;
                while (temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
                // Sort linked list
                linkedList.sortList();
                // Delete last element of linked list
                linkedList.deleteLastNode();
                cout << "Linked List after sorting its elements and deletion of the last element: ";
                // Display linked list after deleting last element
                temp = linkedList.head;
                while (temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
                break;
            case 2:
                // Stack Operations
                int stackValue;
                for (int i = 1; i <= 5; ++i) {
                    cout << "Enter value to push onto stack: ";
                    cin >> stackValue;
                    stack.push(stackValue);
                }
                stack.pop();
                cout << "Stack after 5 pushing and 1 pop operations: ";
                stack.displayStack();
                break;
            case 3:
                // Queue Operations
                int queueValue;
                for (int i = 1; i <= 5; ++i) {
                    cout << "Enter value to add to queue: ";
                    cin >> queueValue;
                    queue.enqueue(queueValue);
                }
                queue.dequeue();
                cout << "Queue after 5 enqueuing and 1 dequeue operations: ";
                queue.displayQueue();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
