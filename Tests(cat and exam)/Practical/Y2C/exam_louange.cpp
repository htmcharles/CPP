#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
    int count;
public:
    LinkedList() : head(nullptr), count(0) {}

    // Function to add a node at the end of the list
    void addNode(int data) {
        if (count >= 4) {
            cout << "You can add only 4 nodes to the linked list." << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            count++;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        count++;
    }

    // Function to sort the linked list
    void sortList() {
        if (!head || !head->next)
            return;

        Node *current = head, *index = nullptr;
        int temp;
        while (current) {
            index = current->next;
            while (index) {
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

    // Function to pop the last element
    void popLast() {
        if (!head)
            return;
        if (!head->next) {
            delete head;
            head = nullptr;
            count--;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        count--;
    }

    // Function to get the current count of nodes in the linked list
    int getCount() const {
        return count;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Stack implementation
class Stack {
private:
    static const int MAX_SIZE = 5;
    int top;
    int arr[MAX_SIZE];
public:
    Stack() : top(-1) {}

    // Function to push an element onto the stack
    void push(int data) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = data;
        display();
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped element: " << arr[top--] << endl;
        display();
    }

    // Function to get the current size of the stack
    int getSize() const {
        return top + 1;
    }

    // Function to display the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Queue implementation
class Queue {
private:
    static const int MAX_SIZE = 5;
    int front, rear, size;
    int arr[MAX_SIZE];
public:
    Queue() : front(0), rear(-1), size(0) {}

    // Function to add an element to the queue
    void enqueue(int data) {
        if (size == MAX_SIZE) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;
        size++;
        display();
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removed element: " << arr[front] << endl;
        front = (front + 1) % MAX_SIZE;
        size--;
        display();
    }

    // Function to get the current size of the queue
    int getSize() const {
        return size;
    }

    // Function to display the queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int cnt = 0; cnt < size; ++cnt) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    int choice;
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    do {
        cout << "Choose an option:\n";
        cout << "1. Linked List\n";
        cout << "2. Stack\n";
        cout << "3. Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (linkedList.getCount() >= 4) {
                    cout << "Linked list is already full." << endl;
                    break;
                }
                cout << "Enter elements for linked list (0 to end): ";
                int num;
                while (cin >> num && num != 0)
                    linkedList.addNode(num);
                cout << "Original linked list: ";
                linkedList.display();
                linkedList.sortList();
                cout << "Sorted linked list: ";
                linkedList.display();
                linkedList.popLast();
                cout << "Linked list after popping last element: ";
                linkedList.display();
                break;
            case 2:
                if (stack.getSize() >= 5) {
                    cout << "Stack is already full." << endl;
                    break;
                }
                cout << "Enter elements for stack (0 to end): ";
                while (cin >> num && num != 0)
                    stack.push(num);
                stack.pop();
                break;
            case 3:
                if (queue.getSize() >= 5) {
                    cout << "Queue is already full." << endl;
                    break;
                }
                cout << "Enter elements for queue (0 to end): ";
                while (cin >> num && num != 0)
                    queue.enqueue(num);
                queue.dequeue();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
