#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Node structure for Linked List
struct Node
{
    int data;
    Node *next;
};

// Class for Linked List
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insert(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

 int getSize() const
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    // Display the Linked List
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *merge(Node *a, Node *b)
    {
        // base case
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        // recursive case
        // take a head pointer
        Node *c;

        if (a->data < b->data)
        {
            c = a;
            c->next = merge(a->next, b);
        }
        else
        {
            c = b;
            c->next = merge(a, b->next);
        }

        return c;
    }
    void sort()
    {
        head = mergeSort(head);
    }

private:
    // Merge Sort function
    Node *mergeSort(Node *start)
    {
        if (!start || !start->next)
            return start;

        Node *slow = start;
        Node *fast = start->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *mid = slow->next;
        slow->next = nullptr;

        Node *left = mergeSort(start);
        Node *right = mergeSort(mid);

        return merge(left, right);
    }

  public:
    Node* deleteLastNode()
    {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return nullptr;
        }

        // Find the second last node
        Node *second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);
        // Change next of second last
        second_last->next = NULL;

        return head;
    }
};

// Class for Queue
class Queue
{
private:
    int queueArray[5]; // Renamed to avoid ambiguity
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

     int getSize() const
    {
        if (front == -1) // Empty queue
            return 0;
        else
            return (rear - front + 1 + 5) % 5; // Handle wrap-around for circular queue
    }

    void enqueue(int val)
    {
        if (rear == 4)
            cout << "Queue Overflow/Full" << endl;
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queueArray[rear] = val;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow/Empty ";
            return;
        }
        cout << "Element deleted from queue is : " << queueArray[front] << endl;
        front++;
    }

    void display()
    {
        if (front == -1)
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Queue elements are : ";
            for (int i = front; i <= rear; i++)
                cout << queueArray[i] << " ";
            cout << endl;
        }
    }

    void readFront()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Element at front is:" << queueArray[front] << endl;
    }
};

// Class for Stack
class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack() : capacity(5), arr(new int[5]), nextIndex(0) {}
    Stack(int cap) : capacity(cap), arr(new int[cap]), nextIndex(0) {}

     int getSize() const // Define getSize function to return the number of elements in the stack
    {
        return nextIndex;
    }

    ~Stack()
    {
        delete[] arr;
    }

    int size() { return nextIndex; }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int ele)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack full" << endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return;
        }
        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return 0; // Return some default value
        }
        return arr[nextIndex - 1];
    }
};

int main()
{
    LinkedList myList;
    Stack myStack;
    Queue myQueue;

    int choice;
    int value;
    do
    {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on Linked List" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (myList.getSize() < 5)
            {
                for (int i = 0; i < 5; i++)
                {
                    cout << "Enter value for Node " << i << ": ";
                    cin >> value;
                    myList.insert(value);
                }
                myList.sort();
                myList.deleteLastNode();
                cout << "Linked list after sorting and deleting last node: ";
                myList.display();
            }
            break;
        case 2:
        {
            Stack myStack(5);
            for (int i = 0; i < 5; i++)
            {
                cout << "Enter value for Stack " << i << ": ";
                cin >> value;
                myStack.push(value);
            }
            for (int i = 0; i < 1; i++)
            {
                myStack.pop();
            }
            cout << "Stack elements after pushing 5 and popping 1: ";
            // Print stack elements
            break;
        }
        case 3:
        {
            Queue myQueue;
            for (int i = 0; i < myQueue.getSize(); i++)
            {
                cout << "Enter value for Queue " << i << ": ";
                cin >> value;
                myQueue.enqueue(value);
            }
            for (int i = 0; i < 1; i++)
            {
                myQueue.dequeue();
            }
            cout << "Queue elements after enqueuing 5 and dequeuing 1: ";
            // Print queue elements
            break;
        }
        case 0:
            cout << "Exiting program...." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
