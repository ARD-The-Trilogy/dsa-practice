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


void level_order_traversal(struct Node* root){
  if(root == NULL){
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* k = q.front();
    q.pop();
    cout<<k->data<<' ';
    if(k->left != NULL){
      q.push(k->left);
    }
    if(k->right != NULL){
      q.push(k->right);
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

  cout<<"level order traversal: ";
  level_order_traversal(root);

  return 0;
}
