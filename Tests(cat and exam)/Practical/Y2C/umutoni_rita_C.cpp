#include <iostream>
using namespace std;

// Queue implementation using normal arrays
int queue[100], n = 100, front = -1, rear = -1;

void enqueue() {
    int val;
    if (rear == n - 1)
        cout << "Queue Overflow/Full" << endl;
    else {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue : " << endl;
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow/Empty" << endl;
        return;
    }
    cout << "Element deleted from queue is : " << queue[front] << endl;
    front++;
}

// Stack implementation using classes
class Stack {
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack() {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
    }

    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    int size() { return nextIndex; }

    bool isEmpty() { return nextIndex == 0; }

    void push(int ele) {
        if (nextIndex == capacity) {
            cout << "Stack full" << endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return;
        }
        nextIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return 0;
        }
        return arr[nextIndex - 1];
    }
};

// Linked list traversal
struct Node {
public:
    int data;
    Node* next;
};

void display(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    int choice;
    Stack myStack(5); // Stack with capacity 5

    do {
        cout << "\nEnter your choice\n"
             << "1. Operate on Queue\n"
             << "2. Operate on Stack\n"
             << "3. Display Linked List\n"
             << "0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n1. Enqueue\n"
                     << "2. Dequeue\n"
                     << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        enqueue();
                        break;
                    case 2:
                        dequeue();
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
                break;

            case 2:
                cout << "\n1. Push\n"
                     << "2. Pop\n"
                     << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        int ele;
                        cout << "Enter element to push: ";
                        cin >> ele;
                        myStack.push(ele);
                        break;
                    case 2:
                        myStack.pop();
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
                break;

            case 3:
                cout << "Displaying Linked List\n";
                // Assuming you have a linked list initialized here
                break;

            case 0:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
