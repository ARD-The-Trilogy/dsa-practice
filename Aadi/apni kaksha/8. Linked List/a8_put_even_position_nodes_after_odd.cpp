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

void put_even_position_nodes_after_odd(Node* head){
  Node *odd = head, *even = head->next;
  Node *even_start = head->next;
  while(odd->next != NULL && even->next != NULL){
    odd->next = even->next;
    odd = even->next;
    even->next = odd->next;
    even = odd->next;
  }
  odd->next = even_start;
}

int main(){
  int n, k;
  cout<<"Enter n: ";
  cin>>n;
  Node* head = NULL;
  for(int i=0; i<n; i++){
    insertAtTail(&head, i+1);
  }
  printList(head);

  put_even_position_nodes_after_odd(head);

  printList(head);
  return 0;
}