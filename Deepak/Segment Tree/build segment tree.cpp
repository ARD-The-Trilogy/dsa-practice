#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int node_val;
int *memo;

int rec(int *arr, int node_val, int l, int r)
{
    if (l > r)
        return INT_MAX;

    if (l == r)
    {
        return memo[node_val] = arr[r];
    }
    int mid = (l + r) / 2;

    // int sum = 0;
    // for (int i = l; i <= r; i++)
    //     sum += arr[i];
    int mini = 1e9;

    int ans1 = rec(arr, 2 * node_val + 1, l, mid);
    int ans2 = rec(arr, 2 * node_val + 2, mid + 1, r);

    // cout << l << '-' << r << ' ' << ans1 << '-' << ans2 << endl;

    return memo[node_val] = min(ans1, ans2);
}

void buildSegTree(int *arr, int n)
{
    rec(arr, 0, 0, n - 1);
}

bool isValid(int l, int h, int le, int ri)
{
    if (h < le)
        return false;
    if (ri < l)
        return false;

    return true;
}

bool overlaps(int l, int h, int le, int ri)
{
    if (le <= l && ri >= h)
        return true;
    return false;
}

int query(int *arr, int node_val, int l, int h, int le, int ri)
{
    if (!isValid(l, h, le, ri))
        return 1e9;
    // return 0;
    if (overlaps(l, h, le, ri))
    {
        // return the value of its node num
        return memo[node_val];
    }

    int mid = (l + h) / 2;
    int ans1 = query(arr, 2 * node_val + 1, l, mid, le, ri);
    int ans2 = query(arr, 2 * node_val + 2, mid + 1, h, le, ri);

    // cout << l << '-' << h << ' ' << ans1 << '-' << ans2 << endl;

    // return ans1 + ans2;
    return min(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q, l, r;
    cin >> n;
    int arr[n];
    memo = new int[2 * (n + 2)];
    memset(memo, 0, sizeof memo);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildSegTree(arr, n);
    for (int i = 0; i <= 2 * n; i++)
    {
        cout << i << '-';
        cout << memo[i] << endl;
    }
    cout << endl;

    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        int ans = query(arr, 0, 0, n - 1, l, r);
        cout << ans << endl;
    }
}
