#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
using namespace std;
// Printing the list
void printList(const list<int>& lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
// linked list operations
void operateOnLinkedList() {
    list<int> linkedList;
    int value;
    for (int i = 0; i < 4; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        linkedList.push_back(value);
    }
    cout << "Linked list after adding 4 elements: ";
    linkedList.sort();
    printList(linkedList);
    if (!linkedList.empty()) {
        linkedList.pop_back();
        cout << "Linked list after sorting its element and deletion of the last element: ";
        printList(linkedList);
    } else {
        cout << "Linked list is empty." << endl;
    }
}
//stack operations
void operateOnStack() {
    stack<int> stk;
    stack<int> tempStack; // Temporary stack to hold elements temporarily

    int value;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter value to push onto stack: ";
        cin >> value;
        stk.push(value);
    }

    // Find and pop the last added element
    int lastAdded = stk.top();
    while (!stk.empty()) {
        if (stk.top() == lastAdded) {
            stk.pop();
            break;
        }
        tempStack.push(stk.top());
        stk.pop();
    }

    // Restore elements to stk
    while (!tempStack.empty()) {
        stk.push(tempStack.top());
        tempStack.pop();
    }

    cout << "Stack elements after 5 pushing operations and 1 pop operation: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}
    
//queue operations
void operateOnQueue() {
    queue<int> que;
    queue<int> tempQueue; // Temporary queue to hold elements temporarily

    int value;
    cout << "Enter values to add to the queue (5 values):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter value to add to queue: ";
        cin >> value;
        que.push(value);
    }

    // Pop the first entered item
    int firstEntered = que.front();

    // Enqueue the rest of the elements to tempQueue
    que.pop(); 
    while (!que.empty()) {
        tempQueue.push(que.front());
        que.pop();
    }

    // Restore elements to que (except the first entered item)
    while (!tempQueue.empty()) {
        que.push(tempQueue.front());
        tempQueue.pop();
    }

    cout << "Queue elements after 5 enqueue operations and 1 dequeue operation: ";
    while (!que.empty()) {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}
int main() {
    int choice;
    bool running = true;
    while (running) {
        cout << "Enter your choice:" << endl;
        cout << "1.Operate on Linked List" << endl;
        cout << "2.Operate on Stack" << endl;
        cout << "3.Operate on Queue" << endl;
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
                running = false;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3." << endl;
        }
    }
    return 0;
}
