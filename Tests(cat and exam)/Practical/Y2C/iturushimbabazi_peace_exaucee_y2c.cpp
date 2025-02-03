#include <iostream>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function for creating a new node
void createNode(Node** head, int val) {
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the nodes
void display(Node* head) {  
    Node* n = head;
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

// Function to delete the last node
Node* deleteLastNode(Node* head) {
    if (head == NULL)
        return NULL;
  
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    
    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    
    // Delete last node
    delete (second_last->next);
    
    // Change next of second last
    second_last->next = NULL;
  
    return head;
}

// Function to sort linked lists
Node *merge(Node *a, Node *b) {
    // base case
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
 
    // recursive case
    // take a head pointer
    Node *c;
 
    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    } else {
        c = b;
        c->next = merge(a, b->next);
    }
 
    return c;
}

Node *mid_point(Node *head) {
    // base case
    if(head == NULL || head->next == NULL)
        return head;
    // recursive case
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if(fast->next == NULL)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
 
Node* merge_sort(Node *head) {
    // base case
    if(head == NULL || head->next == NULL)
        return head;
 
    // recursive case
    // Step 1: divide the linked list into
    // two equal linked lists
    Node *mid = mid_point(head);
    Node *a = head;
    Node *b = mid->next;
 
    mid->next = NULL;
 
    // Step 2: recursively sort the smaller
    // linked lists
    a = merge_sort(a);
    b = merge_sort(b);
 
    // Step 3: merge the sorted linked lists
    Node *c = merge(a, b);
 
    return c;
}

// Implementation of stack
class Stack {
   int *arr;
   int nextIndex;
   int capacity;
public:
   Stack() {
      capacity = 4;
      arr = new int[capacity];
      nextIndex = 0;
   }
   Stack(int cap) {
     capacity = cap;
     arr = new int[capacity];
     nextIndex = 0;
   }
   /// return no of elements present in stack
   int size() { return nextIndex; }
   bool isEmpty() {
     return nextIndex == 0;
   }
       
   void push(int ele) {
      if(nextIndex == capacity) {
        cout<<"Stack full"<<endl;
        return;
      }
      arr[nextIndex] = ele;
      nextIndex++;
   }
   void pop() {
      if(isEmpty()) {
        cout<<"Stack empty"<<endl;
        return;
      }
      nextIndex--;
   }
   int top() {
     if(isEmpty()) {
        cout<<"Stack empty"<<endl;
        return 0;
      }
     return arr[nextIndex-1];
   }
   void printStack() {
    for(int i = nextIndex - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};


// Functions for queue implementation
int queue[100], n = 100, front = -1, rear = -1;

void enqueue(int val) {
   if (rear == n - 1)
      cout << "Queue Overflow/Full" << endl;
   else {
      if (front == -1)
         front = 0;
      rear++;
      queue[rear] = val; // Assigning value to the global queue array at rear index
   }
}

void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow/Empty ";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front] <<endl;
   front++;
}

void displayQueue() {
   if (front == - 1)
      cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}

int main() {
    int choice;
    Node* linkedListHead = nullptr;
    Stack stack;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Operate on linked list\n";
        cout << "2. Operate on Stack\n";
        cout << "3. Operate on queue\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Operations on linked list
                for (int i = 0; i < 4; i++) {
                    int value;
                    cout << "Enter the value for node " << i + 1 << ": ";
                    cin >> value;
                    createNode(&linkedListHead, value);
                }

                cout << "\nLinked List after adding 4 elements: ";
                display(linkedListHead);

                linkedListHead = merge_sort(linkedListHead);
                linkedListHead = deleteLastNode(linkedListHead);

                cout << "\nLinked List after sorting its elements and deletion of the last element: ";
                display(linkedListHead);
                break;
            }
            case 2: {
                // Operations on stack
                for (int i = 0; i < 5; i++) {
                    int value;
                    cout << "Enter the value to push onto stack: ";
                    cin >> value;
                    stack.push(value);
                }

                stack.pop();

                cout << "\nStack elements after 5 pushing and 1 pop operations : ";
                stack.printStack();
                break;
            }
            case 3: {
                // Operations on queue
                for (int i = 0; i < 5; i++) {
                    int value;
                    cout << "Enter value to add to queue: ";
                    cin >> value;
                    enqueue(value);
                }

                dequeue();

                cout << "\nQueue elements after 5 enqueue and 1 dequeue operations: ";
                displayQueue();
                break;
            }
        }
    } while (choice != 0);

    return 0;
}

