// link: https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void insertAtBottom(stack<int> &stk, int inp)
{
    if (stk.empty())
    {
        stk.push(inp);
        return;
    }

    int num = stk.top();
    stk.pop();
    insertAtBottom(stk, inp);
    stk.push(num);
}

void reverseStack(stack<int> &stk)
{
    if (stk.empty())
        return;

    int num = stk.top();
    stk.pop();
    reverseStack(stk);

    // now insert it at bottom
    insertAtBottom(stk, num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, inp;
    stack<int> stk;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        stk.push(inp);
    }

    reverseStack(stk);
    for (int i = 0; i < n; i++)
    {
        inp = stk.top();
        cout << inp << ' ';
        stk.pop();
    }
}
