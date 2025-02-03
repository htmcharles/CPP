#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

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
Node *mid_point(Node *head)
{
  // base case
  if (head == NULL || head->next == NULL)
    return head;
  // recursive case
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
  // base case
  if (head == NULL || head->next == NULL)
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

void printList(Node *head)
{
  while (head != NULL)
  {
    cout << " " << head->data << endl;
    head = head->next;
  }
}
class Stack
{
  int *arr;
  int nextIndex;
  int capacity;

public:
  Stack()
  {
    capacity = 5;
    arr = new int[capacity];
    nextIndex = 0;
  }
  Stack(int capacity)
  {
    this->capacity = capacity;
    arr = new int[capacity];
    nextIndex = 0;
  }
  int size() { return nextIndex; }
  bool isEmpty()
  {

    return nextIndex == 0;
  }
  void push(int el)
  {
    if (nextIndex == capacity)
    {
      return;
    }
    arr[nextIndex] = el;
    nextIndex++;
  }
  void pop()
  {
    if (isEmpty())
    {
      cout << "The stack is already empty";
    }

    nextIndex--;
  }
  int top()
  {
    if (isEmpty())
    {
      cout << "Stack is empty";
      return 0;
    }
    return arr[nextIndex - 1];
  }
};

int queArray[100];
int front = -1;
int rear = -1;
int n = 100;

void enque(int data)
{
  if (rear == n - 1)
  {
    cout << "Que is full";
  }
  else
  {
    if (front = -1)
      front = 0;

    rear++;
    queArray[rear] = data;
  }
};
void deque()
{
  if (front == -1 || front > rear)
  {
    cout << "Que is empty";
    return;
  }
  cout << queArray[front];
  front++;
}
// Insert at beginning of linked list
Node *insertAtAnyPosition(Node *head, int data, int position)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  int count = 1;
  Node *temp = head;
  while (count < position && temp->next != NULL)
  {
    temp = temp->next;
    count = count + 1;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  return head;
}

void print_linked_list(Node *head)
{
  if (head == NULL)
  {
    cout << "The linked list is empty";
  }
  else
  {

    while (head != NULL)
    {
      cout << head->data << endl;
      head = head->next;
    };
  }
}

void operateLinkedList()
{

  int value;
  Node *head = new Node();
  // Adding 4 nodes to the linked list
  cout << "Enter value for node 1: ";
  cin >> value;
  head = insertAtAnyPosition(head, value, 1);

  cout << "Enter value for node 2: ";
  cin >> value;
  head = insertAtAnyPosition(head, value, 2);

  cout << "Enter value for node 3: ";
  cin >> value;
  head = insertAtAnyPosition(head, value, 3);

  cout << "Enter value for node 4: ";
  cin >> value;
  head = insertAtAnyPosition(head, value, 4);

  // Displaying the linked list after adding elements
  cout << "Linked list after adding 4 elements: ";
  print_linked_list(head);
  cout << endl;

  cout << "Linked list after sorting its elements and deletion of the last element: ";
  head = merge_sort(head);
  print_linked_list(head);

  cout << endl;
}
// Function to operate on stack
void operateStack()
{

  int value;
  Stack s(4);
  // Pushing 5 elements onto the stack
  for (int i = 0; i < 5; ++i)
  {
    cout << "Enter value to push onto stack: ";
    cin >> value;

    s.push(value);
  }
  // Displaying stack elements after pushing
  cout << "Stack elements after 5 pushing and 1 pop operations: ";

  s.pop();
  for (int i = 0; i < 5; ++i)
  {

    cout << s.top();
  }

  cout << endl;
}

void operateQueue()
{

  int value;
  // Adding 5 elements to the queue
  for (int i = 0; i < 5; ++i)
  {
    cout << "Enter value to add to queue: ";
    cin >> value;
    enque(value);
  }
  // Displaying queue elements after enqueue and dequeue operations
  for (int i = 0; i < 5; i++)
  {
    deque();
  }

  cout << endl;
}

int main()
{
  int choice;
  do
  {
    // Displaying menu and taking user's choice
    cout << "\nEnter your choice: \n";
    cout << "1. Operate on linked list\n";
    cout << "2. Operate on stack\n";
    cout << "3. Operate on Queue\n";
    cout << "0. Exit\n";
    cin >> choice;
    // Performing operations based on user's choice
    switch (choice)
    {
    case 1:
      operateLinkedList();
      break;
    case 2:
      operateStack();
      break;
    case 3:
      operateQueue();
      break;
    case 0:
      cout << "\nExit proggram...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
  return 0;
}