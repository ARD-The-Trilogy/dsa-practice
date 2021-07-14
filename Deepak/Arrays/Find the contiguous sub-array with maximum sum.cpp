/*
LINK:
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/


*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {

        // Your code here
        long long maxi = 0, max_so_far = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxi + arr[i] <= 0)
                maxi = 0;
            else
                maxi += arr[i];

            max_so_far = max(maxi, max_so_far);
        }

        if (max_so_far > 0)
            return max_so_far;

        max_so_far = *max_element(arr, arr + n);
        return max_so_far;
    }

    // Method 2
    int maxSubarraySum2(int arr[], int n)
    {

        // Your code here
        int prefix[n];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                prefix[i] = arr[i];
                continue;
            }
            prefix[i] = arr[i] + prefix[i - 1];
        }

        int i = 0, j = -1;
        int sum = -1e7 + 1, maxi = -1e7 + 1;
        while (i < n)
        {
            sum = prefix[i];
            if (j != -1)
                sum -= prefix[j];

            if (sum <= 0)
            {
                j = i;
            }
            maxi = max(maxi, sum);
            i++;
        }

        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends