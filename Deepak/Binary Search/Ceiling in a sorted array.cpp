// link: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int bsearch(int *arr, int l, int h, int key)
{
    if (l > h)
        return l;

    int mid = (l + h) / 2;

    if (l == h && arr[l] > key)
        return l;
    if (key < arr[mid])
        return bsearch(arr, l, mid, key);
    if (key >= arr[mid])
        return bsearch(arr, mid + 1, h, key);
}

int bsearchit(int *arr, int l, int h, int key)
{
    int res = -1;

    while (l <= h)
    {

        int mid = (l + h) / 2;

        if (l == h && arr[l] > key)
        {
            res = l; l++;
        }
        else if (key < arr[mid])
        {
            res = mid, h = mid;
        }
        else if (key >= arr[mid])
        {
            l = mid + 1;
        }
    }

    if (res != -1)
        res = arr[res];

    return res;
}

void solve()
{
    int n, key;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;

    int ans = bsearch(arr, 0, n - 1, key);
    // cout << ans << endl;
    ans = (ans == n) ? -1 : arr[ans];

    int ans2 = bsearchit(arr, 0, n-1, key);

    cout << ans << ' ' << ans2 << endl;
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
