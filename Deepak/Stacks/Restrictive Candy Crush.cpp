// LINK: https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1/?track=md-stack&batchId=144#

// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string Reduced_String(int k, string s)
    {
        // Your code goes here
        stack<pair<char, int>> stk;

        for (int i = 0; i < s.length(); i++)
        {

            if (stk.empty() ||  s[i] != stk.top().first)
            {
                stk.push({s[i], 1});
            }
            else
            {
                int val = stk.top().second;
                stk.push({s[i], val + 1});
            }

            if (stk.top().second == k)
            {
                int identical = k;

                while (identical--)
                {
                    stk.pop();
                }
            }
        }

        string ans = "";
        while(!stk.empty()) {
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
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
        int k;
        cin >> k;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.Reduced_String(k, s) << "\n";
    }

    return 0;
} // } Driver Code Ends