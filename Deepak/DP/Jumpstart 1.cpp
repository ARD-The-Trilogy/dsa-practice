#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int N, mod = 1e9 + 7;
map<string, long long> mp;

bool isSmaller(string str1, string str2)
{
    int len1 = str1.length(), len2 = str2.length();
    if (len1 < len2)
        return true;
    if (len1 > len2)
        return false;

    int i = 0;
    while (i < len1)
    {
        if (str1[i] < str2[i])
            return true;
        i++;
    }
    return false;
}

int rec(string &str, string pre_num, int st)
{
    if (st == N)
        return 1;
    if (str[st] == '0')
        return 0;

    string srch = pre_num + '|' + to_string(st);
    if (mp.find(srch) != mp.end())
        return mp[srch];

    long long tot = 0;
    string tmp = "";
    for (int k = st; k < N; k++)
    {

        tmp += str[k];
        if (isSmaller(pre_num, tmp))
        {
            // cout << pre_num << ' ' << tmp << endl;
            tot += rec(str, tmp, k + 1);
            tot %= mod;
        }
    }
    return mp[srch] = tot;
}

int main()
{

    int n;
    string str;
    cin >> n;
    cin >> str;

    N = n;
    int ans = rec(str, "0", 0);
    cout << ans << endl;
}
