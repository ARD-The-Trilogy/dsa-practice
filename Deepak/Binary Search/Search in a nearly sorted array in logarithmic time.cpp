// link: https://www.techiedelight.com/search-nearly-sorted-array-ologn-time/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int search(int *arr, int l, int h, int key)
{
    // base condition
    if (l > h)
        return -1;

    int mid = (l + h) / 2, ans;

    if (arr[mid] == key)
        return mid;
    else if (l == h)
        ans = l;
    else if (mid > l && arr[mid - 1] == key)
    {
        ans = mid - 1;
    }
    else if (mid < h && arr[mid + 1] == key)
        ans = mid + 1;

    else if (key < arr[mid])
        ans = search(arr, l, mid - 2, key);
    else if (key > arr[mid])
        ans = search(arr, mid + 2, h, key);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, key;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;

    // cout << key << endl;

    cout << search(arr, 0, n - 1, key);
}
