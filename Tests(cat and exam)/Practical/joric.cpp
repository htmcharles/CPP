#include <iostream>
#include <vector>
#include <string>

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

    // Function to add a node to the end of the linked list
    void addNode(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function to perform merge sort on the linked list
    Node* mergeSort(Node* start) {
        if (!start || !start->next)
            return start;

        Node* fast = start->next;
        Node* slow = start;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        Node* mid = slow->next;
        slow->next = nullptr;

        Node* left = mergeSort(start);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }

    // Function to sort the linked list
    void sortList() {
        head = mergeSort(head);
    }

    // Function to display the linked list
    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Stack class
class Stack {
private:
    static const int maxSize = 5;
    int stack[maxSize];
    int top;

public:
    Stack() : top(-1) {}

    // Function to check if the stack is full
    bool isFull() {
        return top == maxSize - 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to push element onto the stack
    void push(int value) {
        if (!isFull()) {
            stack[++top] = value;
        } else {
            cout << "Stack is full!" << endl;
        }
    }

    // Function to pop element from the stack
    void pop() {
        if (!isEmpty()) {
            cout << "Popped element: " << stack[top--] << endl;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // Function to display elements of the stack
    void displayStack() {
        for (int i = 0; i <= top; ++i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

// Queue class
class Queue {
private:
    static const int maxSize = 5;
    int queue[maxSize];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    // Function to check if the queue is full
    bool isFull() {
        return (rear == maxSize - 1 && front == 0) || (rear + 1 == front);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add element to the queue
    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty())
                front = 0;
            rear = (rear + 1) % maxSize;
            queue[rear] = value;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    // Function to remove element from the queue
    void dequeue() {
        if (!isEmpty()) {
            cout << "Removed element: " << queue[front++] << endl;
            if (front > rear)
                front = rear = -1;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Function to display elements of the queue
    void displayQueue() {
        int i = front;
        while (i != (rear + 1) % maxSize && i != -1) {
            cout << queue[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int choice;
    vector<string> dataList;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on Linked List" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            LinkedList linkl;
            for (int i = 0; i < 4; ++i) {
                int value;
                cout << "Enter value to add to linked list: ";
                cin >> value;
                linkl.addNode(value);
            }
            linkl.sortList();
            cout << "Linked list after sorting: ";
            linkl.displayList();
            cout << endl;
        } else if (choice == 2) {
            Stack stack;
            for (int i = 0; i < 5; ++i) {
                int value;
                cout << "Enter the value to push onto stack: ";
                cin >> value;
                stack.push(value);
            }
            stack.pop();
            cout << "Stack elements after 5 pushing and 1 pop operation: ";
            stack.displayStack();
            cout << endl;
        } else if (choice == 3) {
            Queue queue;
            for (int i = 0; i < 5; ++i) {
                int value;
                cout << "Enter the value to add to queue: ";
                cin >> value;
                queue.enqueue(value);
            }
            queue.dequeue();
            cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
            queue.displayQueue();
            cout << endl;
        } else if (choice == 0) {
            cout << "Exiting program......" << endl;
        } else {
            cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 0);

    return 0;
}
