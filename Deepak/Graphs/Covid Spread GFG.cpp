// LINK: https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1/?track=md-graph&batchId=144#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Box
{
public:
    int ri, ci, lev;
    Box(int r, int c, int le)
    {
        ri = r, ci = c, lev = le;
    }
};

class Solution
{
public:
    int N, M;
    vector<vector<bool>> vis;
    bool isValid(vector<vector<int>> &grid, int ri, int ci)
    {
        if (ri < 0 || ci < 0 || ri > N - 1 || ci > M - 1)
            return false;
        if (vis[ri][ci] || grid[ri][ci] == 0)
            return false;

        return true;
    }

    int funUtil(vector<vector<int>> &grid)
    {
        queue<Box> que;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        int maxi = 0;
        while (!que.empty())
        {
            Box node = que.front();
            que.pop();

            int ri = node.ri, ci = node.ci, dist = node.lev;
            maxi = max(maxi, dist);
            if (isValid(grid, ri + 1, ci))
            {
                vis[ri + 1][ci] = true;
                que.push({ri + 1, ci, dist + 1});
            }
            if (isValid(grid, ri - 1, ci))
            {
                vis[ri - 1][ci] = true;
                que.push({ri - 1, ci, dist + 1});
            }
            if (isValid(grid, ri, ci - 1))
            {
                vis[ri][ci - 1] = true;
                que.push({ri, ci - 1, dist + 1});
            }
            if (isValid(grid, ri, ci + 1))
            {
                vis[ri][ci + 1] = true;
                que.push({ri, ci + 1, dist + 1});
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;
            }
        }
        return maxi;
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        N = hospital.size(), M = hospital[0].size();
        vis.assign(N, vector<bool>(M, 0));

        return funUtil(hospital);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int>> hospital;
        int i, j;
        for (i = 0; i < R; i++)
        {
            vector<int> temp;
            for (j = 0; j < C; j++)
            {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends