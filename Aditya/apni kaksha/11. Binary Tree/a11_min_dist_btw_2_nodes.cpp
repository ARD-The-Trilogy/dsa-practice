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

Node* LCS(Node* root, Node* n1, Node* n2){
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

// int dist_btw_root_and_node(Node* root, Node* n, int d){
//   if(root == NULL){
//     return -1;
//   }
//   if(root == n){
//     return d;
//   }
//   int left = dist_btw_root_and_node(root->left, n, d+1);
//   if(left != -1){
//     return left;
//   }
//   return dist_btw_root_and_node(root->right, n, d+1);
// }


int min_dist_btw_nodes(Node* root, Node* n1, Node* n2){
  Node* lcs = LCS(root, n1, n2);

  int d1 = dist_btw_root_and_node(lcs, n1, 0);
  int d2 = dist_btw_root_and_node(lcs, n2, 0);

  return d1 + d2;
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

  Node* n1 = root->left->left;  // 4
  Node* n2 = root->left->right; // 5

  cout<<"min dist b/w n1 & n2: "<<min_dist_btw_nodes(root, n1, n2);

  return 0;
}
