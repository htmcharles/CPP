#include <iostream>

using namespace std;

class Stack
{
private:
    int capacity;
    int nextIndex;
    int *array;

public:
    Stack()
    {
        capacity = 5;
        nextIndex = 0;
        array = new int[capacity];
    }

    Stack(int capacity) : capacity(capacity)
    {
        nextIndex = 0;
        array = new int[capacity];
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    bool isFull()
    {
        return nextIndex == capacity;
    }

    void push(int data)
    {
        if (!isFull())
        {
            array[nextIndex] = data;
            nextIndex++;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            nextIndex--;
        }
    }

    void printStack()
    {
        for (int i = nextIndex - 1; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

struct Node
{
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void addNode(int data)
    {
        Node *node = new Node();
        node->data = data;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            // node->next = head->next;
            // head->next = node;
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void deleteEnd()
    {
        if (head == NULL || head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *current = head;
            while (current->next->next)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void printLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *current = head;
            while (current->next)
            {
                if (current->data > current->next->data)
                {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        }
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        if (rear == NULL) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (front == NULL) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    void printQueue() {
        Node* current = front;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

void linkedlist_operation()
{
    LinkedList list = LinkedList();
    for (int i = 0; i < 4; i++)
    {
        int input;
        cout << "Enter value for node " << i + 1 << ":";
        cin >> input;
        list.addNode(input);
        cin.ignore();
        cout << endl;
    }
    cout << "Linked list after adding 4 elements:";
    list.printLinkedList();
    list.sort();
    list.deleteEnd();
    cout << "Linked list after sorting its elements and deletion of the last element:";
    list.printLinkedList();
}

void stack_operation()
{
    Stack stack = Stack();
    for (int i = 0; i < 5; i++)
    {
        int input;
        cout << "Enter value to push onto stack" << i + 1 << ":";
        cin >> input;
        stack.push(input);
        cin.ignore();
        cout << endl;
    }
    stack.pop();
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    stack.printStack();
}

void queue_operation()
{
    Queue queue = Queue();
    for (int i = 0; i < 5; i++)
    {
        int input;
        cout << "Enter value to add to queue" << i + 1 << ":";
        cin >> input;
        queue.enqueue(input);
        cin.ignore();
        cout << endl;
    }
    queue.dequeue();
    cout << "Queue elements after 5 enqueue and 1 dequeue operations:";
    queue.printQueue();
}

int main(int argc, char const *argv[])
{
    int choice;
    cout << "Enter your choice:" << endl;
    cout << "1. Operate on Linked List" << endl;
    cout << "2. Operate on Stack" << endl;
    cout << "3. Operate on Queue" << endl;
    cout << "0. Exit " << endl;
    cin >> choice;
    if (choice == 0)
    {
        cout << "Exiting " << endl;
        return 0;
    }
    else if (choice == 1)
    {
        linkedlist_operation();
    }
    else if (choice == 2)
    {
        stack_operation();
    }
    else if (choice == 3)
    {
        queue_operation();
    }
    return 0;
}
