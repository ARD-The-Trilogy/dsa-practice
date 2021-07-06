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


void flatten(Node* root){

  // if(root == NULL || (root->left == NULL && root->right == NULL)){
  if(root == NULL){
    return;
  }

  if(root->left != NULL){

    flatten(root->left);

    Node* temp = root->right;
    root->right = root->left;
    root->left = NULL;

    Node* tail = root;
    while(tail->right != NULL){
      tail = tail->right;
    }
    tail->right = temp;

    // flatten(temp);    // not correct
  }
  flatten(root->right);
}

void preorder(Node* root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<' ';
  preorder(root->left);
  preorder(root->right);
}

void traverse(Node* root){
  while(root != NULL){
    cout<<root->data<<' ';
    root = root->right;
  }
}


int main(){

/*       1
      /     \
     2       3
      \     /  \
       5    6   7
        \
         9
       /  \
      10   11
*/

  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  // root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  // root->left->left->right = new Node(8);
  root->left->right->right = new Node(9);
  root->left->right->right->left = new Node(10);     
  root->left->right->right->right = new Node(11);      

  cout<<"Before flattening: ";
  preorder(root);

  flatten(root);

  cout<<"\nAfter flattening: ";
  // preorder(root);
  traverse(root);

  return 0;
}
