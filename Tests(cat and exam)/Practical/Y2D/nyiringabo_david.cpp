#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class to manage the linked list operations
class LinkedList {
    public:
        Node* head;

        LinkedList() {
            head = nullptr;
        }

    // Function to add a new node at the end of the list
    void addNode(int data) {
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

    // Function to delete the last element from the list
    void deleteLastNode() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to perform merge sort on the linked list
    void sortList() {
        head = mergeSort(head);
    }

private:
    // Merge function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        Node* result = nullptr;
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        }
        else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function for merge sort
    Node* mergeSort(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }
};
// declaration of stack
class Stack {
private:
    int* arr;
    int capacity;
    int nextIndex;

public:
    Stack() {
        arr = new int[5];
        capacity = 5;
        nextIndex = 0;
    }

    void push(int data) {
        if (nextIndex >= capacity) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }

    int pop() {
        if (nextIndex == 0) {
            cout << "Stack is empty!" << endl;
            return -1; // Return a default value indicating failure
        }
        nextIndex--;
        int popped = arr[nextIndex];
        return popped;
    }
    void display() {
        for (int i = nextIndex - 1; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// declaration of queue
class Queue {
private:
    int* arr;
    int rear;
    int front;
    int size;

public:
    Queue() {
        arr = new int[5];
        front = 0;
        rear = 0;
        size = 5;
    }

    void enqueue(int data) {
        if (rear >= size) {
            cout << "The queue is full!" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (front == rear) {
            cout << "The queue is Empty!" << endl;
            return -1; // Return a default value indicating failure
        }
        int dequeued = arr[front];
        front++;
        return dequeued;
    }
    void display() {
        for (int i = front; i < rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// driver code
int main() {
    int choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Operate on Linked List\n";
        cout << "2. Operate on Stack\n";
        cout << "3. Operate on Queue\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            LinkedList list;
            for (int i = 1; i < 5; ++i) {
                int val;
                cout << "Enter value for the node "<< i << " : ";
                cin >> val;
                list.addNode(val);
            }
            cout << "Linked list after adding 4 elements: ";
            list.display();
            list.sortList();
            list.deleteLastNode();
            cout << "Linked list after sorting its elements and deletion of the last element: ";
            list.display();
            break;
        }
        case 2: {
            Stack stack;
            for (int i = 0; i < 5; ++i) {
                int val;
                cout << "Enter value to push onto stack: ";
                cin >> val;
                stack.push(val);
            }
            stack.pop();
            cout << "Stack elements after 5 pushing and 1 pop operations: ";
            stack.display();
            cout << endl;
            break;
        }
        case 3: {
            Queue queue;
            for (int i = 0; i < 5; ++i) {
                int val;
                cout << "Enter value to add to queue: ";
                cin >> val;
                queue.enqueue(val);
            }
            cout << "Queue elements after 5 enqueue and 1 dequeue operations";
            queue.display();
            cout << endl;
            break;
        }
        case 0:
            cout << "Exiting program ...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
