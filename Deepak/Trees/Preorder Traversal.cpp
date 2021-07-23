// Link: https://www.geeksforgeeks.org/iterative-preorder-traversal/

#include <bits/stdc++.h>
#include "buildTree.h"
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void preOrderRec(Node *);
void preOrderIterative();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    makeTree();
    preOrderRec(root);
    cout << endl;
    // preOrderIterative();
}

void preOrderRec(Node *temp)
{
    if (temp)
    {
        cout << temp->data << ' ';
        preOrderRec(temp->left);
        preOrderRec(temp->right);
    }
}

// Geeks Submission
vector<int> preOrder(Node *root)
{
    //code here
    vector<int> nums;
    stack<Node *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        Node *tmp_root = stk.top();
        stk.pop();

        nums.push_back(tmp_root->data);

        if (tmp_root->right)
            stk.push(tmp_root->right);

        if (tmp_root->left)
            stk.push(tmp_root->left);
    }

    return nums;
}