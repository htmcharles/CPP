#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *insertAtHead(Node *head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp = newNode;
    }
    return head;
}

Node *insertAtPos(Node *head, int i, int data)
{
    if (i < 0)
    {
        return head;
    }
    if (i == 0)
    {
        return insertAtHead(head, data);
    }
}
Node *deleteLastNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (second_last->next);
    second_last->next = NULL;

    return head;
}
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

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

Node *mid_point(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next == NULL)
            break;

        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = mid_point(head);
    Node *a = head;
    Node *b = mid->next;

    mid->next = NULL;
    a = merge_sort(a);
    b = merge_sort(b);
    Node *c = merge(a, b);

    return c;
}
template <typename T>
struct Queue
{
    int front, rear, n;
    T *queue;
    int size;
    Queue(int c)
    {
        front = rear = -1;
        n = c;
        queue = new T;
        size = 0;
    }

    void enqueue(T val)
    {
        if (rear == n - 1)
            cout << "Queue Overflow/Full" << endl;
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            size++;
            queue[rear] = val;
        }
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow/Empty ";
            return;
        }
        cout << "Element deleted from queue is : " << queue[front] << endl;
        for (int i = front; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }

        rear--;
        size--;
    }
    void display()
    {
        if (front == -1)
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Queue elements are : ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
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
        cout << "Element at front is:" << queue[front] << endl;
    }
};

template <typename T>
class Stack
{
    T *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        capacity = 4;
        arr = new T[capacity];
        nextIndex = 0;
    }
    Stack(T cap)
    {
        capacity = cap;
        arr = new T[capacity];
        nextIndex = 0;
    }

    T size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(T el)
    {
        if (nextIndex == capacity)
        {
            cout << "The stack is full" << endl;
        }
        arr[nextIndex] = el;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty: " << endl;
            return;
        }
        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }

        return arr[nextIndex - 1];
    }
    void display()
    {
        cout << "Stack elements are: ";
        for (int i = nextIndex - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Node *head = nullptr;
    Stack<int> stack;
    Queue<int> queue(100);

    int choice;
    do
    {
        cout << "\n-------------------------" << endl;
        cout << "Main Menu:" << endl;
        cout << "1. Node Operations" << endl;
        cout << "2. Stack Operations" << endl;
        cout << "3. Queue Operations" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            cout << "Exiting..." << endl;
            break;
        }
        case 1:
            for (int i = 0; i < 5; i++)
            {
                int data;
                cout << "Enter data for node " << i + 1 << ": ";
                cin >> data;
                head = insertAtHead(head, data);
            }
            cout << "Linked list before sorting:";
            display(head);
            cout << endl;
            head = merge_sort(head);

            cout << "Linked list after sorting:";
            display(head);
            cout << endl;

            cout << "Linked list after deleting:";
            head = deleteLastNode(head);
            display(head);
            break;
        case 2:
        {
            for (int i = 0; i < 5; i++)
            {
                int data;
                cout << "Enter data for element " << i + 1 << ": ";
                cin >> data;
                stack.push(data);
            }

            stack.display();
            break;
        }

        case 3:
        {
            for (int i = 0; i < 5; i++)
            {
                int data;
                cout << "Enter data for element " << i + 1 << ": ";
                cin >> data;
                queue.enqueue(data);
            }
            queue.display();
            queue.dequeue();
            cout << "queue elements after deleting:";
            queue.display();

            break;
        }

        default:
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
        }
    } while (choice != 4);

    return 0;
}