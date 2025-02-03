#include <iostream>
#define MAX_SIZE 100

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sortList()
    {
        if (!head || !head->next)
        {
            cout << "Linked list is already sorted or empty." << endl;
            return;
        }

        bool swapped;
        Node *current;
        Node *lastSorted = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != lastSorted)
            {
                if (current->data > current->next->data)
                {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            lastSorted = current;
        } while (swapped);
    }

    void deleteLastNode()
    {
        if (!head)
        {
            cout << "Linked list is empty." << endl;
            return;
        }
        else if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void displayList()
    {
        if (!head)
        {
            cout << "Linked list is empty." << endl;
            return;
        }
        cout << "Linked list elements: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack
{
private:
    int top;          
    int arr[MAX_SIZE];

public:
    Stack()
    {
        top = -1; 
    }

    void push(int val)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val; 
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    void displayStack()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue
{
private:
    int front, rear;
    int arr[MAX_SIZE]; 

public:
    Queue()
    {
        front = rear = -1; 
    }

    void enqueue(int val)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = val; 
        if (front == -1)
        {
            front = 0;
        }
    }

    void dequeue()

    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void displayQueue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int choice;

    LinkedList linkedList;
    Stack stack;
    Queue queue;
    while (true)
    {
        cout<<endl;
        cout<<endl;
        cout << "Enter your choice" << endl;
        cout << "1. Operation on Linked List" << endl;
        cout << "2. Operation on Stack" << endl;
        cout << "3. Operation on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting program..." << endl;
            break;
        }

        switch (choice)
        {
        case 1: //LinkedList
            for (int i = 0; i < 4; ++i)
            {
                int val;
                cout << "Enter element for node" << i + 1 << ": ";
                cin >> val;
                linkedList.addNode(val);
            }
            cout << "LinkedList elements after adding 4 nodes: ";
            linkedList.displayList();
            linkedList.sortList();
            linkedList.deleteLastNode();
            cout << "LinkedList elements after sorting and deleting the last node: ";
            linkedList.displayList();
            break;

        case 2: // Stack
            for (int i = 0; i < 5; i++)
            {
                int val;
                cout << "Enter element to push onto stack" << i + 1 << ": ";
                cin >> val;
                stack.push(val);
            }
            stack.pop();
            cout << "Stack elements after 5 pushing and 1 poping: ";
            stack.displayStack();
            cout<<endl;
            break;

        case 3: // Queue
            for (int i = 0; i < 5; ++i)
            {
                int val;
                cout << "Enter element to enqueue into the Queue: ";
                cin >> val;
                queue.enqueue(val);
            }
            queue.dequeue();
            cout << "Queue elements after enqueuing and dequeuing 1 element: ";
            queue.displayQueue();
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2, 3, or 0." << endl;
            break;
        }
    }

    return 0;
}
