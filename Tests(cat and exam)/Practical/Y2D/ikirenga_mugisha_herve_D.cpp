#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Function prototypes
void linkedListOperations();
void stackOperations();
void queueOperations();

int main() {
    int choice;

    do {
        // Display menu
        cout << "Choose an option:" << endl;
        cout << "1. Linked List" << endl;
        cout << "2. Stack" << endl;
        cout << "3. Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                linkedListOperations();
                break;
            case 2:
                stackOperations();
                break;
            case 3:
                queueOperations();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

// Linked list operations
void linkedListOperations() {
    list<int> linkedList;

    // Add 4 nodes to the linked list
    for (int i = 0; i < 4; i++) {
        int data;
        cout << "Enter data for node " << i+1 << ": ";
        cin >> data;
        linkedList.push_back(data);
    }

    // Sort the elements of the linked list
    linkedList.sort();

    // Delete the last element of the linked list
    linkedList.pop_back();

    cout << "Linked list operations completed." << endl;
}

// Stack operations
void stackOperations() {
    stack<int> myStack;

    // Push 5 elements onto the stack
    for (int i = 0; i < 5; i++) {
        int data;
        cout << "Enter data for element " << i+1 << ": ";
        cin >> data;
        myStack.push(data);
    }

    // Check if the stack is empty before popping an element
    if (!myStack.empty()) {
        // Pop one element from the stack
        myStack.pop();
        cout << "Element popped from stack." << endl;
    } else {
        cout << "Stack is empty. Cannot pop element." << endl;
    }
}

// Queue operations
void queueOperations() {
    queue<int> myQueue;

    // Add 5 elements to the queue
    for (int i = 0; i < 5; i++) {
        int data;
        cout << "Enter data for element " << i+1 << ": ";
        cin >> data;
        myQueue.push(data);
    }

    // Remove one element from the queue
    if (!myQueue.empty()) {
        myQueue.pop();
        cout << "Element removed from queue." << endl;
    } else {
        cout << "Queue is empty. Cannot remove element." << endl;
    }
}
