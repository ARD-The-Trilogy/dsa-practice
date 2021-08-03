// LINK: https://practice.geeksforgeeks.org/problems/final-destination4628/1/?track=md-graph&batchId=144#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int canReach(long long a, long long b, long long x)
    {
        // code here
        int steps = abs(a) + abs(b);

        if (x < steps)
            return false;
        else if ((x - steps) % 2 == 0)
            return true;

        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x;

        cin >> a >> b >> x;

        Solution ob;
        cout << ob.canReach(a, b, x) << endl;
    }
    return 0;
} // } Driver Code Ends