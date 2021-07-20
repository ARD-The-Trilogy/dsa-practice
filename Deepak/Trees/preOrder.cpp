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

void preOrderIterative()
{
    stack<Node *> stk; // for storing Nodes addreses;

    stk.push(root);
    while (!stk.empty())
    {
        Node *temp = stk.top();
        stk.pop();
        cout << temp->data << ' ';
        if (temp->right)
            stk.push(temp->right);
        if (temp->left)
            stk.push(temp->left);
    }
    cout << endl;
}
