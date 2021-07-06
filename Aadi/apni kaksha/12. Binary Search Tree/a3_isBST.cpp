#include<bits/stdc++.h>
using namespace std;

struct Node {

  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }

};

Node* insertBSTNode(Node* root, int val){
  if(root == NULL){
    return new Node(val);
  }
  if(val < root->data){
    root->left = insertBSTNode(root->left, val);
  }
  else{
    root->right = insertBSTNode(root->right, val);
  }
  return root;
}
 
void inorder(Node* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}


bool isBST(Node* root, int min, int max){
  if(root == NULL){
    return true;
  }
  if(root->data <= min || root->data >= max){
    return false;
  }
  bool isLeftValid = isBST(root->left, min ,root->data);
  bool isRightValid = isBST(root->right, root->data, max);

  return isLeftValid && isRightValid;
}




// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/


int main(){

  Node* root = NULL;
  vector <int> v = {5,1,7,3,8,10,2,4};
  // vector <int> v = {10,5,15,2,8,12,18,1,6,9,14,20};
  for(int i=0; i<v.size(); i++){
    if(i==0){
      root = insertBSTNode(root, v[i]);
    } else {
      insertBSTNode(root, v[i]);
    }
  }
  
/*
           5
        /     \
      1        7
       \      /  \
        3    8   10
      /  \
     2    4    
        
*/
  inorder(root);

  if(isBST(root, INT_MIN, INT_MAX)){
    cout<<"Valid BST"<<endl;
  } else {
    cout<<"Invalid BST"<<endl;
  }

  return 0;
}
