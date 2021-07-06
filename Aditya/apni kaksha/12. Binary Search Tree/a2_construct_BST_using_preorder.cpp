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

Node* constructBST(int preorder[]){

}



void inorder(Node* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}


int main(){

  int preorder[] = {5, 1, 3, 2, 4, 7, 8, 10};

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
  
  int key;
  cout<<"\nEnter key: ";
  cin>>key;

  

  cout<<"inorder: ";
  inorder(root);


  return 0;
}
