#include <bits/stdc++.h>
#include "buildTree.h"
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void inOrderRec(Node *);
void inOrderIterative();


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    makeTree();
    inOrderRec(root);
    cout << endl;
    inOrderIterative();
}

void inOrderRec(Node *temp)
{
    if (temp)
    {
        inOrderRec(temp->left);
        cout << temp->data << ' ';
        inOrderRec(temp->right);
    }
}

void inOrderIterative()
{
    stack<Node *> stk;
    stk.push(root);
    stack<int> nums;

    while (!stk.empty())
    {
        Node *temp = stk.top();
        stk.pop();

        if (temp->right)
        {
            stk.push(temp->right);
        }

        if (temp->left)
        {
            stk.push(temp->left);
        }
        else
        {
            cout << temp->data << ' ';
            stk.pop();
            if (temp->right)
                stk.push(temp->right);
        }
    }
}
