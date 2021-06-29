// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

class Node
{
public:
  int val;
  Node *left, *right;

  Node(int data, Node *le, Node *ri)
  {
    val = data;
    left = le, right = ri;
  }
};

// Declarations
void makeTree();
void preOrderRec(Node *temp);

Node *root;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  makeTree();
  // preOrderRec(root);
  // cout << endl;

  vector<vector<int>> arrayNodes;
  vector<int> subArray;
  queue<Node *> qu;
  qu.push(root);
  qu.push(NULL);
  while (!qu.empty())
  {
    Node *temp = qu.front();
    qu.pop();
    if (temp)
      subArray.push_back(temp->val);
    // push temp->val into the vector

    if (!temp)
    {
      arrayNodes.push_back(subArray);
      subArray.clear();

      if (!qu.empty())
        qu.push(NULL);
    }

    if (temp && temp->left)
    {
      qu.push(temp->left);
    }
    if (temp && temp->right)
    {
      qu.push(temp->right);
    }
  }

  for (int i = 0; i < arrayNodes.size(); i++)
  {
    cout << "Level:" << i << " ";
    for (auto it : arrayNodes[i])
    {
      cout << it << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void preOrderRec(Node *temp)
{
  if (temp)
  {
    cout << temp->val << ' ';
    preOrderRec(temp->left);
    preOrderRec(temp->right);
  }
}

void makeTree()
{
  Node *node1 = new Node(1, 0, 0);
  Node *node2 = new Node(2, 0, 0);
  Node *node3 = new Node(3, 0, 0);
  Node *node4 = new Node(4, 0, 0);
  Node *node5 = new Node(5, 0, 0);
  Node *node6 = new Node(6, 0, 0);
  Node *node7 = new Node(7, 0, 0);
  Node *node8 = new Node(8, 0, 0);
  Node *node9 = new Node(9, 0, 0);
  Node *node10 = new Node(10, 0, 0);
  Node *node11 = new Node(11, 0, 0);
  Node *node12 = new Node(12, 0, 0);
  Node *node13 = new Node(13, 0, 0);
  Node *node14 = new Node(14, 0, 0);

  // asymetric tree
  root = node5;

  node5->left = node6;
  node5->right = node7;

  node6->left = node8;
  node6->right = node1;

  node1->left = node3;

  node7->left = node2;

  node2->left = node4;
  node2->right = node9;

  node9->left = node10;

  node10->right = node11;

  node11->right = node12;

  node3->left = node13;
  node3->right = node14;

  // Symmetric tree
  // node6->data = 6;
  // node7->data = 6;
  // node2->data = 8;
  //
  // node5->left = node6;
  // node5->right = node7;

  // node6->left = node8;
  // node6->right = node1;

  // node7->left = node2;
}
