#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function prototypes
void operateLinkedList();
void operateStack();
void operateQueue();

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node
void deleteNode(Node* node) {
    delete node;
}

// Function to add a node to the end of the linked list
void appendNode(Node* &head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to sort the linked list (bubble sort)
void sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to delete the last node from the linked list
void deleteLastNode(Node* &head) {
    if (head == NULL || head->next == NULL) {
        deleteNode(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        deleteNode(temp->next);
        temp->next = NULL;
    }
}

// Function to operate on linked list
void operateLinkedList() {
    Node* myList = NULL;
    int value;
    // Adding 4 nodes to the linked list
    std::cout << "Enter value for node 1: ";
    std::cin >> value;
    appendNode(myList, value);
    std::cout << "Enter value for node 2: ";
    std::cin >> value;
    appendNode(myList, value);
    std::cout << "Enter value for node 3: ";
    std::cin >> value;
    appendNode(myList, value);
    std::cout << "Enter value for node 4: ";
    std::cin >> value;
    appendNode(myList, value);
    // Displaying the linked list after adding elements
    std::cout << "Linked list after adding 4 elements: ";
    displayList(myList);
    // Sorting the linked list
    sortList(myList);
    // Deleting the last element
    deleteLastNode(myList);
    // Displaying the linked list after sorting and deletion
    std::cout << "Linked list after sorting its elements and deletion of the last element: ";
    displayList(myList);
}

// Function to operate on stack
void operateStack() {
    Node* myStack = NULL;
    int value;
    // Pushing 5 elements onto the stack
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter value to push onto stack: ";
        std::cin >> value;
        appendNode(myStack, value);
    }
    // Displaying stack elements after pushing
    std::cout << "Stack elements after 5 pushing and 1 pop operations: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << myStack->data << " ";
        Node* temp = myStack->next;
        deleteNode(myStack);
        myStack = temp;
    }
    std::cout << std::endl;
}

// Function to operate on queue
void operateQueue() {
    Node* myQueueFront = NULL;
    Node* myQueueRear = NULL;
    int value;
    // Adding 5 elements to the queue
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter value to add to queue: ";
        std::cin >> value;
        appendNode(myQueueRear, value);
        if (myQueueFront == NULL) {
            myQueueFront = myQueueRear;
        }
    }
    // Removing/deleting one element from the queue
    if (myQueueFront != NULL) {
        Node* temp = myQueueFront->next;
        deleteNode(myQueueFront);
        myQueueFront = temp;
    }
    // Displaying queue elements after enqueue and dequeue operations
    std::cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
    Node* temp = myQueueFront;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    int choice;
    do {
        // Displaying menu and taking user's choice
        std::cout << "\nEnter your choice: \n";
        std::cout << "1. Operate on linked list\n";
        std::cout << "2. Operate on stack\n";
        std::cout << "3. Operate on Queue\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;
        // Performing operations based on user's choice
        switch (choice) {
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
                std::cout << "\nExiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}

