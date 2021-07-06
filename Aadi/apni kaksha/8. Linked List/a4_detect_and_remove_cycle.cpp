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

void make_cycle(Node* head, int pos){
  Node* temp = head;
  Node* cycle_start = NULL;
  int count = 1;
  while(temp->next != NULL){
    if(count == pos){
      cycle_start = temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = cycle_start;
}

bool detect_cycle(Node* head){
  Node *slow = head, *fast = head;
  Node *temp = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      cout<<"Cycle detected!"<<endl;
      return true;
    }
  }
  cout<<"No cycle detected"<<endl;
  return false;
}

remove_cycle(Node* head){
  if(detect_cycle(head)){
    Node *slow = head, *fast = head;
    do{
      slow = slow->next;
      fast = fast->next->next;
    } while(slow != fast);

    fast = head;
    while(fast->next != slow->next){
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = NULL;
    cout<<"Cycle removed!"<<endl;
  }
}

void print_cycle(Node* head, int n, int pos){
  if(detect_cycle(head)){
    for(int i=0; i < (2*n-pos+2); i++){
      cout<<head->data<<"->";
      head = head->next;
    }
    cout<<"..."<<endl;
  }
  else{
    printList(head);
  }
}


int main(){
  int n, pos;
  cout<<"Enter n: ";
  cin>>n;
  cout<<"Enter pos: ";
  cin>>pos;
  Node* head = NULL;
  for(int i=0; i<n; i++){
    insertAtTail(&head, i+1);
  }
  printList(head);

  make_cycle(head, pos);
  // detect_cycle(head);
  print_cycle(head, n, pos);
  remove_cycle(head);
  print_cycle(head, n, pos);

  return 0;
}