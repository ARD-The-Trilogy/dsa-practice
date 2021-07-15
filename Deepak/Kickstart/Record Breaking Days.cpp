/*
LINK:
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

INPUT:
4
8
1 2 0 7 2 0 2 0
6
4 8 15 16 23 42
9
3 1 4 1 5 9 2 6 5
6
9 9 9 9 9 9

OUTPUT:
Case #1: 2
Case #2: 1
Case #3: 3
Case #4: 0

*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool f1 = false, f2 = false;
    int maxi = -1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        f1 = false, f2 = false;
        if (arr[i] > maxi)
        {
            f1 = true;
        }
        maxi = max(maxi, arr[i]);

        if (i == n - 1 || arr[i] > arr[i + 1])
            f2 = true;

        if (f1 && f2)
            cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
