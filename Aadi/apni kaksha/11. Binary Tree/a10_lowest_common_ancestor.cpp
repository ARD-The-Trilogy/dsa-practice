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

// METHOD - 1
// --------
// --------
// --------

// METHOD - 2

Node* LCS(Node* root, Node* n1, Node* n2){    // O(n)
  if(root == NULL){
    return NULL;
  }
  if(root == n1 || root == n2){
    return root;
  }

  Node* left = LCS(root->left, n1, n2);
  Node* right = LCS(root->right, n1, n2);

  if(left != NULL && right != NULL){
    return root;
  }
  if(left != NULL){
    return left;
  }
  if(right != NULL){
    return right;
  }
  return NULL;
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

  Node* n1 = root->left->left;
  Node* n2 = root->left->right;

  Node* lcs = LCS(root, n1, n2);
  cout<<"LCS: "<<lcs->data;

  return 0;
}
