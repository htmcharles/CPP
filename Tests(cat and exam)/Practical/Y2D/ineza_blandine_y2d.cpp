#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// Function to add 4 nodes to a linked list, sort its elements, and delete the last element
void operateOnLinkedList() {
    list<int> linkedList;

    // Add 4 nodes to the linked list
    for (int i = 0; i < 4; ++i) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        linkedList.push_back(value);
    }

    // Display linked list after adding 4 elements
    cout << "Linked list after adding 4 elements: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;

    // Sort the linked list
    linkedList.sort();

    // Delete the last element
    linkedList.pop_back();

    // Display linked list after sorting and deleting the last element
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;
}

// Function to operate on stack
void operateOnStack() {
    stack<int> stk;

    // Push 5 elements to the stack
    for (int i = 0; i < 5; ++i) {
        int value;
        cout << "Enter value to push onto stack: ";
        cin >> value;
        stk.push(value);
    }

    // Check if stack is empty before popping
    if (!stk.empty()) {
        // Pop one element
        stk.pop();
        cout << "One element popped from stack." << endl;
    } else {
        cout << "Stack is empty, cannot pop." << endl;
    }
}

// Function to operate on queue
void operateOnQueue() {
    queue<int> q;

    // Add 5 elements to the queue
    for (int i = 0; i < 5; ++i) {
        int value;
        cout << "Enter value to add to queue: ";
        cin >> value;
        q.push(value);
    }

    // Remove/delete one element
    if (!q.empty()) {
        q.pop();
        cout << "One element removed from queue." << endl;
    } else {
        cout << "Queue is empty, cannot remove." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on linked list" << endl;
        cout << "2. Operate on stack" << endl;
        cout << "3. Operate on queue" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                operateOnLinkedList();
                break;
            case 2:
                operateOnStack();
                break;
            case 3:
                operateOnQueue();
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


