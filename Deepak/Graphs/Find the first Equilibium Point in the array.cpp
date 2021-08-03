// LINK: https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?track=md-arrays&batchId=144#

// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // Your code here
        if (n == 1)
            return 1;

        long long pre_sum = 0, sum = 0;

        for (int i = 0; i < n; i++)
            sum += a[i];

        for (int i = 0; i < n; i++)
        {
            sum -= a[i];

            if (pre_sum == sum)
                return i + 1;
            pre_sum += a[i];
        }

        return -1;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long t;

    //taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends