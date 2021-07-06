#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    Node(int val){
      data = val;
      next = NULL;
    }
};

class Queue{
  public:
    Node* front;
    Node* back;
    Queue(){
      front = NULL;
      back = NULL;
    }

    void push(int val){
      Node* new_node = new Node(val);
      cout<<"pushing "<<val<<endl;
      if(front == NULL){
        front = new_node;
        back = new_node;
        return;
      }
      back->next = new_node;
      back = new_node;
    }

    bool empty(){
      if(front == NULL){
        cout<<"empty queue!"<<endl;
        return true;
      }
      return false;
    }

    void pop(){
      if(!empty()){
        Node* temp = front;
        front = front->next;
        cout<<"popping "<<temp->data<<endl;
        delete temp;
      }
    }

    int peek(){
      if(!empty()){
        cout<<"peek value: "<<front->data<<endl;
        return front->data;
      }
      return -1;
    }
};


int main(){
  Queue q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.peek();
  q.pop();
  q.pop();
  q.pop();
  q.pop();

  return 0;
}