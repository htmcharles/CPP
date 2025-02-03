#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};
// lInked list implementation
// Linked list implementation
class LinkedList {
	private:
		Node* head;

	public:
		LinkedList() : head(nullptr) {}

		void insertNode(int val) {
			Node* newNode = new Node(val);
			if (!head) {
				head = newNode;
			} else {
				Node* temp = head;
				while (temp->next) {
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}

		void display() {
			Node* temp = head;
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}

		void insertionSort() {
			if (!head || !head->next) {
				return;
			}

			Node* sorted = nullptr;
			Node* current = head;
			while (current) {
				Node* next = current->next;
				if (!sorted || current->data < sorted->data) {
					current->next = sorted;
					sorted = current;
				} else {
					Node* temp = sorted;
					while (temp->next && temp->next->data < current->data) {
						temp = temp->next;
					}
					current->next = temp->next;
					temp->next = current;
				}
				current = next;
			}
			head = sorted;
		}

		void deleteLast() {
			if (!head) {
				return;
			}
			if (!head->next) {
				delete head;
				head = nullptr;
				return;
			}
			Node* temp = head;
			while (temp->next->next) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
};


// Simple Stack implementation
class Stack {
	private:
		static const int MAX_SIZE = 100;
		int arr[MAX_SIZE];
		int topIndex;

	public:
		Stack() : topIndex(-1) {}

		bool isEmpty() {
			return topIndex == -1;
		}

		bool isFull() {
			return topIndex == MAX_SIZE - 1;
		}

		void push(int val) {
			if (!isFull()) {
				arr[++topIndex] = val;
			} else {
				cout << "Stack full. Cannot push element.\n";
			}
		}

		void pop() {
			if (!isEmpty()) {
				--topIndex;
			} else {
				cout << "Stack empty. Cannot pop element.\n";
			}
		}

		int top() {
			if (!isEmpty()) {
				return arr[topIndex];
			} else {
				cout << "Stack empty.\n";
				return -1; // Not a valid value, just to indicate error
			}
		}
};

// Simple Queue implementation
class Queue {
	private:
		static const int MAX_SIZE = 100;
		int arr[MAX_SIZE];
		int frontIndex;
		int rearIndex;

	public:
		Queue() : frontIndex(-1), rearIndex(-1) {}

		bool isEmpty() {
			return frontIndex == -1;
		}

		bool isFull() {
			return (frontIndex == 0 && rearIndex == MAX_SIZE - 1) || (frontIndex == rearIndex + 1);
		}

		void enqueue(int val) {
			if (!isFull()) {
				if (isEmpty()) {
					frontIndex = 0;
				}
				rearIndex = (rearIndex + 1) % MAX_SIZE;
				arr[rearIndex] = val;
			} else {
				cout << "Queue full. Cannot enqueue element.\n";
			}
		}

		void dequeue() {
			if (!isEmpty()) {
				if (frontIndex == rearIndex) {
					frontIndex = -1;
					rearIndex = -1;
				} else {
					frontIndex = (frontIndex + 1) % MAX_SIZE;
				}
			} else {
				cout << "Queue empty. Cannot dequeue element.\n";
			}
		}

		int front() {
			if (!isEmpty()) {
				return arr[frontIndex];
			} else {
				cout << "Queue empty.\n";
				return -1; // Not a valid value, just to indicate error
			}
		}
};

// Insertion Sort algorithm
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int choice;
	LinkedList linkedList;
	Stack stack;
	Queue queue;

	do {
		cout << "\nEnter your choice\n1. Operate on linked list\n2. Operate on stack\n3. Operate on Queue\n0. Exit\n";
		cin >> choice;

		switch (choice) {
			case 1:
				linkedList = LinkedList(); // Reset the linked list

				// Input values for the linked list nodes
				cout << "Enter values for 5 nodes:\n";
				for (int i = 0; i < 5; ++i) {
					int val;
					cout << "Enter value for node " << i + 1 << ": ";
					cin >> val;
					linkedList.insertNode(val);
				}

				cout << "Linked list after adding elements: ";
				linkedList.display();

				linkedList.insertionSort();
				linkedList.deleteLast();

				cout << "Linked list after sorting and deletion of the last node: ";
				linkedList.display();
				break;


			case 2:
				// Operate on stack
				cout << "Pushing 5 elements onto the stack:\n";
				for (int i = 0; i < 5; ++i) {
					int val;
					cout << "Enter the value to push onto the stack : ";
					cin >> val;
					stack.push(val);
				}
				cout << "Stack elements after pushing and popping 1 element: ";
				while (!stack.isEmpty()) {
					cout << stack.top() << " ";
					stack.pop();
				}
				cout << endl;
				break;
			case 3:
				// Operate on queue
				cout << "Adding 5 elements to the queue:\n";
				for (int i = 0; i < 5; ++i) {
					int val;
					cout << "Enter the value to add to queue : ";
					cin >> val;
					queue.enqueue(val);
				}
				cout << "Queue elements after 5 enqueues and 1 dequeue operations: ";
				while (!queue.isEmpty()) {
					cout << queue.front() << " ";
					queue.dequeue();
				}
				cout << endl;
				break;
			case 0:
				cout << "\nExiting the program ....\n";
				break;
			default:
				cout << "Invalid choice! Please enter a valid option.\n";
		}
	} while (choice != 0);

	return 0;
}
