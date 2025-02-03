#include <iostream>
using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Linked List Class
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

 void sortList() {
        Node* i = head;
        Node* j = nullptr;
        if (head == nullptr) {
            return;
        }
        while (i != nullptr) {
            j = i->next;
            while (j != nullptr) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    // Function to delete the last element from the linked list
    void deleteLastNode() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* second_last = head;
        while (second_last->next->next != NULL) {
            second_last = second_last->next;
        }

        delete second_last->next;
        second_last->next = NULL;
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
};

// Stack Class
class Stack {
private:
    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int nextIndex;

public:
    Stack() {
        nextIndex = -1;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return (nextIndex == -1);
    }

    // Function to check if stack is full
    bool isFull() {
        return (nextIndex == MAX_SIZE - 1);
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full." << endl;
            return;
        }
        data[++nextIndex] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        nextIndex--;
    }

    // Function to display the stack
    void display() {
        for (int i = nextIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Queue Class
class Queue {
private:
    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = rear = -1;
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if queue is full
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
    }

    // Function to enqueue an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            ++rear;
        }

        data[rear] = value;
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == MAX_SIZE - 1)
                front = 0;
            else
                ++front;
        }
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                cout << data[i++] << " ";
            }
        } else {
            while (i < MAX_SIZE) {
                cout << data[i++] << " ";
            }
            i = 0;
            while (i <= rear) {
                cout << data[i++] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int choice;

    do {
        cout << "Enter your choice:\n1. Operate on Linked List\n2. Operate on Stack\n3. Operate on Queue\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                LinkedList linkedList;
                int value;
                for (int i = 0; i < 4; ++i) {
                    cout<<"Enter value for node "<<i<<": ";
                    cin >> value;
                    linkedList.addNode(value);
                }

                cout << "Linked list after adding 4 elements: ";
                linkedList.display();

                // Sorting the linked list
                linkedList.sortList();

                // Deleting the last element
                linkedList.deleteLastNode();

                cout << "Linked List after sorting its elements and deleting last element: ";
                linkedList.display();
                break;
            }
            case 2: {
                Stack stack;
                int value;
                for (int i = 0; i < 5; ++i) {
                cout << "Enter value to push onto stack: ";
                    cin >> value;
                    stack.push(value);
                }


                // Popping one element
                stack.pop();

                cout << "Stack after pushing and popping operations: ";
                stack.display();
                break;
            }
            case 3: {
                Queue queue;
                int value;
                for (int i = 0; i < 5; ++i) {
                cout << "Enter value to add to queue: ";
                    cin >> value;
                    queue.enqueue(value);
                }


                // Dequeuing one element
                queue.dequeue();

                cout << "Queue elements after 5 enqueue and 1 dequeue: ";
                queue.display();
                break;
            }
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
