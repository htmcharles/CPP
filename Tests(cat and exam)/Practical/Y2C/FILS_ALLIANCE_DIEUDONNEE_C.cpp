#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void operateLinkedList() {
    list<int> linkedList;
    
    // Add 4 nodes
    cout << "Adding elements to linked list:\n";
    for (int i = 0; i < 4; ++i) {
        int val;
        cout << "Enter value for linked list node " << i + 1 << ": ";
        cin >> val;
        linkedList.push_back(val);
    }
    
    // Display linked list after adding elements
    cout << "Linked List after adding elements: ";
    for (list<int>::iterator it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Sort elements
    linkedList.sort();
    
    // Display linked list after sorting
    cout << "Linked List after sorting: ";
    for (list<int>::iterator it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Delete the last element
    linkedList.pop_back();
    
    cout << "Linked List operation completed.\n";
}

void operateStack() {
    stack<int> stk;
    
    // Push 5 elements
    cout << "Pushing elements to stack:\n";
    for (int i = 0; i < 5; ++i) {
        int val;
        cout << "Enter value to push onto stack: ";
        cin >> val;
        stk.push(val);
    }
    
    // Display elements pushed to stack
    cout << "Elements pushed onto stack: ";
    stack<int> tempStk = stk; // Create a temporary stack to display elements
    while (!tempStk.empty()) {
        cout << tempStk.top() << " ";
        tempStk.pop();
    }
    cout << endl;
    
    // Pop one element
    if (!stk.empty()) {
        cout << "Popped element from stack: " << stk.top() << endl;
        stk.pop();
    } else {
        cout << "Stack is empty, cannot pop.\n";
    }
    
    cout << "Stack operation completed.\n";
}

void operateQueue() {
    queue<int> q;
    
    // Add 5 elements
    cout << "Enqueuing elements to queue:\n";
    for (int i = 0; i < 5; ++i) {
        int val;
        cout << "Enter value to enqueue: ";
        cin >> val;
        q.push(val);
    }
    
    // Display elements enqueued to queue
    cout << "Elements enqueued into queue: ";
    queue<int> tempQ = q; // Create a temporary queue to display elements
    while (!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;
    
    // Remove one element
    if (!q.empty()) {
        cout << "Dequeued element: " << q.front() << endl;
        q.pop();
    } else {
        cout << "Queue is empty, cannot dequeue.\n";
    }
    
    cout << "Queue operation completed.\n";
}

int main() {
    int choice;
    
    do {
        cout << "Choose operation:\n"
             << "1. Linked List\n"
             << "2. Stack\n"
             << "3. Queue\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        
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
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}

