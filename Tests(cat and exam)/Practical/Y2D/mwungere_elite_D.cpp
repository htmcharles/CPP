#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// Function to print the contents of a list
template <typename T>
void printList(list<T>& myList) {
    typename list<T>::iterator it;
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Function to print stack elements after popping specified number of elements
void printStackAfterPop(stack<int>& myStack, int numPop) {
    for (int i = 0; i < numPop && !myStack.empty(); ++i) {
        myStack.pop();
    }
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
	cout << endl;
	cout << endl;    
}

// Function to print queue elements after dequeuing specified number of elements
void printQueueAfterDequeue(queue<int>& myQueue, int numDequeue) {
    for (int i = 0; i < numDequeue && !myQueue.empty(); ++i) {
        myQueue.pop();
    }
    cout << "Queue elements after 5 enqueue and 1 dequeue opearations: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "Enter your choice: " << endl;
        cout << "1. Linked List" << endl;
        cout << "2. Stack" << endl;
        cout << "3. Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Linked List
                list<int> myList;

                // Add 4 nodes
                for (int i = 0; i < 4; ++i) {
                    int value;
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> value;
                    myList.push_back(value);
                }

                // Print added nodes
                cout << "Linked list after adding 4 elements: ";
                printList(myList);

                // Sort elements
                myList.sort();

                // Delete the last element
                if (!myList.empty()) {
                    myList.pop_back();
                    cout << "Linked list after sorting its elements and deletion of the last element: ";
                    printList(myList);
                    cout << endl;
                    cout << endl;
                } else {
                    cout << "Linked list is empty." << endl;
                }

                // Print updated linked list
                cout << "Updated linked list: ";
                printList(myList);

                break;
            }
            case 2: {
                // Stack
                stack<int> myStack;

                // Push 5 elements
                
                for (int i = 0; i < 5; ++i) {
                	cout << "Enter value to push onto stack: ";
                    int value;
                    cin >> value;
                    myStack.push(value);
                }

                // Print statement after pushing and popping
                printStackAfterPop(myStack, 1);

                break;
            }
            case 3: {
                // Queue
                queue<int> myQueue;

                // Add 5 elements
                
                for (int i = 0; i < 5; ++i) {
                	cout << "Enter value to add to queue: ";
                    int value;
                    cin >> value;
                    myQueue.push(value);
                }

                // Print statement after enqueuing and dequeuing
                printQueueAfterDequeue(myQueue, 1);

                break;
            }
            case 0:
                // Exit the program
                running = false;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    cout << "Exiting program..." << endl;

    return 0;
}

