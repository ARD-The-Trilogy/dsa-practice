// LINK: https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<bool> vis;
    // stack<int> stk;
    bool dfsUtil(vector<int> graph[], int i, int par)
    {
        vis[i] = true;

        bool f1 = true;
        for (auto it : graph[i])
        {
            if (!vis[it])
                f1 &= dfsUtil(graph, it, i);
            if (it == par || i == it)
                return false;
        }

        // stk.push(i);
        return f1;
    }

    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> graph[N];
        int *indeg = new int[N], vis = N;
        fill_n(indeg, N, 0);
        int M = prerequisites.size();
        for (int i = 0; i < M; i++)
        {
            int fi = prerequisites[i].first, se = prerequisites[i].second;
            graph[fi].push_back(se);
            indeg[se]++;
        }

        // for(int i=0;i<N;i++) cout << indeg[i] << ' ';
        // cout << endl;

        // for(int i=0;i<N;i++) {
        //     cout << i << "->";
        //     for(auto kt: graph[i]) {
        //         cout << kt << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        queue<int> qu;
        for (int i = 0; i < N; i++)
        {
            if (indeg[i] == 0)
                qu.push(i);
        }

        while (!qu.empty())
        {
            int u = qu.front();
            qu.pop();
            // cout << u << "->" ;
            vis--;

            for (int v : graph[u])
            {
                // cout << v << ' ';
                indeg[v]--;
                if (indeg[v] == 0)
                    qu.push(v);
            }
        }

        return vis == 0;
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
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends