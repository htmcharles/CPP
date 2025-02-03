
// queue

#include <iostream>

#define MAX_SIZE 5

using namespace std;

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
bool isFull() {
  return rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
bool isEmpty() {
  return front == -1;
}

// Function to enqueue (add) an element
void enqueue(int data) {
  if (isFull()) {
    cout << "Queue overflow!" << endl;
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear++;
  queue[rear] = data;
  cout << data << " enqueued successfully." << endl;
}

// Function to dequeue (remove) an element
void dequeue() {
  if (isEmpty()) {
    cout << "Queue underflow!" << endl;
    return;
  }
  int data = queue[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
  cout << data << " dequeued successfully." << endl;
}

// Function to display the queue elements
void display() {
  if (isEmpty()) {
    cout << "Queue is empty." << endl;
    return;
  }
  cout << "Queue elements: ";
  for (int i = front; i <= rear; i++) {
    cout << queue[i] << " ";
  }
  cout << endl;
}

int main() {
  int choice, data;

  do {
    cout << "\n1. Enqueue (Add)" << endl;
    cout << "2. Dequeue (Remove)" << endl;
    cout << "3. Display" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        if (rear < MAX_SIZE - 1) {
          cout << "Enter data to enqueue: ";
          cin >> data;
          enqueue(data);
        }
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 0:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  } while (choice != 0);

  return 0;
}
