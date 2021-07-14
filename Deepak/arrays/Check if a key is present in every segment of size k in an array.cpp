/* 
https://www.geeksforgeeks.org/check-if-a-key-is-present-in-every-segment-of-size-k-in-an-array/

INPUT:
15 4 4
4 5 5 1 4 3 8 1 10 4 9 6 1 3 1

OUTPUT:
0
*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, key, seg_size;
    cin >> n >> key >> seg_size;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << key << ' ' << seg_size << ' ' << n << endl;

    int rem = seg_size;
    bool f1 = false;
    for (int i = 0; i < n; i++)
    {
        if (rem == 0 && !f1)
            break;

        if (rem == 0 && f1)
        {
            rem = seg_size;
            f1 = false;
        }

        if (arr[i] == key)
            f1 = true;
        rem--;
    }

    cout << f1 << endl;
}
