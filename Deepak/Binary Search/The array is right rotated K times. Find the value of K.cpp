// LINK: https://practice.geeksforgeeks.org/problems/rotation4723/1#

// LINK: https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int bsearch(int *arr, int l, int h, int n)
    {
        if (l > h)
            return -1;
        // we have to find the point
        // when the mid is greater than the next
        // element

        int mid = (l + h) / 2;

        // cout << mid << endl;

        if (arr[l] == arr[h])
            return l;
        if (mid != n - 1 && arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }
        else if (arr[mid] < arr[h])
        {
            return bsearch(arr, l, mid, n);
        }
        else if (arr[mid] > arr[h])
        {
            return bsearch(arr, mid + 1, h, n);
        }
    }

    int findKRotation(int arr[], int n)
    {
        // code here

        int idx1 = 0;
        int idx2 = bsearch(arr, 0, n - 1, n);

        // cout << idx1 << ' ' << idx2 << endl;

        int ans = idx2 - idx1;
        return ans;
        // return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends