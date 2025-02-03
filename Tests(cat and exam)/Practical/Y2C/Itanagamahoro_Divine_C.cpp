#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Linked List class
class LinkedList {
	
public:
    Node* head;

public:
    LinkedList() : head(NULL) {} 

    // Function to add a node to the linked list
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to sort linked list using merge sort
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = NULL;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    Node* mergeSort(Node* start) {
        if (!start || !start->next)
            return start;

        Node* slow = start;
        Node* fast = start->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = NULL;

        Node* left = mergeSort(start);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }
    // Function to delete the last element of the linked list
    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // Function to print the linked list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Stack class
class Stack {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push element onto stack
    void push(int val) {
        if (!isFull()) {
            arr[++top] = val;
        } else {
            cout << "Stack is full!" << endl;
        }
    }

    // Function to pop element from stack
    void pop() {
        if (!isEmpty()) {
            cout << "The Popped element: " << arr[top--] << endl;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // Function to print the stack
    void print() {
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Queue class
class Queue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    // Function to check if queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Function to check if queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to add element to queue
    void enqueue(int val) {
        if (!isFull()) {
            arr[rear] = val;
            rear = (rear + 1) % MAX_SIZE;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    // Function to remove element from queue
    void dequeue() {
        if (!isEmpty()) {
            cout << "Dequeued element: " << arr[front++] << endl;
            front %= MAX_SIZE;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Function to print the whole queue
    void print() {
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
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
        cout << "Enter your choice:" << endl;
        cout << "1. Linked Lists" << endl;
        cout << "2. Stack" << endl;
        cout << "3. Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                int val;
                for (int i = 0; i < 4; ++i) {
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> val;
                    linkedList.addNode(val);
                }
                cout << "Linked List after adding 4 elements: ";
                linkedList.print();
                linkedList.mergeSort(linkedList.head);
                linkedList.deleteLast();
                cout << "Linked List after Sorting its elements and deletion of the last element: ";
                linkedList.print();
                break;
            case 2:
                int num;
                
                for (int i = 0; i < 5; ++i) {
                	cout << "Enter value to push onto stack:" << endl;
                    cin >> num;
                    stack.push(num);
                }
                cout << "Stack elements after 5 pushing and 1 pop operation: ";
                stack.pop();
                stack.print();
                break;
            case 3:
                
                for (int i = 0; i < 5; ++i) {
                	cout << "Enter value to add to queue:" << endl;
                    cin >> num;
                    queue.enqueue(num);
                }
                cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
                queue.dequeue();
                queue.print();
                break;
            case 0:
                cout << "Exiting program...." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
