/*

https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/

INPUT:
5
1 2 3 4 5

OUTPUT:
5 1 2 3 4 

*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

void rotate(int arr[], int n)
{
    int tmp = -1, pre = -1;

    if (n == 1)
        return;

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            pre = arr[0];
            continue;
        }

        tmp = arr[i];
        arr[i] = pre;
        pre = tmp;
    }
    arr[0] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    rotate(arr, n);

    for (auto it : arr)
        cout << it << ' ';
}
