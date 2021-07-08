/* 
https://www.geeksforgeeks.org/find-the-missing-number/

INPUT:
8
1 2 4 6 3 7 8

OUTPUT:
5

*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void method1(int arr[], int n)
{
    int sum1 = n * (n + 1) / 2;
    int sum2 = accumulate(arr, arr + n - 1, 0);
    // cout << sum2 << endl;
    cout << sum1 - sum2 << endl;
}

// This will prevent the overflow of integers.
int method2(vector<int> arr, int n)
{
    int missing_num = 0;
    for (int i = 0; i < n - 1; i++)
    {
        missing_num += (i + 1 - arr[i]);
    }
    return missing_num += n;
}

int method3(vector<int> arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = (ans ^ arr[i] ^ (i + 1));
    }
    return (ans ^ n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, inp;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> inp;
        arr.push_back(inp);
    }

    cout << method3(arr, n);
}
