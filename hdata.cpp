#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(){}
Node(int d){
data=d;
next=NULL;
}
};
void printList(Node *head){
while(head!=NULL){
cout<<head->data<<"->";
head=head->next;
}
cout<<"NULL"<<endl;
}
Node* addAtHead(Node *head,int value){
  Node *newNode=new Node(value);
  newNode->next=head;
  head=newNode;
  return head;
  }
 Node* addNode(Node *head,Node *sn){
  sn->next=head;
  head=sn;
  return head;
  } 
int main(){
Node *n1=new Node(10);
Node *n2=new Node(20);
Node *n3=new Node(30);
n1->next=n2;
n2->next=n3;
Node *head=n1;
printList(head);
cout<<"After adding first elements at the head"<<endl;
head=addAtHead(head,8);
printList(head);
cout<<"After adding first elements at the head"<<endl;
printList(addAtHead(head,50));
Node *n5=new Node(26);
head=addNode(head,n5);
//This should print 50->8->10->20->30->NULLL
return 0;
}

