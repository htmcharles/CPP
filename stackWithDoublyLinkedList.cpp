#include<iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize the Node
    Node(int new_data) {
        data = new_data;
        next = nullptr;
        prev = nullptr;
    }
};

// Class to implement stack using a doubly linked list
class Stack {
    Node* head; // Top of the stack

public:
    // Constructor to initialize the stack
    Stack() { this->head = nullptr; }

    // Function to check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to push an element onto the stack
    void push(int new_data) {
        Node* new_node = new Node(new_data);
        if (!new_node) {
            cout << "\nStack Overflow";
            return;
        }
        if (head != nullptr) {
            head->prev = new_node;
        }
        new_node->next = head;
        head = new_node;
    }

    // Function to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "\nStack Underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Function to return the top element of the stack
    int peek() {
        if (!isEmpty()) {
            return head->data;
        } else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
    }
};

// Driver program to test the stack implementation
int main() {
    Stack st;

    // Push elements onto the stack
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // Removing two elements from the top
    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}

