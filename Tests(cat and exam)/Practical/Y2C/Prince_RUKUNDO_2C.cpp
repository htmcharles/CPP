#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// Operations on linked list
void operateLinkedList() {
    list<int> myList;
    int value;
    // Adding 4 nodes to the linked list
    cout << "Enter value for node 1: ";
    cin >> value;
    myList.push_back(value);
    cout << "Enter value for node 2: ";
    cin >> value;
    myList.push_back(value);
    cout << "Enter value for node 3: ";
    cin >> value;
    myList.push_back(value);
    cout << "Enter value for node 4: ";
    cin >> value;
    myList.push_back(value);
    // Displaying the linked list after adding elements
    cout << "Linked list after adding 4 elements: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Sorting the linked list
    myList.sort();
    // Deleting the last element of the linked list
    if (!myList.empty()) {
        myList.pop_back();
    }
    // Displaying the linked list after sorting and deleting the last element
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Operations on stack
void operateStack() {
    stack<int> myStack;
    int value;
    int n = 5;
    // Pushing 5 elements onto the stack
    for (int i = 0; i < n; i++) {
        cout << "Enter value to push onto stack: ";
        cin >> value;
        myStack.push(value);
    }
    // Displaying stack elements after pushing and popping one element
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    for (int i = 0; i < n-1; i++) {
    	myStack.pop();
        cout << myStack.top() << " ";
    }
    cout << endl;
}

// Operations on queue
void operateQueue() {
    queue<int> myQueue;
    int value;
    int n = 5;
    // Adding 5 elements to the queue
    for (int i = 0; i < n; ++i) {
        cout << "Enter value to add to queue: ";
        cin >> value;
        myQueue.push(value);
    }
    // Removing/deleting one element from the queue
    if (!myQueue.empty()) {
        myQueue.pop();
    }
    // Displaying queue elements after enqueue and dequeue operations
    cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
}


int main() {
    int choice;
    do {
        // Displaying menu and taking user's choice
        cout << "Enter your choice: " << endl;
        cout << "1. Operate on linked list" << endl;
        cout << "2. Operate on stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        // Performing operations based on user's choice
        switch (choice) {
            case 1:
                operateLinkedList();
                break;
            case 2:
                operateStack();
                break;
            case 3:
                operateQueue();
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






