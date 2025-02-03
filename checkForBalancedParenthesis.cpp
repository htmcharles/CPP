//C++ program to implement to check for balanced parathesisi using a linked list
#include <iostream>
using namespace std;

// Node structure for a stack
struct Node {
    char data;   // Character data
    Node* next;  // Pointer to the next node
    
    // Constructor to initialize a node with a given character
    Node(char c) : data(c), next(nullptr) {}
};

// LinkedList-based stack class
class LinkedListStack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    LinkedListStack() : top(nullptr) {}

    // Pushes a character onto the stack
    void push(char c) {
        Node* newNode = new Node(c);  // Create a new node
        newNode->next = top;          // Link the new node to the current top
        top = newNode;                // Update the top pointer to the new node
    }

    // Pops a character from the stack and returns it
    char pop() {
        if (top == nullptr) return '\0';  // Return null character if the stack is empty
        char c = top->data;              // Store the character at the top
        Node* temp = top;                // Temporarily store the top node
        top = top->next;                 // Move the top pointer to the next node
        delete temp;                     // Delete the old top node to free memory
        return c;                        // Return the popped character
    }

    // Checks if the stack is empty
    bool isEmpty() {
        return top == nullptr;  // Return true if the stack is empty (top is null)
    }
};

// Function to check if a string has balanced parentheses
bool isBalanced(const string& s) {
    LinkedListStack stack;  // Create an empty stack

    // Iterate over each character in the string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } 
        // For closing brackets, check if they match the top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;  // If the stack is empty, no matching opening bracket

            char top = stack.pop();  // Pop the top character from the stack
            // Check if the popped character matches the corresponding opening bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Mismatch found
            }
        }
    }
    return stack.isEmpty();  // If the stack is empty after processing, the string is balanced
}

int main() {
    string s = "{([])}";  // Example input string
    if (isBalanced(s))     // Check if the string is balanced
        cout << "true";     // Output true if balanced
    else
        cout << "false";    // Output false if not balanced
    return 0;
}

