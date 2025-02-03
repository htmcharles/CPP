#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to add node ,sort linked list and delete last node , display stack and display queue
void addNode(Node*& head, int data);
void sortLinkedList(Node*& head);
void deleteLastNode(Node*& head);
void displayLinkedList(Node* head);
void displayStack(std::stack<int>& stack);
void displayQueue(std::queue<int>& queue);

int main() {
    
    int choice;
    Node* linkedList = nullptr;
    std::stack<int> stack;
    std::queue<int> queue;

    // switching cases
    do {
        // cases
        std::cout << "\nChoose data structure operation:\n"
                  << "1. Operate onLinked List\n"
                  << "2. Operate onStack\n"
                  << "3. Operate onQueue\n"
                  << "0. Exit \n ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Linked List
                int val;
                for (int i = 0; i < 4; ++i) {
                    std::cout << "Enter value for node " << i+1 << ": ";
                    std::cin >> val;
                    addNode(linkedList, val);
                }
                  std::cout << "Linked List after adding 4 elements: ";
                  displayLinkedList(linkedList);  
                sortLinkedList(linkedList);
                deleteLastNode(linkedList);
                std::cout << "Linked List after sorting and deleting the last element: ";
                displayLinkedList(linkedList);
                break;

            case 2: // Stack
                int stackVal;
                for (int i = 0; i < 5; ++i) {
                    std::cout << "Enter Value to push onto stack " << i+1 << ": ";
                    std::cin >> stackVal;
                    stack.push(stackVal);
                }
                if (!stack.empty()) {
                    stack.pop();
                    std::cout << "Popped one element from stack.\n";
                } else {
                    std::cout << "Stack is empty.\n";
                }
                std::cout << "Stack after pushing and 1 pop operation : ";
                displayStack(stack);
                break;

         

            case 3: // Queue
                int queueVal;
                for (int i = 0; i < 5; ++i) {
                    std::cout << "Enter Value to add to queue" << i+1 << ": ";
                    std::cin >> queueVal;
                    queue.push(queueVal);
                }
                if (!queue.empty()) {
                    queue.pop();
                    std::cout << "queue after enqueue and dequeue operation :";
                    displayQueue(queue);
                } else {
                    std::cout << "Queue is empty.\n";
                     ;
                }
                break;

            case 0: // Exit
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    // Free memory for linked list
    while (linkedList != nullptr) {
        Node* temp = linkedList;
        linkedList = linkedList->next;
        delete temp;
    }

    return 0;
}

// Function to add a node to linked list
void addNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to sort linked list
void sortLinkedList(Node*& head) {
    std::vector<int> values;
    Node* current = head;
    while (current != nullptr) {
        values.push_back(current->data);
        current = current->next;
    }
    std::sort(values.begin(), values.end());
    current = head;
    for (int val : values) {
        current->data = val;
        current = current->next;
    }
}

// Function to delete last node of linked list
void deleteLastNode(Node*& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* current = head;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }
    delete current;
    prev->next = nullptr;
}

// Function to display linked list
void displayLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to display stack
void displayStack(std::stack<int>& stack) {
    std::stack<int> tempStack = stack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

// Function to display queue
void displayQueue(std::queue<int>& queue) {
    std::queue<int> tempQueue = queue;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;
}
