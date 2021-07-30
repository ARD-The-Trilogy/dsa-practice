/*
LINK: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/?track=md-backtracking&batchId=144#
LINK: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int N;
    vector<string> ans;

    bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r, int c)
    {
        if (r < 0 || c < 0 || r > N - 1 || c > N - 1)
            return false;

        if (grid[r][c] == 0 || vis[r][c])
            return false;

        return true;
    }

    void pathUtil(vector<vector<int>> &grid, vector<vector<bool>> vis, int r, int c, string str)
    {
        if (!isValid(grid, vis, r, c))
            return;

        if (r == N - 1 && c == N - 1)
        {
            ans.push_back(str);
            return;
        }

        vis[r][c] = true;

        pathUtil(grid, vis, r + 1, c, str + "D");
        pathUtil(grid, vis, r - 1, c, str + "U");
        pathUtil(grid, vis, r, c - 1, str + "L");
        pathUtil(grid, vis, r, c + 1, str + "R");
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        N = n;
        vector<vector<bool>> vis(N, vector<bool>(N, 0));

        pathUtil(m, vis, 0, 0, "");
        sort(ans.begin(), ans.end());

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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends