// https://practice.geeksforgeeks.org/problems/anagram-palindrome4720/1#

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    int ans = 0, cnt = 0;
    bool f1 = true;
    for (auto chr : str)
    {
        int pos = chr - 'a';
        ans = ans ^ (1 << pos);
    }

    while (ans)
    {
        ans = ans & (ans - 1);
        cnt++;
    }

    if (str.size() % 2 && cnt != 1)
    {
        f1 = false;
    }
    else if (str.size() % 2 == 0 && cnt != 0)
    {
        f1 = false;
    }

    cout << f1 << endl;
}
