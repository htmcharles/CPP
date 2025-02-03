#include <iostream>
#include <cstdlib>

using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void addNode(int value) {
        Node* newNode = new Node();
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
    void sortList() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr) {
            index = current->next;

            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    void deleteLastElement() {
        if (head == nullptr)
            return;

        if (head->next == nullptr) {
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
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class Stack {
private:
    static const int MAX_SIZE = 5;
    int top;
    int arr[MAX_SIZE];
public:
    Stack() : top(-1) {}
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }
    bool isEmpty() {
        return (top == -1);
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        --top;
    }
    void display() {
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class Queue {
private:
    static const int MAX_SIZE = 5;
    int front, rear;
    int arr[MAX_SIZE];
public:
    Queue() : front(-1), rear(-1) {}
    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;
    }
    void display() {
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        if (front != -1 && rear != -1)
            cout << arr[rear];
        cout << endl;
    }
};

int main() {
    int choice;
    LinkedList linkedList;
    Stack stack;
    Queue queue;
    
    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on Linked list" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value for node 1: ";
                cin >> value;
                linkedList.addNode(value);
                cout << "Enter the value for node 2: ";
                cin >> value;
                linkedList.addNode(value);
                cout << "Enter the value for node 3: ";
                cin >> value;
                linkedList.addNode(value);
                cout << "Enter the value for node 4: ";
                cin >> value;
                linkedList.addNode(value);
                
                cout << "Linked list after adding 4 elements: ";
                linkedList.display();
                
                linkedList.sortList();
                linkedList.deleteLastElement();
                
                cout << "Linked list after sorting its elements and deletion of the last element: ";
                linkedList.display();
                
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to push onto stack 1: ";
                cin >> value;
                stack.push(value);
                cout << "Enter the value to push onto stack 2: ";
                cin >> value;
                stack.push(value);
                cout << "Enter the value to push onto stack 3: ";
                cin >> value;
                stack.push(value);
                cout << "Enter the value to push onto stack 4: ";
                cin >> value;
                stack.push(value);
                cout << "Enter the value to push onto stack 5: ";
                cin >> value;
                stack.push(value);
                
                stack.pop();
                
                cout << "Stack elements after 5 pushes and 1 pop operation: ";
                stack.display();
                
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value to add to queue 1: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Enter the value to add to queue 2: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Enter the value to add to queue 3: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Enter the value to add to queue 4: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Enter the value to add to queue 5: ";
                cin >> value;
                queue.enqueue(value);
                
                queue.dequeue();
                
                cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
                queue.display();
                
                break;
            }
            case 0:
                cout << "Exiting program......" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 0);

    return 0;
}
