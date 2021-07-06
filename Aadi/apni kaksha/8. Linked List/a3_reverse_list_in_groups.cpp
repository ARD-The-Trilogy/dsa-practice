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

Node* reverse_the_group(Node** head, int k){
  Node* curr = *head;
  Node* prev = NULL, *temp = NULL;
  int i = 0;
  while (curr != NULL && i < k){
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    i++;
  }
  *head = curr;                         
  return prev;
}

void reverse_list_in_groups(Node** head, int k){
  Node* curr = *head;
  Node* prev = NULL, *temp = NULL;
  Node* start = *head, *end = NULL;
  if(*head == NULL || k == 1){
    return;
  }
  while(curr != NULL){
    temp = curr;
    end = reverse_the_group(&curr, k);        //  &curr is passed
    if(start == *head){
      *head = end;
    }
    else{
      start->next = end;
    }
    start = temp;
  }
}

int main(){
  int n, k;
  cout<<"Enter n: ";
  cin>>n;
  cout<<"Enter k: ";
  cin>>k;
  Node* head = NULL;
  for(int i=0; i<n; i++){
    insertAtTail(&head, i+1);
  }
  printList(head);

  reverse_list_in_groups(&head, k);

  printList(head);
  return 0;
}