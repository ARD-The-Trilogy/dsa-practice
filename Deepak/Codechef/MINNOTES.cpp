#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void calc_gcd(int arr[], int prefix_gcd[], int suffix_gcd[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefix_gcd[i] = arr[i];
            continue;
        }
        prefix_gcd[i] = __gcd(prefix_gcd[i - 1], arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            suffix_gcd[i] = arr[i];
            continue;
        }
        suffix_gcd[i] = __gcd(suffix_gcd[i + 1], arr[i]);
    }
}

void updateSal(int arr[], int n, int denom)
{

    for (int i = 0; i < n; i++)
    {
        if (__gcd(arr[i], denom) != denom)
        {
            arr[i] = denom;
            return;
        }
    }

    int maxi = *max_element(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maxi)
        {
            arr[i] = denom;
            return;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int prefix_gcd[n], suffix_gcd[n];
    calc_gcd(arr, prefix_gcd, suffix_gcd, n);

    priority_queue<int, vector<int>, greater<int>> pq;

    int gcd = -1, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (n == 1)
            gcd = arr[i];
        else if (i == 0 && n > 1)
            gcd = suffix_gcd[i + 1];
        else if (i == n - 1 && n > 1)
            gcd = prefix_gcd[i - 1];
        else
            gcd = __gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);

        if (pq.size() < 2)
            pq.push(gcd);
        else if (pq.top() < gcd)
        {
            pq.pop();
            pq.push(gcd);
        }
    }

    int curr = -1e9;
    idx = -1;
    while (!pq.empty())
    {
        curr = max(curr, pq.top());
        pq.pop();
    }

    updateSal(arr, n, curr);

    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += arr[i] / curr;
    }

    cout << tot << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

