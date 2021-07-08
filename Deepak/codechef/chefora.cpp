#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int mod = 1e9 + 7;
ll power(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

void calcChefora(set<ll> &chefora, string str, int len, int dist)
{
    if (chefora.size() < 1e5)
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

    chefora.insert(10000000001);
    vector<ll> vt, prefix;
    for (auto it : chefora)
    {
        vt.push_back(it);
        prefix.push_back(it);
    }

    int size = vt.size();
    // cout << size << endl;
    // for (int i = size - 1; i >= size - 100; i--)
    // {
    //     cout << vt[i] << endl;
    // }

    int q, l, r;

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            continue;
        prefix[i] += prefix[i - 1];
    }

    cin >> q;
    int tot_powers = 0;
    while (q--)
    {
        cin >> l >> r;
        tot_powers = prefix[r - 1];
        tot_powers -= prefix[l - 1];

        cout << vt[l - 1] << ' ' << tot_powers << endl;
        cout << power(vt[l - 1], tot_powers) << endl;
    }
}
