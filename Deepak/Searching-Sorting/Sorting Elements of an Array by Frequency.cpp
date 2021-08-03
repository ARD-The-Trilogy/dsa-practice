// LINK: https://www.geeksforgeeks.org/sort-elements-by-frequency/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct compr
{

    bool operator()(const pair<int, int> &pr1, const pair<int, int> &pr2)
    {
        if (pr1.first == pr2.first)
            return pr1.second < pr2.second;

        return pr1.first > pr2.first;
    }
};


void solve()
{
    int n, inp;
    vector<pair<int, int>> arr(61, {0,0});

    // vector<pair<int, int>> v = {{1, 2}, {6, 4}, {3, 4}, {4, 1}};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        // cout << inp << endl;
        arr[inp].first++;
        arr[inp].second = inp;
    }

    // sort(v.begin(), v.end(), compr());
    sort(arr.begin(), arr.end(), compr());

    for(auto it:arr) {
        while(it.first--) {
            cout << it.second << ' ';
        }
    }
  

    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
