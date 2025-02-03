#include <iostream>
#include <algorithm>
using namespace std;
// Linked List Node
struct Node {
    int data;
    Node* next;
};
// adding a node to the end of a linked list
void addNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
//sorting a linked list
void sortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;
    Node* current = head;
    while (current != nullptr) {
        Node* index = current->next;
        while (index != nullptr) {
            if (current->data > index->data)
                swap(current->data, index->data);
            index = index->next;
        }
        current = current->next;
    }
}
// deleting the last node of a linked list
void deleteLastNode(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}
//implementing stack operations
void stackOperations() {
    int stack[5];
    int top = -1;
    // Pushing 5 elements onto the stack
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Enter value to push onto stack: ";
        cin >> value;
        if (top < 4) {
            top++;
            stack[top] = value;
        } else {
            cout << "Stack is full. Cannot push." << endl;
            break;
        }
    }
    // Pop one element from the stack
    if (top != -1) {
        top--;
        cout << "Element popped from stack." << endl;
    } else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
}
//implementing queue operations
void queueOperations() {
    int queue[5];
    int front = 0;
    int rear = -1;
    // Adding 5 elements to the queue
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Enter value to add to queue: ";
        cin >> value;
        if (rear < 4) {
            rear++;
            queue[rear] = value;
        } else {
            cout << "Queue is full. Cannot add." << endl;
            break;
        }
    }
    // Removing one element from the queue
    if (front <= rear) {
        front++;
        cout << "Element removed from queue." << endl;
    } else {
        cout << "Queue is empty. Cannot remove." << endl;
    }
}
int main() {
    int choice;
    Node* head = nullptr;
    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Linked List" << endl;
        cout << "2. Stack" << endl;
        cout << "3. Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                // Adding 4 nodes to the linked list
                for (int i = 0; i < 4; i++) {
                    int value;
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> value;
                    addNode(head, value);
                }
                // Sorting the elements of the linked list
                sortLinkedList(head);
                // Deleting the last element
                deleteLastNode(head);
                cout << "Last element deleted from linked list." << endl;
                break;
            }
            case 2:
                stackOperations();
                break;
            case 3:
                queueOperations();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}