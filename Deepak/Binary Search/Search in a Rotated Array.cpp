// link: https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

// link: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int bsearch(int *arr, int l, int h, int key)
    {
        if (l > h)
            return -1;

        int mid = (l + h) / 2;

        // cout << l << ' ' << h << endl;

        if (key == arr[mid])
            return mid;

        if (key < arr[mid])
            return bsearch(arr, l, mid - 1, key);
        if (key > arr[mid])
            return bsearch(arr, mid + 1, h, key);
    }

    int findIdx(int *arr, int l, int h)
    {
        if (l > h)
            return -1;

        int mid = (l + h) / 2;

        // cout << mid << endl;
        
        if (l == h)
            return l;

        if (mid > l && mid < h && arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1])
        {
            return mid;
        }

        if (arr[mid] < arr[h])
        {
            return findIdx(arr, l, mid);
        }
        else if (arr[mid] > arr[h])
        {
            return findIdx(arr, mid + 1, h);
        }
    }

    int search(int A[], int l, int h, int key)
    {
        //complete the function here

        int idx = findIdx(A, 0, h);

        // cout << idx << endl;

        int f1 = bsearch(A, idx, h, key);
        // cout << f1 << endl;

        if (f1 == -1)
            f1 = bsearch(A, 0, idx-1, key);

        return f1;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
} // } Driver Code Ends