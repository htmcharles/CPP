#include <iostream>
using namespace std;

//creation of the node
struct Node{
	int data;
	Node *next;
	
	Node(int d){
		data = d;
		next = NULL;
	}
};

// function to add a node to the linked list
void addNode(Node *head, Node *nu){
	if(head == NULL){
		head = nu;
		return;
	}
	
	while(head->next != NULL){
		head = head->next;
	}
		
	head->next = nu;
}

void sort(Node *head) {
    Node *temp, *tail = NULL;
    while(head != NULL) {
        bool swapped = false;
        temp = head;
        while(temp->next != tail){
            if(temp->data > temp->next->data){
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
        tail = temp; // Update the last sorted node
        if (!swapped) break; // If there was no swap, the list is already sorted
    }
}


// function to delete a node from the end of the stack
void deleteNode(Node *head){
	Node *prev;
	if((head)->next == NULL){
		head = NULL;
		return;
	}
		
	while(head->next != NULL){
		prev = head;
		head = head->next;
	}
	prev->next = NULL;
}

// creation of a stack using a linked list
struct Stack{
	Node *head;
} stack1;
	
// we don't need isFull since the stack is created using a linked list
	
// isEmpty to chech whether the stack or queue is empty or not
bool isEmpty(Node *head){
	return head == NULL;
}
	
// function to add a node at the end of the stack
void push(Node *head, Node *nu){
	head->next = nu;
	head = nu;
}
	
// function to remove a node from the end of the stack
void pop(Node *head){
	head = NULL;
}

// creation of a queue using a linked list
struct Queue{
	Node *head;
} queue1;

// we don't need isFull because the queue is created using a linked list
	
// function to add a node at the end of the queue
void enqueue(Node *head, Node *nu){
	if(head == NULL){
		head = nu;
	}
		
	while(head->next != NULL){
		head = head->next;
	}
		
	head->next = nu;
}
	
// function to remove the last node from the queque
void dequeue(Node *head){
	while(head->next != NULL){
		head = head->next;
	}
		
	head = NULL;
}

// function to print all nodes
void print(Node *head){
	while(head != NULL){
		cout<<head->data<<", ";
		head = head->next;
	}
	
	cout<<endl;
}

int main(){
	int input, d;
	while(true){
		cout<<"Enter your choice: "<<endl;
		cout<<"1. Operate on Linkded List\n2. Operate on Stack\n3. Operate on Queue\n0. Exit"<<endl;
		// save user's choice into input
		cin>>input;
		
		switch(input){
			// for choice 0, end program
			case 0: return 0;
					
			// for choice 1, ...
			case 1: {
						cout<<"Enter value for node 1: ";
						cin>>d;
						Node *n1 = new Node(d);
						
						cout<<"Enter value for node 2: ";
						cin>>d;
						Node *n2 = new Node(d);
						
						cout<<"Enter value for node 3: ";
						cin>>d;
						Node *n3 = new Node(d);
						
						cout<<"Enter value for node 4: ";
						cin>>d;
						Node *n4 = new Node(d);
						
						addNode(n1, n2);
						addNode(n2, n3);
						addNode(n3, n4);
						cout<<"Linked list after adding 4 elements: ";
						print(n1);
						
						sort(n1);
						deleteNode(n1);
						cout<<"Linked list after sorting its elements and deletion of the last element: ";
						print(n1);
						break;
					}
					
					
			// for choice 2, ...
			case 2: {
						cout<<"Enter value to push onto stack: ";
						cin>>d;
						Node *n1 = new Node(d);
						
						cout<<"Enter value to push onto stack: ";
						cin>>d;
						Node *n2 = new Node(d);
						
						cout<<"Enter value to push onto stack: ";
						cin>>d;
						Node *n3 = new Node(d);
						
						cout<<"Enter value to push onto stack: ";
						cin>>d;
						Node *n4 = new Node(d);
						
						cout<<"Enter value to push onto stack: ";
						cin>>d;
						Node *n5 = new Node(d);
						
						
						push(n1, n2);
						push(n2, n3);
						push(n3, n4);
						push(n4, n5);
						
						if(!isEmpty(n5)){
							pop(n5);
						}
						cout<<"Stack elements after after 5 pushing and 1 pop operations: ";
						print(n1);
						break;
					}
					
			//cor choice 3, ...
			case 3: {
						cout<<"Enter a value to add to queue: ";
						cin>>d;
						Node *n1 = new Node(d);
						
						cout<<"Enter a value to add to queue: ";
						cin>>d;
						Node *n2 = new Node(d);
						
						cout<<"Enter a value to add to queue: ";
						cin>>d;
						Node *n3 = new Node(d);
						
						cout<<"Enter a value to add to queue: ";
						cin>>d;
						Node *n4 = new Node(d);
						
						cout<<"Enter a value to add to queue: ";
						cin>>d;
						Node *n5 = new Node(d);
						
						enqueue(n1, n2);
						enqueue(n2, n3);
						enqueue(n3, n4);
						enqueue(n4, n5);
						
						if(!isEmpty(n5)){
							dequeue(n1);
						}
						cout<<"Queue elements after 5 enqueue and 1 dequeue operations: ";
						print(n1);
						break;
					}
					
			default: cout<<"Invalid choice."<<endl;
		}
	}
	return 0;
}