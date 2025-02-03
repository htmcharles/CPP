#include <iostream>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a node at the end of the linked list
void addNode(Node*& head, int data) {
    if (head == nullptr) {
        head = createNode(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

// Function to display the elements of the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        cout << "Linked list: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Function to sort the linked list
void sortLinkedList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return; // No need to sort if list is empty or has only one node
    }
    // Bubble sort algorithm
    bool swapped;
    Node* lastNode = nullptr;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != lastNode) {
            if (current->data > current->next->data) {
                // Swap data of adjacent nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastNode = current;
    } while (swapped);
}

// Function to delete the last element of the linked list
void deleteLastElement(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last element deleted. List is now empty." << endl;
        return;
    }
    Node* prev = nullptr;
    Node* current = head;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }
    delete current;
    prev->next = nullptr;
    cout << "Last element deleted." << endl;
}

// Function to operate on linked list
void operateLinkedList() {
    Node* linkedList = nullptr;
    int value;

    // Adding 4 nodes to the linked list
    cout << "Enter value for node 1: ";
    cin >> value;
    addNode(linkedList, value);
    cout << "Enter value for node 2: ";
    cin >> value;
    addNode(linkedList, value);
    cout << "Enter value for node 3: ";
    cin >> value;
    addNode(linkedList, value);
    cout << "Enter value for node 4: ";
    cin >> value;
    addNode(linkedList, value);

    // Displaying the linked list after adding elements
    cout << "Linked list after adding 4 elements: ";
    displayList(linkedList);

    // Sorting the linked list
    sortLinkedList(linkedList);
    
    // Deleting the last element
    deleteLastElement(linkedList);

    // Displaying the linked list after sorting and deletion
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    displayList(linkedList);
}

// Function to operate on stack
void operateStack() {
    const int maxSize = 5;
    int stackArray[maxSize];
    int top = -1; // Initialize top of the stack

    // Pushing 5 elements onto the stack
    cout << "Enter values to push onto stack: ";
    for (int i = 0; i < maxSize; ++i) {
        int value;
        cin >> value;
        if (top == maxSize - 1) {
            cout << "Stack is full. Cannot push more elements." << endl;
            break;
        }
        stackArray[++top] = value;
    }

    // Displaying stack elements after pushing
    cout << "Stack elements after pushing: ";
    for (int i = 0; i <= top; ++i) {
        cout << stackArray[i] << " ";
    }
    cout << endl;

    // Pop one element from stack
    if (top == -1) {
        cout << "Stack is empty. Cannot pop." << endl;
    } else {
        cout << "One element popped from stack: " << stackArray[top--] << endl;
    }
}

// Function to operate on queue
void operateQueue() {
    const int maxSize = 5;
    int queueArray[maxSize];
    int front = 0, rear = -1; // Initialize front and rear of the queue

    // Adding 5 elements to the queue
    cout << "Enter values to add to queue: ";
    for (int i = 0; i < maxSize; ++i) {
        int value;
        cin >> value;
        if (rear == maxSize - 1) {
            cout << "Queue is full. Cannot add more elements." << endl;
            break;
        }
        queueArray[++rear] = value;
    }

    // Removing/deleting one element from the queue
    if (front > rear) {
        cout << "Queue is empty. Cannot remove." << endl;
    } else {
        cout << "One element removed from queue: " << queueArray[front++] << endl;
    }
}

int main() {
    int choice;

    do {
        // Displaying menu and taking user's choice
        cout << "\nEnter your choice: \n";
        cout << "1. Operate on linked list\n";
        cout << "2. Operate on stack\n";
        cout << "3. Operate on Queue\n";
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
            case 3:
                operateQueue();
                break;
            case 0:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
