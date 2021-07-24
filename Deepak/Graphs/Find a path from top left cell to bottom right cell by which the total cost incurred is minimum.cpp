// LINK: https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Box
{
    int ri, ci, dist;
    Box(int r, int c, int d) : ri(r), ci(c), dist(d) {}
};

struct comprUtil
{
    bool operator()(const Box &box1, const Box &box2)
    {
        return box1.dist > box2.dist;
    }
};

class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int N, M;
    vector<vector<bool>> vis;

    bool isVal(vector<vector<int>> &grid, int ri, int ci)
    {
        if (ri < 0 || ci < 0 || ri > N-1 || ci > M-1) 
        return false;

        if(vis[ri][ci]) return false;
        
        return true;
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        N = grid.size(), M = grid[0].size();
        vis.assign(N, vector<bool>(M, 0));

        priority_queue<Box, vector<Box>, comprUtil> pq;
        pq.push({0, 0, grid[0][0]});

        while (!pq.empty())
        {
            Box tmp = pq.top();
            pq.pop();

            int ri = tmp.ri, ci = tmp.ci, dist = tmp.dist;

            while(vis[pq.top().ri][pq.top().ci]) {
                pq.pop();
            }
            
            vis[ri][ci] = true;
            
            // cout << tmp.ri << ' ' << tmp.ci << ' ' << tmp.dist << endl;
            if(ri == N-1 && ci == M-1) return dist;

            if(isVal(grid, ri+1, ci)) {
                pq.push({ri+1, ci, dist + grid[ri+1][ci]});   
            }
            if(isVal(grid, ri-1, ci)) {
                pq.push({ri-1, ci, dist + grid[ri-1][ci]});
            }
            if(isVal(grid, ri, ci-1)) {
                pq.push({ri, ci-1, dist + grid[ri][ci-1]});
            }
            if(isVal(grid, ri, ci+1)) {
                pq.push({ri, ci+1, dist + grid[ri][ci+1]});
            }
        }

        return 0;
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
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends