// LINK: https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class box
{
public:
    int ri, ci, dist;
    box(int r, int c, int lev)
    {
        ri = r, ci = c, dist = lev;
    }
};

class Solution
{
public:
    int n, m, tx, ty;
    vector<vector<bool>> vis;

    bool isValid(vector<vector<int>> &grid, int ri, int ci)
    {
        if (ri > n - 1 || ci > m - 1 || ri < 0 || ci < 0)
            return false;
        if (vis[ri][ci] || grid[ri][ci] == 0)
            return false;

        return true;
    }

    int distUtil(vector<vector<int>> &grid)
    {
        // starting from 0;
        queue<box> qu;
        qu.push({0, 0, 0});
        vis[0][0] = 1;

        while (!qu.empty())
        {
            box tmp = qu.front();
            qu.pop();

            int ri = tmp.ri, ci = tmp.ci, dist = tmp.dist;
            // cout << ri << ' ' << ci << ' ' << dist << endl;

            if (ri == tx && ci == ty)
                return dist;

            if (isValid(grid, ri + 1, ci))
            {
                vis[ri + 1][ci] = dist + 1;
                qu.push({ri + 1, ci, dist + 1});
            }
            if (isValid(grid, ri - 1, ci))
            {
                vis[ri - 1][ci] = dist + 1;
                qu.push({ri - 1, ci, dist + 1});
            }
            if (isValid(grid, ri, ci - 1))
            {
                vis[ri][ci - 1] = dist + 1;
                qu.push({ri, ci - 1, dist + 1});
            }
            if (isValid(grid, ri, ci + 1))
            {
                vis[ri][ci + 1] = dist + 1;
                qu.push({ri, ci + 1, dist + 1});
            }
        }

        return -1;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        n = N, m = M, tx = X, ty = Y;
        vis.assign(n, vector<bool>(m, 0));

        if (isValid(A, 0, 0) && isValid(A, tx, ty))
            return distUtil(A);
        else
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

    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
} // } Driver Code Ends