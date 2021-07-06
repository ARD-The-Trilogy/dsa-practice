#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void calcChefora(set<ll> &chefora, string str, int len, int dist)
{
    if (chefora.size() < 1e5 + 1)
    {
        int mid = len / 2;
        for (int i = 0; i <= 9; i++)
        {
            // put the int before and after the number.
            if (dist == mid && i == 0)
                continue;
            str[mid - dist] = '0' + i;
            str[mid + dist] = '0' + i;
            // cout << str << endl;

            if (chefora.size() < 1e5 + 1)
                chefora.insert(stol(str));

            if (dist != mid)
                calcChefora(chefora, str, len, dist + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    set<ll> chefora;
    for (int len = 1; len < 12; len += 2)
    {
        string str(len, '0');
        str[0] = '1';
        str[len - 1] = '1';
        chefora.insert(stol(str));
        calcChefora(chefora, str, len, 0);
    }

    vector<int> vt;
    for (auto it : chefora)
    {
        vt.push_back(it);
    }
    // vt.push_back(1000000001)

    cout << *chefora.rbegin() << endl;

    cout << chefora.size();

    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
    }
}
