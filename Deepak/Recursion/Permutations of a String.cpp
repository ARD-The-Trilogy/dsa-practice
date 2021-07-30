/*
LINK: https://practice.geeksforgeeks.org/problems/permutations-of-a-string/1/?track=md-backtracking&batchId=144#

LINK: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

*/


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<string> ans;
    void permutateUtil(string S, int i)
    {
        if (i == 0)
        {
            ans.push_back(S);
            return;
        }

        for (int j = 0; j <= i; j++)
        {
            swap(S[j], S[i]);
            permutateUtil(S, i - 1);
            swap(S[j], S[i]);
        }
    }

    vector<string> permute(string s)
    {
        // code here
        permutateUtil(s, s.length() - 1);

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
        string s;
        cin >> s;
        Solution obj;
        vector<string> ans;
        ans = obj.permute(s);
        sort(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";

        cout << endl;
    }
    return 0;
} // } Driver Code Ends