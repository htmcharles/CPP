#include <iostream>

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Linked List Operations
void addNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

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

void sortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void deleteLastNode(Node*& head) {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Stack Operations
const int MAX_STACK_SIZE = 5;

struct Stack {
	
	int nextIndex;
    int arr[MAX_STACK_SIZE];
    int top;

    Stack() {
        top = -1;
        nextIndex = 0;
    }
    
    bool isEmpty(){
     if(nextIndex==0){
       return true;
     }else{
       return false;
     }  
       return nextIndex==0;
   }

    void push(int value) {
        if (top == MAX_STACK_SIZE - 1) {
            std::cout << "Stack Overflow: Cannot push element.\n";
        } else {
            arr[++top] = value;
        }
    }

    void pop() {
    	if(isEmpty()){
    		std::cout<<"Stack is empty"<<std::endl;
		}
        if (top == -1) {
            std::cout << "Stack Underflow: Cannot pop element.\n";
        } else {
            --top;
        }
    }
};

// Queue Operations
const int MAX_QUEUE_SIZE = 5;

struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || (rear == (front - 1) % (MAX_QUEUE_SIZE - 1))) {
            std::cout << "Queue Overflow: Cannot enqueue element.\n";
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == MAX_QUEUE_SIZE - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
    }

    void dequeue() {
        if (front == -1) {
            std::cout << "Queue Underflow: Cannot dequeue element.\n";
        } else if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_QUEUE_SIZE - 1) {
            front = 0;
        } else {
            ++front;
        }
    }
};

int main() {
    int choice;
    Node* linkedList = nullptr;
    Stack stack;
    Queue queue;

    while (true) {
        std::cout << "Enter your choice:\n";
        std::cout << "1. Linked List\n";
        std::cout << "2. Stack\n";
        std::cout << "3. Queue\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting the program.\n";
            break;
        }

        switch (choice) {
            case 1:
                // Linked List
                for (int i = 0; i < 4; ++i) {
                    int value;
                    std::cout << "Enter value for node " << (i + 1) << ": ";
                    std::cin >> value;
                    addNode(linkedList, value);
                }

                std::cout << "Linked List before sorting: ";
                Node* temp = linkedList;
                while (temp != nullptr) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;

                sortLinkedList(linkedList);

                std::cout << "Linked Listafter sorting: ";
                temp = linkedList;
                while (temp != nullptr) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;

                deleteLastNode(linkedList);

                std::cout << "Linked List after deleting the last element: ";
                temp = linkedList;
                while (temp != nullptr) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;

                break;

            case 2:
                // Stack
                for (int i = 0; i < 5; ++i) {
                    int value;
                    std::cout << "Enter value to push into the stack: ";
                    std::cin >> value;
                    stack.push(value);
                }

                stack.pop();
                break;

            case 3:
                // Queue
                for (int i = 0; i < 5; ++i) {
                    int value;
                    std::cout << "Enter value to enqueue into the queue: ";
                    std::cin >> value;
                    queue.enqueue(value);
                }

                queue.dequeue();
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}