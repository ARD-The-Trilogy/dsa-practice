// link: https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1/?track=md-greedy&batchId=144

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findLargest(int N, int S)
    {
        // code here
        if (S == 0 && N > 1)
            return "-1";

        int nines = S / 9;
        int rest = S % 9;

        string ans = "";
        for (int i = 0; i < nines; i++)
        {
            ans += '9';
        }

        // cout << nines << ' ' << rest << endl;

        if (rest)
        {
            ans += char(rest + '0');
        }

        int rem = N - ans.length();
        if (rem < 0)
            return "-1";

        for (int i = 0; i < rem; i++)
            ans += '0';

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends