#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end of the linked list
    void addNode(int value) {
        Node* newNode = new Node();
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

    // Function to display the elements of the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete the last node of the linked list
    void deleteLast() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Function to perform bubble sort on the linked list
    void bubbleSort() {
        if (head == nullptr || head->next == nullptr)
            return;

        bool swapped;
        Node* current;
        Node* last = nullptr;

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

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Stack class implemented using LinkedList
class Stack {
private:
    LinkedList list;

public:
    // Function to push an element onto the stack
    void push(int value) {
        list.addNode(value);
    }

    // Function to pop an element from the stack
    void pop() {
        list.deleteLast();
    }

    // Function to display the elements of the stack
    void display() {
        list.display();
    }
};

// Queue class implemented using LinkedList
class Queue {
private:
    LinkedList list;

public:
    // Function to enqueue an element into the queue
    void enqueue(int value) {
        list.addNode(value);
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        list.deleteLast();
    }

    // Function to display the elements of the queue
    void display() {
        list.display();
    }
};

int main() {
    int choice;
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on linked list" << endl;
        cout << "2. Operate on stack" << endl;
        cout << "3. Operate on queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                for (int i = 1; i <= 4; ++i) {
                    cout << "Enter value for node " << i << ": ";
                    cin >> value;
                    linkedList.addNode(value);
                }
                cout << "Linked list after adding 4 elements: ";
                linkedList.display();
                linkedList.bubbleSort();
                linkedList.deleteLast();
                cout << "Linked list after sorting elements and deleting last element: ";
                linkedList.display();
                break;
            }
            case 2: {
                int value;
                for (int i = 0; i < 5; ++i) {
                    cout << "Enter value to push on stack: ";
                    cin >> value;
                    stack.push(value);
                }
                cout << "Stack elements after 5 pushing and 1 pop operation: ";
                stack.display();
                stack.pop();
                break;
            }
            case 3: {
                int value;
                for (int i = 0; i < 5; ++i) {
                    cout << "Enter value to add to queue: ";
                    cin >> value;
                    queue.enqueue(value);
                }
                cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
                queue.display();
                queue.dequeue();
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
