#include <bits/stdc++.h>
#include "buildTree.h"
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void levOrder();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    makeTree();
    levOrder();
    cout << endl;

}

void levOrder()
{
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *temp = qu.front();
        qu.pop();
        cout << temp->data << ' ';

        if (temp->left)
            qu.push(temp->left);
        if (temp->right)
            qu.push(temp->right);
    }
    cout << endl;
}
