// LINK: https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<bool>> vis;
    int N, M;

    bool isValid(vector<vector<int>> &grid, int r, int c)
    {
        // within boundaries, should be a 3 or 2, should not be visited.
        if (r < 0 || c < 0 || r > N - 1 || c > M - 1)
            return false;
        if (vis[r][c] || (grid[r][c] == 0 || grid[r][c] == 1))
            return false;

        return true;
    }

    bool pathUtil(vector<vector<int>> grid, int src_r, int src_c)
    {
        // bfs
        queue<pair<int, int>> qu;
        qu.push({src_r, src_c});

        // for(int i=0;i<N;i++) {
        //     for(int j=0;j<M;j++) cout << grid[i][j] << ' ';
        //     cout << endl;
        // }

        while (!qu.empty())
        {
            pair<int, int> pr = qu.front();
            qu.pop();
            int ri = pr.first, ci = pr.second;
            // cout << ri << ' ' << ci << endl;
            // mark visited

            if (grid[ri][ci] == 2)
            {
                return true;
            }

            // all combinations check if valid
            if (isValid(grid, ri - 1, ci))
            {
                // push to the queue
                vis[ri - 1][ci] = true;
                qu.push({ri - 1, ci});
            }
            if (isValid(grid, ri + 1, ci))
            {
                vis[ri + 1][ci] = true;
                qu.push({ri + 1, ci});
            }
            if (isValid(grid, ri, ci - 1))
            {
                vis[ri][ci - 1] = true;
                ;
                qu.push({ri, ci - 1});
            }
            if (isValid(grid, ri, ci + 1))
            {
                vis[ri][ci + 1] = true;
                qu.push({ri, ci + 1});
            }
        }

        return false;
    }

    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        //code here
        N = grid.size(), M = grid[0].size();
        vis.assign(N, vector<bool>(M, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 1)
                {
                    // cout << i << ' ' << j << endl;
                    vis[i][j] = true;
                    return pathUtil(grid, i, j);
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
} // } Driver Code Ends