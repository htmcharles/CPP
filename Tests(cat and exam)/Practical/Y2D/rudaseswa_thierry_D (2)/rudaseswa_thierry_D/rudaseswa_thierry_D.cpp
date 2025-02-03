#include <iostream>
using namespace std;

// class for  the LinkedList
class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

// class of the linkedlist
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int data)
    {
        // creating a new node
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // adding  element at end
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sortList()
    {
        // within ahelp of bubble sort
        Node *i;
        Node *j;
        for (i = head; i != nullptr; i = i->next)
        {
            for (j = i->next; j != nullptr; j = j->next)
            {
                if (i->data > j->data)
                {
                    swap(i->data, j->data);
                }
            }
        }
    }

    // deleting  last node
    void deleteLastNode()
    {
        // checking if empty
        if (head == nullptr)
            return;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        // deletion operator
        Node *secondLast = head;
        while (secondLast->next->next != nullptr)
            secondLast = secondLast->next;
        delete secondLast->next;
        secondLast->next = nullptr;
    }

    void clearList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        
    }
    // printing value 
    void printNodes()
    {
        Node *current = head;
        ;
        while (current != nullptr)
        {
//           current node value
            cout << current->data << " ";
            current = current->next;
        }
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// the use of the stack
class Stack
{
private:
    // peek value
    int top;
    static const int MAX = 5;
    int arr[MAX];

public:
    Stack() : top(-1) {}
    void push(int data)
    {
      
        if (top < MAX - 1)
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Stack is full.\n";
        }
    }

    
    int pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }
        else
        {
          
            cout << "Stack is empty.\n";
            return -1; 
        }
    }

    //  Isempty function to help us to know if is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // isfull function which help us to know if is full
    bool isFull()
    {
        return top == MAX - 1;
    }

    void clearStack()
    {
        top = -1; 
    }
    void printStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// the use of Queuse as the othe r option
class Queue
{
private:
    int front, rear, count;
    static const int MAX = 5;
    int arr[MAX];

public:
    Queue() : front(0), rear(-1), count(0) {} 

    void enqueue(int data)
    {
        if (count < MAX)
        {
            rear = (rear + 1) % MAX; 
            arr[rear] = data;
            count++; 
        }
        else
        {
            cout << "Queue is full.\n";
        }
    }

    int dequeue()
    {
        if (count > 0)
        {
            int data = arr[front];
            front = (front + 1) % MAX; 
            count--;                   
            return data;
        }
        else
        {
            cout << "Queue is empty.\n";
            return -1; 
//            helping us to know if is empty
        }
    }

    void printQueue()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
    void clearQueue()
    {
        front = 0; 
        rear = -1; 
        count = 0; 
    }
};

int main()
{
    LinkedList ll;
    Stack stack;
    Queue queue;
    int choice;

    do
    {
        cout << "\n Enter your choice:\n";
        cout << "1.Operate on  LinkedList\n2.Operate on  Stack\n3. Operate on Queue\n0. Exit\n";
        cin >> choice;
        
//        the use of switches that help us to fin the choice being chosen

        switch (choice)
        {
        case 1:
            // LinkedList operations
            ll.clearList();
            for (int i = 1; i <= 4; i++)
            {
                int nodeValue;
                cout << "Enter value for node " << i << ":";
                // read nodeValue
                cin >> nodeValue;
                // add new node
                ll.addNode(nodeValue);
            }

            cout << "Linked list after adding 4 elements :";
            ll.printNodes();
            cout << endl;
            ll.sortList();
            ll.deleteLastNode();
            cout << "Linked list after sorting its elements and deletion of the last element:";
            ll.printNodes();
            cout << endl;
            cout << "LinkedList operations completed.\n";
            break;
        case 2:
           
            stack.clearStack();
            for (int i = 1; i <= 5; ++i)
            {
                int stackValue;
                cout << "Enter value to push onto stack: ";
               
                cin >> stackValue;
                // adding new stack
                stack.push(stackValue);
            }
            stack.pop();
            cout << "Stack elements after 5 pushing and 1 pop operations :";
            stack.printStack();
            cout << endl;
            cout << "Stack operations completed.\n";
            break;
        case 3:
            // Queue operations usage
            queue.clearQueue();
            for (int i = 1; i <= 5; ++i)
            {
                int queueValue;
                cout << "Enter value to add to  queue: ";
                
                cin >> queueValue;
            
                queue.enqueue(queueValue);
            }
            queue.dequeue();
            cout << "Queue elements after 5 enqueue and  1 dequeue operations :";
            queue.printQueue();
            cout << "Queue operations completed.\n";
            break;
        case 0:
            cout << "Exiting program ...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
