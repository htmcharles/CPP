#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    // Function to add a node to the linked list
    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to sort the linked list and delete the last element
    void sortAndDeleteLast() {
        if (head == NULL)
            return;
        
        vector<int> values;
        Node* temp = head;
        while (temp != NULL) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        sort(values.begin(), values.end());
        head = NULL;
        for (int i = 0; i < values.size() - 1; ++i) {
            addNode(values[i]);
        }
    }
};

class Stack {
private:
    vector<int> stack;
public:
    void push(int data) {
        stack.push_back(data);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    bool isEmpty() {
        return stack.empty();
    }

    void display() {
        cout << "Stack elements:";
        for (int i = stack.size() - 1; i >= 0; --i) {
            cout << " " << stack[i];
        }
        cout << endl;
    }
};

class Queue {
private:
    vector<int> queue;
public:
    void enqueue(int data) {
        queue.push_back(data);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int front = queue.front();
        queue.erase(queue.begin());
        return front;
    }

    bool isEmpty() {
        return queue.empty();
    }

    void display() {
        cout << "Queue elements:";
        for (int i = 0; i < queue.size(); ++i) {
            cout << " " << queue[i];
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Operate on linked List" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                for (int i = 1; i <= 4; ++i) {
                    cout << "Enter value for node " << i << ": ";
                    cin >> value;
                    linkedList.addNode(value); // Modified here
                }
                cout << "Linked List after adding 4 elements: ";
                linkedList.display();
                linkedList.sortAndDeleteLast();
                cout << "Linked List after sorting its elements and deletion of the last element: ";
                linkedList.display();
                break;
            case 2:
                int val;
                for (int i = 0; i < 5; ++i) {
                    cout << "Enter value to push onto stack: ";
                    cin >> val;
                    stack.push(val);
                }
                
                cout << "Stack elements after 5 pushing and 1 pop operations: ";
                stack.pop();
                stack.display();
                break;
            case 3:
                int v;
                for (int i = 0; i < 5; ++i) {
                    cout << "Enter value to add to queue: ";
                    cin >> v;
                    queue.enqueue(v);
                }
                
                cout << "Queue elements after 5 enqueues and 1 dequeue operation: ";
                queue.dequeue();
                queue.display();
                break;
            case 0:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } 
while (choice != 0);
    return 0;
}

