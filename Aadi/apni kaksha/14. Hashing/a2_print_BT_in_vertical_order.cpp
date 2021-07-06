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

// https://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

void verticalOrder(Node* root, int hd, map<int, vector<int>> &mp){
  if(root == NULL){
    return;
  }
  mp[hd].push_back(root->data);
  verticalOrder(root->left, hd - 1, mp);
  verticalOrder(root->right, hd + 1, mp);
}

int main(){

/*
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
*/
/*        1
        / .  \
       2  .   3
        \ .  /.\
          5 / . 7
          6 \ . .
          .   9 .
          . /  \.
          10    11
*/

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
                 10
              /     \
            5        15
          /  \      /   \
        2     8    12    18
      /     /  \     \      \
     1     6    9     14     20
             
            
*/

  map<int, vector<int>> mp;

  cout<<"vertical order traversal: ";
  verticalOrder(root, 0, mp);

  for(auto it= mp.begin(); it != mp.end(); it++){
    cout<<endl<<it->first<<" => ";
    for(int i=0; i < (it->second).size(); i++){
      cout<<(it->second)[i]<<' ';
    }
  }

  return 0;
}
