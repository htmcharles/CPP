#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Function prototypes for each data structure
void operateOnLinkedList();
void operateOnStack();
void operateOnQueue();

// Implementation of linked list operations
void operateOnLinkedList() {
    vector<int> list;

    // Function to add nodes to the linked list
    for(int i = 0; i < 4; i++) {
        int num;
        cout << "Enter value for node " << i+1 << ": ";
        cin >> num;
        list.push_back(num);
    }

    // Function to sort the linked list
    for(int i = 0; i < list.size()-1; i++) {
        for(int j = 0; j < list.size()-i-1; j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    // Function to delete the last element of the linked list
    list.pop_back();
}

// Implementation of stack operations
void operateOnStack() {
    stack<int> stack;

    // Function to push elements onto the stack
    for(int i = 0; i < 5; i++) {
        int num;
        cout << "Enter value to push onto stack: ";
        cin >> num;
        stack.push(num);
    }

    // Function to pop elements from the stack
    if(stack.empty()) {
        cout << "Stack is empty.\n";
    } else {
        stack.pop();
    }
}

// Implementation of queue operations
void operateOnQueue() {
    queue<int> queue;

    // Function to add elements to the queue
    for(int i = 0; i < 5; i++) {
        int num;
        cout << "Enter value to add to queue: ";
        cin >> num;
        queue.push(num);
    }
}

int main() {
    int choice;

    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Operate on linked list\n";
        cout << "2. Operate on stack\n";
        cout << "3. Operate on queue\n";
        cout << "0. Exit\n";
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
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

