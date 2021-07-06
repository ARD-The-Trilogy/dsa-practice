#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }

};


void rightView(Node* root){
  if(root == NULL){
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    for(int i=0; i<n; i++){
      Node* k = q.front();
      q.pop();
      if(i == n-1){
        cout<<k->data<<' ';
      }
      if(k->left != NULL){
        q.push(k->left);
      }
      if(k->right != NULL){
        q.push(k->right);
      }
    }
  }
}

void leftView(Node* root){
  if(root == NULL){
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    for(int i=0; i<n; i++){
      Node* k = q.front();
      q.pop();
      if(i == 0){
        cout<<k->data<<' ';
      }
      if(k->left != NULL){
        q.push(k->left);
      }
      if(k->right != NULL){
        q.push(k->right);
      }
    }
  }
}



int main(){
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  // root->left->left->right = new Node(8);
  // root->right->left->left = new Node(9);
  // root->left->left->right->left = new Node(10);

  cout<<"Right View: ";
  rightView(root);
  cout<<"\nLeft View: ";
  leftView(root);

  return 0;
}
