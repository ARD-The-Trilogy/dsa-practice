// LINK: https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    vector<string> brackets;
    void paranthesisUtil(string str, int open, int closed, int &n)
    {
        if (open == closed && open == n)
        {
            brackets.push_back(str);
            return;
        }

        // cout << str << endl;
        // cout << open << ' ' << closed;

        if (open < n)
            paranthesisUtil(str + "(", open + 1, closed, n);

        if (closed < open)
        {
            paranthesisUtil(str + ")", open, closed + 1, n);
        }
    }

    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        paranthesisUtil("", 0, 0, n);

        return brackets;
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
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends