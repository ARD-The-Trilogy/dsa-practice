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

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  return max(height(root->left), height(root->right)) + 1;
}


// Basic Approach [ O(n^2) ]

bool isBalanced(Node* root){
  if(root == NULL){
    return true;
  }
  if(!isBalanced(root->left) || !isBalanced(root->right)){
    return false;
  }

  int lh = height(root->left);
  int rh = height(root->right);
  
  if(abs(lh - rh) <= 1){
    return true;
  }
  return false;
}


// Optimized Approach [ O(n) ]

bool balanced_height(Node* root, int* height){
  if(root == NULL){
    return true;
  }
  int lh = 0, rh = 0;
  if(!balanced_height(root->left, &lh) || !balanced_height(root->right, &rh)){
    return false;
  }
  *height = max(lh, rh) + 1;
  if(abs(lh - rh) <= 1){
    return true;
  }
  return false;
}



int main(){
  struct Node* root = new Node(1);
  // root->left = new Node(2);
  root->right = new Node(3);
  // root->left->left = new Node(4);
  // root->left->right = new Node(5);
  // root->right->left = new Node(6);
  root->right->right = new Node(7);


  cout<<isBalanced(root)<<" => ";


  int h = height(root);

  if(balanced_height(root, &h)){
    cout<<"Balanced height"<<endl;
  }
  else{
    cout<<"Unbalanced height"<<endl;
  }

  return 0;
}



