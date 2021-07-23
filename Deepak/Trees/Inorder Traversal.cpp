// LINK: 

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

// GFG Submission
vector<int> inOrder(Node *root)
{
    //code here
    vector<int> nums;
    stack<Node *> vert, hori;

    vert.push(root);
    while (!vert.empty())
    {
        Node *tmp = vert.top();
        vert.pop();

        if (!tmp->left && !tmp->right)
        {
            nums.push_back(tmp->data);
        }
        else if (!hori.empty() && tmp == hori.top())
        {
            nums.push_back(tmp->data);
            hori.pop();
        }
        else
        {

            if (tmp->right)
                vert.push(tmp->right);

            vert.push(tmp);

            if (tmp->left)
                vert.push(tmp->left);

            hori.push(tmp);
        }
    }

    return nums;
}
