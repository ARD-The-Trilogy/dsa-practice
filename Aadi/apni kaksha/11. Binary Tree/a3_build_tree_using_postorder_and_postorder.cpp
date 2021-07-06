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

search_inorder(int inorder[], int start, int end, int currVal){
  while ((start <= end) && (inorder[start] != currVal)){
    start++;
  }
  if(inorder[start] == currVal){
    return start;
  }
  return -1;
}

Node* buildTree_using_preorder(int preorder[], int inorder[], int start, int end){
  if(start > end){
    return NULL;
  }

  static int i = 0;               // static int is a must
  int curr_val = preorder[i];
  i++;

  Node* new_node = new Node(curr_val);

  if(start == end){
    return new_node;
  }
  int pos = search_inorder(inorder, start, end, curr_val);
  new_node->left = buildTree_using_preorder(preorder, inorder, start, pos-1);
  new_node->right = buildTree_using_preorder(preorder, inorder, pos+1, end);

  return new_node;
}

Node* buildTree_using_postorder(int postorder[], int inorder[], int start, int end, int n){
  if(start > end){
    return NULL;
  }

  // static int i = sizeof(postorder)/postorder[0];    // this(use of sizeof) is incorrect inside fxn        
  static int i = n-1;                                  // static int is a must
  int curr_val = postorder[i];
  i--;

  Node* new_node = new Node(curr_val);

  if(start == end){
    return new_node;
  }
  int pos = search_inorder(inorder, start, end, curr_val);
  new_node->right = buildTree_using_postorder(postorder, inorder, pos+1, end, n);
  new_node->left = buildTree_using_postorder(postorder, inorder, start, pos-1, n);

  return new_node;
}


void inorder(struct Node* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}



int main(){
  int arr_size = 7;
  int inorder_arr[] = {4, 2, 5, 1, 6, 3, 7};
  int preorder_arr[] = {1, 2, 4, 5, 3, 6, 7};
  int postorder_arr[] = {4, 5, 2, 6, 7, 3, 1};

  Node* pre_root = buildTree_using_preorder(preorder_arr, inorder_arr, 0, 6);
  cout<<"inorder & preorder => inorder: "<<endl;
  inorder(pre_root);
  Node* post_root = buildTree_using_postorder(postorder_arr, inorder_arr, 0, 6, arr_size);
  cout<<endl<<"inorder & postorder => inorder: "<<endl;
  inorder(post_root);

  return 0;
}