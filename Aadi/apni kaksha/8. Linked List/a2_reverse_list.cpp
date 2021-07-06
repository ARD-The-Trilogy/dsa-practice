#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int val){
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

void printList(Node* head){
  while(head != NULL){
    cout<<head->data<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}

void reverseList(Node** head){
  Node* curr = *head;
  Node *prev = NULL, *temp = NULL;
  if(*head == NULL){
    return;
  }
  while (curr != NULL){                 // important decision
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  *head = prev;
}

int main(){
  Node* head = NULL;
  for(int i=0; i<5; i++){
    insertAtTail(&head, i+1);
  }
  printList(head);
  reverseList(&head);
  printList(head);
  return 0;
}