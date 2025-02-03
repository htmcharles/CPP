#include <iostream>

using namespace std;

struct Stack {
    int arr[5];  // Array to store stack elements
    int top;           // Index of the top element

    // Initialize an empty stack
    Stack() {
        top = -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == 5 - 1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Push an element onto the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1; // Or any invalid value to indicate error
        }
        return arr[top--];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
struct Queue {
    int arr[5];
    int front, rear;

    // Initialize an empty queue
    Queue() {
        front = rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == 5 - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue an element (add to the back)
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Set front to 0 for the first element
        }
        arr[++rear] = data;
    }

    // Dequeue an element (remove from the front)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return -1; // Or any invalid value to indicate error
        }
        int data = arr[front];
        if (front == rear) { // If only one element, reset both front and rear
            front = rear = -1;
        } else {
            front++;
        }
        return data;
    }

    // Display the elements in the queue (if not empty)
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// Structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the tail of the linked list
void insertAtTail(Node** head_ref, int new_data) {
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    // If the list is empty, make the new node the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node and append the new node
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to remove the last node from the linked list
void removeTail(Node** head_ref) {
    // If the list is empty, return
    if (*head_ref == nullptr) {
        return;
    }

    // If there's only one node, make the head nullptr
    if ((*head_ref)->next == nullptr) {
        delete *head_ref;
        *head_ref = nullptr;
        return;
    }

    // Traverse to the second last node
    Node* second_last = *head_ref;
    while (second_last->next->next != nullptr) {
        second_last = second_last->next;
    }

    // Delete the last node and update the second last node's next pointer
    delete second_last->next;
    second_last->next = nullptr;
}

int main() {
    Node* head = nullptr;  // Start with an empty list

    // Add 4 nodes to the list
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    cout << "Original list: ";
    // Print the list (optional, for demonstration)
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Remove the last node
    removeTail(&head);

    cout << "List after removing last node: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    Stack myStack;

    // Add five elements
    for (int i = 1; i <= 5; i++) {
        myStack.push(i * 10);
    }

    // Check if stack is full (should be full after adding 5 elements)
    if (myStack.isFull()) {
        cout << "Stack is full." << endl;
    }
    cout<<"Before popping the last element: "<< endl;
    myStack.display();
    // Pop one element
    int popped_value = myStack.pop();
    if (popped_value != -1) { // Check if pop was successful
        cout << "Popped element: " << popped_value << endl;
    }

    myStack.display();

    // Check if stack is empty (should not be empty after popping one)
    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    Queue myQueue;

    // Display the queue before adding elements (should be empty)
    myQueue.display();

    // Add five elements
    for (int i = 1; i <= 5; i++) {
        myQueue.enqueue(i * 10);
    }

    // Display the queue after adding elements
    myQueue.display();

    // Dequeue one element
    int deleted_value = myQueue.dequeue();
    if (deleted_value != -1) { // Check if dequeue was successful
        cout << "Deleted element: " << deleted_value << endl;
    }

    // Display the queue after deleting one element
    myQueue.display();

    return 0;
}
