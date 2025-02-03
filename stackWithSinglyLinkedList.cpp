#include <iostream>
using namespace std;

// Node class representing a stack node
class Node {
public:
    char data;
    Node* next;
    
    Node(char new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Stack class implemented using linked list
class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    
    // Push a character onto the stack
    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }
    
    // Pop a character from the stack
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        Node* temp = top;
        char poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to reverse a string using a stack implemented with linked list
string reverseStringUsingStack(const string &str) {
    Stack charStack;
    
    // Push all characters of the string onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }
    
    string reversedStr = "";
    
    // Pop characters from the stack to reverse the string
    while (!charStack.isEmpty()) {
        reversedStr += charStack.pop(); // Get top character
    }
    
    return reversedStr;
}

int main() {
    string str = "hello"; // Input string
    
    cout << "Given String: " << str << endl;
    
    string reversedStr = reverseStringUsingStack(str);
    
    cout << "Reversed String: " << reversedStr << endl;
    
    return 0;
}

