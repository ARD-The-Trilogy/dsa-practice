#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
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

bool isPalindrome(string str)
{
    if (str.length() % 2 == 0)
        return false;
    int len = str.length();
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
            return false;
    }
    return true;
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

    prefix[0] = vt[0];
    for (int i = 1; i < size; i++)
    {
        prefix[i] = vt[i] + prefix[i - 1];
    }

    cin >> q;
    ll tot_powers = 0;
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        tot_powers = prefix[r];
        tot_powers -= prefix[l];

        // cout << vt[l] << ' ' << tot_powers << endl;
        cout << power(vt[l], tot_powers) << endl;
    }
}
