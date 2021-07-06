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
 
bool searchBST(Node* root, int key){
  if(root == NULL){
    return false;
  }
  if(key == root->data){
    return true;
  }
  else if(key < root->data){
    return searchBST(root->left, key);
  }
  return searchBST(root->right, key);
}


Node* deleteBSTNode(Node* root, int key){
  if(root == NULL){
    return NULL;
  }
  if(key < root->data){
    root->left = deleteBSTNode(root->left, key);
  }
  else if(key > root->data){
    root->right = deleteBSTNode(root->right, key);
  }
  else{
    if(root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }
    else if(root->left == NULL || root->right == NULL){
      Node* temp = root;
      if(root->left == NULL){
        root = root->right;
      } else {
        root = root->left;
      }
      delete temp;
    }
    else{
      Node* temp = root->right;
      while(temp->left != NULL){
        temp = temp->left;
      }
      root->data = temp->data;
      root->right = deleteBSTNode(root->right, temp->data);
    }
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


int main(){

  Node* root = NULL;
  // vector <int> v = {5,1,7,3,8,10,2,4};
  vector <int> v = {10,5,15,2,8,12,18,1,6,9,14,20};
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
/*
                 10
              /     \
            5        15
          /  \      /   \
        2     8    12    18
      /     /  \     \      \
     1     6    9     14     20
             
            
*/

  cout<<"inorder: ";
  inorder(root);
  
  int key;
  cout<<"\nEnter key: ";
  cin>>key;

  if(searchBST(root, key)){
    cout<<key<<" Found"<<endl;
    root = deleteBSTNode(root, key);
    cout<<key<<" Deleted"<<endl;
  } else {
    cout<<key<<" Not Found";
  }

  cout<<"inorder: ";
  inorder(root);


  return 0;
}
