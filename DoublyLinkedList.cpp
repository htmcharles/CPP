#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Getter for head
    Node* getHead() {
        return head;
    }

    // Function 1: Display elements using loop
    void displayLoop() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function 1: Display elements using recursion
    void displayRecursion(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        displayRecursion(node->next);
    }

    // Function 2: Search for an element
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Function 3: Count elements using loop
    int countLoop() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function 3: Count elements using recursion
    int countRecursion(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + countRecursion(node->next);
    }

    // Function 4: Delete the first node
    void deleteFirst() {
        if (head != nullptr) {
            Node* temp = head;
            if (head->next != nullptr) {
                head = head->next;
                head->prev = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }
    }

    // Function 5: Delete the last node
    void deleteLast() {
        if (tail != nullptr) {
            Node* temp = tail;
            if (tail->prev != nullptr) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    // Function 6: Delete any node by value
    void deleteNode(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function 7: Insert at the beginning
    void insertFirst(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function 8: Insert at the end
    void insertLast(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function 9: Insert at a given position
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            insertFirst(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 1; i < position && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertFirst(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertFirst(5);
    list.insertAtPosition(15, 3);

    cout << "Display elements using loop: ";
    list.displayLoop();

    cout << "Display elements using recursion: ";
    list.displayRecursion(list.getHead());
    cout << endl;

    cout << "Count elements using loop: " << list.countLoop() << endl;

    cout << "Count elements using recursion: " << list.countRecursion(list.getHead()) << endl;

    list.deleteFirst();
    cout << "After deleting first element: ";
    list.displayLoop();

    list.deleteLast();
    cout << "After deleting last element: ";
    list.displayLoop();

    list.deleteNode(15);
    cout << "After deleting node with value 15: ";
    list.displayLoop();

    return 0;
}

