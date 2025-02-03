#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
    	this->data=val;
    	next=NULL;
	}
};

// Linked list class
class LinkedList {
    Node* head;
    
public:
	LinkedList(){
		head=NULL;
	}
    
    // Function to insert a node at the end of the linked list
    void insertList(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Function to display the linked list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Function to sort the linked list (bubble sort)
    void sortList() {
        if (head == nullptr || head->next == nullptr)
            return;
        
        Node* current = head;
        Node* nextNode = nullptr;
        bool swapped;
        
        do {
            swapped = false;
            current = head;
            
            while (current->next != nextNode) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            nextNode = current;
        } while (swapped);
    }
};

// Stack class using linked list
class Stack {

    Node* top;
public:
	Stack(){
		top=NULL;
	}

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop an element." << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display elements of the stack
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Queue class using linked list
class Queue {
    Node* front;
    Node* rear;

public:
	Queue(){
		front=NULL;
		rear=NULL;
	}


    // Function to add an element to the queue (Enqueue)
    void push(int data) {
        Node* newNode = new Node(data);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the queue (Dequeue)
    void pop() {
        if (isEmpty()) {
            cout << "Underflow error. Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display elements of the queue
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void linkedListOperations()
{
    LinkedList linkedList;

    // Add 4 nodes
    for (int i = 0; i < 4; i++)
    {
        int data;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        linkedList.insertList(data);
    }

    cout << "Linked List after inserting 4 elements:" << endl;
    linkedList.displayList();

    // Sort elements
    linkedList.sortList();

    cout << "Linked List after sorting its element and delection of the last element: ";
    linkedList.displayList();
}

void stackOperations()
{
    Stack stack;

    // Push 5 elements
    for (int i = 0; i < 5; i++)
    {
        int data;
        cout << "Enter value to push onto stack " << i + 1 << ": ";
        cin >> data;
        stack.push(data);
    }

    // Remove the last element
    stack.pop();

    cout << "Stack elements after 5 pushing and 1 pop operations: " ;
    stack.display();
}

void queueOperations()
{
    Queue queue;

    // Add 5 elements
    for (int i = 0; i < 5; i++)
    {
        int data;
        cout << "Enter element to add to queue " << i + 1 << ": ";
        cin >> data;
        queue.push(data);
}

    // Remove the first element (dequeue)
    queue.pop();

    cout << "Queue elemets after 5 enqueue and 1 dequeue operations:" ;
    queue.display();
}

int main()
{
    int choice;

    do
    {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on Linked List\n2. Operate on Stack\n3. Operate on Queue\n0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            linkedListOperations();
            break;
        case 2:
            stackOperations();
            break;
        case 3:
            queueOperations();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}
