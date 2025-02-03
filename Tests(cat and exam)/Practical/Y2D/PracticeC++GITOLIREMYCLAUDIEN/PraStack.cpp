

#include <iostream>

using namespace std;

int* stack = NULL;
int top = -1;
int capacity = 0;

// Function to check if the stack is full
bool isFull() {
    return top == capacity - 1;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int data) {
    if (isFull()) {
        // Double the capacity when the stack is full
        int newCapacity = (capacity == 0) ? 1 : 2 * capacity;
        int* newStack = new int[newCapacity];
        for (int i = 0; i <= top; ++i) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        capacity = newCapacity;
    }
    top++;
    stack[top] = data;
    cout << data << " pushed successfully." << endl;
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        cout << "Stack underflow!" << endl;
        return;
    }
    int data = stack[top];
    top--;
    cout << data << " popped successfully." << endl;
}

// Function to display the stack elements
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, data;

    do {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to push: ";
            cin >> data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    // Free the dynamically allocated memory
    delete[] stack;

    return 0;
}



