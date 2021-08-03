// LINK: https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
// LINK: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        int *lbound = lower_bound(arr, arr + n, x);
        int *upbound = upper_bound(arr, arr + n, x);

        return upbound - lbound;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends