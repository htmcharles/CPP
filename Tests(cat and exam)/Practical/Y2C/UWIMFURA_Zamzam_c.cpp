#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// Function to operate on linked list

void operateLinkedList() {
    list<int> myList;
    int value;
    
    // Adding 4 nodes to the linked list
    cout << "Enter value for 4 nodes:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Enter value for node " << i+1 << ": ";
        cin >> value;
        myList.push_back(value);
    }
    
    // Displaying the linked list after adding elements
    cout << "Linked list after adding 4 elements: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Sorting the linked list
    myList.sort();
    // Deleting the last element
    if (!myList.empty()) {
        myList.pop_back();
    }
    // Displaying the linked list after sorting and deletion
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Function to operate on stack
void operateStack() {
    stack<int> myStack;
    int value;
    // Pushing 5 elements onto the stack
    cout << "Enter value to push onto stack:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Enter value for element " << i+1 << ": ";
        cin >> value;
        myStack.push(value);
    }
    // Displaying stack elements after pushing
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    for (int i = 0; i < 5; ++i) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        // Displaying menu and taking user's choice
        cout << "\nEnter your choice: \n";
        cout << "1. Operate on linked list\n";
        cout << "2. Operate on stack\n";
        cout << "0. Exit\n";
        cin >> choice;
        // Performing operations based on user's choice
        switch (choice) {
            case 1:
                operateLinkedList();
                break;
            case 2:
                operateStack();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
