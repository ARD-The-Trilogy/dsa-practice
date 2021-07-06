#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int val){       // constructor
      data = val;
      next = NULL;
    }
};

void insertAtTail(Node** head, int val){
  Node* new_node = new Node(val);
  Node* temp = *head;
  if(temp == NULL){
    *head = new_node;
    return;
  }
  while(temp -> next != NULL){
    temp = temp -> next;
  }
  temp -> next = new_node;
}

void insertAtHead(Node** head, int val){
  Node* new_node = new Node(val);
  new_node -> next = *head;
  *head = new_node;
}

void deleteNode(Node** head, int key){
  Node* temp = *head;
  if(temp == NULL){
    return;
  }
  if(temp -> data == key){
    *head = temp -> next;
    delete temp;
    return;
  }
  Node* prev = NULL;
  while(temp != NULL && temp->data != key){
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL){   // this case must be handled first
    cout<<key<<" Not Found >> ";
    return;        // And this return statement is a must
  }                // if you're using temp further
  prev->next = temp->next;
  delete temp;
  cout<<key<<" Deleted >> ";
  // if(temp->data == val){
  //   prev->next = temp->next;
  //   delete temp;
  // }
}

bool searchNode(Node* head, int key){
  while(head != NULL && head->data != key){
    head = head->next;
  }
  if(head == NULL){
    cout<<key<<" Not Found"<<endl;
    return false;
  }
  cout<<key<<" Found"<<endl;
  return true;
}

void printList(Node* head){
  while(head != NULL){
    cout<<head->data<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}

int main(){

  Node* head = NULL;
  // Node* head = new Node(1);

  insertAtHead(&head, 1);
  printList(head);
  insertAtTail(&head, 2);
  printList(head);
  insertAtHead(&head, 3);
  printList(head);
  insertAtTail(&head, 4);
  printList(head);
  
  deleteNode(&head, 3);
  printList(head);
  deleteNode(&head, 4);
  printList(head);
  deleteNode(&head, 5);
  printList(head);

  insertAtHead(&head, 5);
  printList(head);
  insertAtTail(&head, 6);
  printList(head);

  searchNode(head, 2);
  searchNode(head, 4);
  searchNode(head, 5);

  return 0;
}