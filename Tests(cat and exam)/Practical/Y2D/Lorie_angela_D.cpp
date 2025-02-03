#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// Class for linked list operations
class LinkedList {
private:
    list<int> myList;
    
public:
    // Function to add nodes to the linked list
    void addNodes() {
        int value;
        
        // Prompt user to enter values for each node
        for (int i = 0; i < 4; ++i) {
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> value;
            myList.push_back(value);
        }
    }
    
    // Function to sort the elements and delete the last element from the linked list
    void sortAndDeleteLast() {
        // Sort the elements in ascending order
        myList.sort();
        // Delete the last element if the list is not empty
        if (!myList.empty()) {
            myList.pop_back();
        }
    }
    
    // Function to display the elements of the linked list
    void display() {
        // Display the elements of the linked list
        cout << "Linked list elements: ";
        for (auto it = myList.begin(); it != myList.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    };
};

// Class for stack operations
class MyStack {
private:
    stack<int> myStack;
    
public:
    // Function to push elements onto the stack
    void pushElements() {
        int value;
        
        // Prompt user to enter values to push onto the stack
        for (int i = 0; i < 5; ++i) {
            cout << "Enter value to push onto stack: ";
            cin >> value;
            myStack.push(value);
        }
    }
    
    // Function to pop an element from the stack
    void popElement() {
        // Pop an element if the stack is not empty
        if (!myStack.empty()) {
            myStack.pop();
        } else {
            // Display message if stack is empty
            cout << "Stack is empty. Cannot pop.\n";
        }
    }
    
    // Function to display the elements of the stack
    void display() {
        // Display the elements of the stack
        cout << "Stack elements: ";
        stack<int> tempStack = myStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

// Class for queue operations
class MyQueue {
private:
    queue<int> myQueue;
    
public:
    // Function to enqueue elements into the queue
    void enqueueElements() {
        int value;
        
        // Prompt user to enter values to push onto the queue
        for (int i = 0; i < 5; ++i) {
            cout << "Enter value to push onto queue: ";
            cin >> value;
            myQueue.push(value);
        }
    }
    
    // Function to dequeue an element from the queue
    void dequeueElement() {
        // Dequeue an element if the queue is not empty
        if (!myQueue.empty()) {
            myQueue.pop();
        } else {
            // Display message if queue is empty
            cout << "Queue is empty. Cannot dequeue.\n";
        }
    }
    
    // Function to display the elements of the queue
    void display() {
        // Display the elements of the queue
        cout << "Queue elements: ";
        queue<int> tempQueue = myQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    int choice;
    LinkedList linkedList;
    MyStack myStack;
    MyQueue myQueue;
    
    // Main menu loop
    do {
        // Display menu options
        cout << "Enter your choice\n"
             << "1. operate on LL\n"
             << "2. operate on Stack\n"
             << "3. operate on Queue\n"
             << "0. Exit\n";
        cin >> choice;
        
        // Perform operations based on user choice
    

        
        switch (choice) {
            case 1:
                linkedList.addNodes();
                linkedList.display();
                linkedList.sortAndDeleteLast();
                linkedList.display();
                break;
            case 2:
                myStack.pushElements();
                myStack.display();
                myStack.popElement();
                myStack.display();
                break;
            case 3:
                myQueue.enqueueElements();
                myQueue.display();
                myQueue.dequeueElement();
                myQueue.display();
                break;
            case 0:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 0);
    
    return 0;
}
