// link: https://practice.geeksforgeeks.org/problems/power-set4302/1#

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> vt;
    string str;
    int n;

    void stringUtil(string s, int i)
    {
        if (i == str.length())
        {
            if (s != "")
                vt.push_back(s);

            return;
        }

        stringUtil(s + str[i], i + 1);
        stringUtil(s, i + 1);
    }

    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        str = s;
        stringUtil("", 0);
        sort(vt.begin(), vt.end());

        return vt;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends