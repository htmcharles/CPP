#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
    
    static Node *merge(Node *a, Node *b){
        if(a == NULL){
            return b;
        }
        if(b == NULL){
            return a;
        }
        Node *c;
        if(a->data < b->data){
            c = a;
            c->next = merge(a->next,b);
        }else{
            c = b;
            c->next = merge(a,b->next);
        }
        return c;
    }

    static Node *midPoint(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node *fast = head;
        Node *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            if(fast->next == NULL){
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }

    static Node *mergeSort(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *mid = midPoint(head);
        Node *a = head;
        Node *b = mid->next;
        mid->next = NULL;
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a,b);
    }
};

/*
    Linked List implementation
*/

class LL {
private:
    Node* head;

public:
    LL() : head(NULL) {}

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "";
            temp = temp->next;
        }
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteLast(){
        if(head == NULL){
            return;
        }
        Node *current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    void mergeSortList(){
        head = Node::mergeSort(head);
    }
 
};

/*
    Stack Implemetation
*/


class Stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
    Stack():capacity(5),arr(new int[capacity]),nextIndex(0){}

    bool isEmpty(){
        return nextIndex == 0;
    }
    bool isFull(){
        return nextIndex == capacity;
    }
    void push(int ele){
        if(isFull()){
            cout<<"It is full(Overflow)"<<endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"It is empty(Underflow)"<<endl;
            return;
        }
        nextIndex--;
    }

    void display(){
        for(int i = 0 ; i < nextIndex; i++ ){
        cout<<arr[i]<<" ";
    }
    }
};

/*
  Queue implementation
*/

class Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

   public:
    Queue() : capacity(4), arr(new int[capacity]), rear(0), front(0), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int ele) {
        if (isFull()) {
            cout<<"It is full(Overflow)"<<endl;
        }
        arr[rear] = ele;
        rear++;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "It is empty(Underflow)" << endl;
            return;
        }

        for( int i=front; i<rear - 1;i++){
         arr[i]=arr[i+1];
        }

        rear--;
        size--;
    }

    void display() {
        for (int i = front; i < rear; i++) {
            cout << arr[i] << "";
        }
    }
};

int main() {
    LL linkedList;
    Stack s;
    Queue q;
    vector<string> collection = {"1.Operate on Linked List", "2.Operate on Stack", "3.Operate on Queue", "0.Exit"};

    while (true) {
        cout << "Enter your choice :" << endl;
        int choice;
        for (int i = 0; i < collection.size(); i++) {
            cout << collection[i] << endl;
        }

        cin >> choice;
        int value;

        if (choice == 1) {
            for (int i = 0; i < 4; i++) {
                cout << "Enter value for node " << i + 1 << " : ";
                cin >> value;
                linkedList.addNode(value);
                cout << endl;
            }

            cout << "Linked list after adding 4 elements :";
            linkedList.display();
            cout << "After sorting deleting last element : ";
            linkedList.mergeSortList();
            linkedList.display();
        } else if (choice == 2) {
            for (int i = 0; i < 5; i++) {
                cout << "Enter value to push onto stack : ";
                cin >> value;
                s.push(value);
                cout << endl;
            }

            cout << "Stack element after 5 pushing and 1 pop operation :";
            s.pop();
            s.display();
        } else if (choice == 3) {
            for (int i = 0; i < 5; i++) { 
                cout << "Enter value to add to queue : ";
                cin >> value;
                q.enqueue(value);
                cout << endl;
            }

            cout << "Queue element after 5 enqueue and 1 dequeue operation :";
            q.dequeue();
            q.display();
        }

        if (choice == 0) {
            break;
        }
    }

    return 0;
}
