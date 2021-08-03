// LINK: https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find unit area of the largest region of 1s.
    int N, M;
    vector<vector<bool>> vis;

    bool isValid(vector<vector<int>> &grid, int ri, int ci)
    {
        if (ri < 0 || ci < 0 || ri > N - 1 || ci > M - 1)
            return false;

        if (grid[ri][ci] == 0 || vis[ri][ci])
            return false;

        return true;
    }

    int areaUtil(vector<vector<int>> &grid, int ri, int ci)
    {
        int tot = 0;
        queue<pair<int, int>> qu;
        qu.push({ri, ci});
        vis[ri][ci] = true;

        while (!qu.empty())
        {
            int ri = qu.front().first, ci = qu.front().second;
            qu.pop();
            tot++;

            for (int x = ri - 1; x <= ri + 1; x++)
            {
                for (int y = ci - 1; y <= ci + 1; y++)
                {
                    if (isValid(grid, x, y))
                    {
                        vis[x][y] = true;
                        qu.push({x, y});
                    }
                }
            }
        }

        return tot;
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        N = grid.size(), M = grid[0].size();
        vis.assign(N, vector<bool>(M, 0));

        int maxi = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    maxi = max(maxi, areaUtil(grid, i, j));
                }
            }
        }

        return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends