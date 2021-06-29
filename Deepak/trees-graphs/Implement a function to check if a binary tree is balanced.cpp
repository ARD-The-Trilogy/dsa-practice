// * Check Balanced : Implement a function to check if a binary tree is balanced.For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val, Node *le, Node *ri)
    {
        data = val;
        left = le;
        right = ri;
    }
};

Node *rootNode = 0;

void makeTree();
int isBalanced(Node *, bool &);

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    makeTree();
    bool balanced = true;
    // cout << rootNode->data << endl;
    isBalanced(rootNode, balanced);
    cout << balanced << endl;
}

int isBalanced(Node *tempNode, bool &balanced)
{
    if (!tempNode)
        return 0;

    int leftHeight = isBalanced(tempNode->left, balanced);
    int rightHeight = isBalanced(tempNode->right, balanced);

    // * DEBUG INFO
    // cout << tempNode->data << ' ' << leftHeight << ' ' << rightHeight << endl;

    if (abs(leftHeight - rightHeight) > 1)
    {
        balanced &= false;
    }

    return max(leftHeight, rightHeight) + 1;
}

void makeTree()
{
    Node *Node1 = new Node(1, 0, 0);
    Node *Node2 = new Node(2, 0, 0);
    Node *Node3 = new Node(3, 0, 0);
    Node *Node4 = new Node(4, 0, 0);
    Node *Node5 = new Node(5, 0, 0);
    Node *Node6 = new Node(6, 0, 0);
    Node *Node7 = new Node(7, 0, 0);
    Node *Node8 = new Node(8, 0, 0);
    Node *Node9 = new Node(9, 0, 0);
    Node *Node10 = new Node(10, 0, 0);
    Node *Node11 = new Node(11, 0, 0);
    Node *Node12 = new Node(12, 0, 0);
    Node *Node13 = new Node(13, 0, 0);
    Node *Node14 = new Node(14, 0, 0);

    // asymetric tree
    rootNode = Node5;

    Node5->left = Node6;
    Node5->right = Node7;

    Node6->left = Node8;
    Node6->right = Node1;

    Node1->left = Node3;

    Node7->left = Node2;

    Node2->left = Node4;
    Node2->right = Node9;

    Node9->left = Node10;

    Node10->right = Node11;

    Node11->right = Node12;

    Node3->left = Node13;
    Node3->right = Node14;

    // Symmetric tree
    // Node6->data = 6;
    // Node7->data = 6;
    // Node2->data = 8;
    //
    // Node5->left = Node6;
    // Node5->right = Node7;

    // Node6->left = Node8;
    // Node6->right = Node1;

    // Node7->left = Node2;
}
