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


void inorder(struct Node* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}

void preorder(struct Node* root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<' ';
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct Node* root){
  if(root == NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<' ';
}


int main(){
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout<<"inorder: ";
  inorder(root);
  cout<<"\npreorder: ";
  preorder(root);
  cout<<"\npostorder: ";
  postorder(root);

  return 0;
}


// inorder: 4 2 5 1 6 3 7 
// preorder: 1 2 4 5 3 6 7  
// postorder: 4 5 2 6 7 3 1 