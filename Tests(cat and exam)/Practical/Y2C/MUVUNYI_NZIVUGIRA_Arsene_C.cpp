/* Written by MUVUNYI NZIVUGIRA Arsene Year 2C
It may not look like the one on my paper exactly but it is almost similar
The one here is more optimized  
**/


#include <iostream>
using namespace std;

//Node defintion
class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

//Linked list definition
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


//Printing the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << "\n";
    }


//Sorting the linked list
    void sortList() {
        Node* i = head;
        Node* j = nullptr;
        if (head == nullptr) {
            return;
        }
        while (i != nullptr) {
            j = i->next;
            while (j != nullptr) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
                j = j->next;
            }
            i = i->next;
        }
    }

//Deleting the last element
    void removeLast() {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            removeLast();
        }
    }
};


//Defining the stack
class Stack {
public:
    int top;
    unsigned capacity;
    int* array;
    Stack(int cap) : capacity(cap), top(-1) {
        array = new int[capacity];
    }

//Adding an element to the stack
    void push(int data) {
    	
    	//check if stack is full
        if (top == (int)capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        array[++top] = data;
    }

//Removing an element from the stack
    int pop() {
    	
    	//check if stack is empty
        if (top == -1) {
            cout << "Stack Underflow\n";
            return 0;
        }
        return array[top--];
    }

//Printing the stack
    void printStack() {
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << "\n";
    }

    ~Stack() {
        delete[] array;
    }
};


//Defining the queue
class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
    Queue(int cap) : capacity(cap), front(0), size(0), rear(capacity - 1) {
        array = new int[capacity];
    }


	//adding data to the queue
    void enqueue(int data) {
    	
    	//check if queue is full
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = data;
        size++;
    }

	//removing data from the queue
    int dequeue() {
    	
    	//check if queue is empty
        if (size == 0) {
            cout << "Queue is empty\n";
            return 0;
        }
        int data = array[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }


//Printing the queue
    void printQueue() {
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }

    ~Queue() {
        delete[] array;
    }
};


//Combination of all linked list operatinons
void listOperations() {
    LinkedList list;
    for (int i = 0; i < 4; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        int data;
        cin >> data;
        list.append(data);
    }
    cout << "Linked List after adding 4 elements: ";
    list.printList();
    list.sortList();
    list.removeLast();
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    list.printList();
}

void stackOperations() {
    Stack stack(5);
    for (int i = 0; i < 5; i++) {
        cout << "Enter value to push onto stack: ";
        int data;
        cin >> data;
        stack.push(data);
    }
    stack.pop();
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    stack.printStack();
}


//Combination of all queue operations
void queueOperations() {
    Queue queue(5);
    for (int i = 0; i < 5; i++) {
        cout << "Enter value to add to queue: ";
        int data;
        cin >> data;
        queue.enqueue(data);
    }
    queue.dequeue();
    cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
    queue.printQueue();
}


//main function
int main() {
    int choice;
    do {
        cout << "Enter your choice:\n"
             << "1. Operate on Linked List\n"
             << "2. Operate on Stack\n"
             << "3. Operate on Queue\n"
             << "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                listOperations();
                break;
            case 2:
                stackOperations();
                break;
            case 3:
                queueOperations();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);
    return 0;
}

