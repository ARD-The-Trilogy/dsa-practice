// link: https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1#

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        // code here
        int children[n + 1], dia[n + 1], vis[n + 1];
        bool in_edge[n + 1];
        for (int i = 0; i <= n; i++)
        {
            in_edge[i] = 0;
            vis[i] = false;
            children[i] = -1;
        }

        for (int i = 0; i < a.size(); i++)
        {
            int idx = a[i], child = b[i], val = d[i];
            children[idx] = child;
            dia[idx] = val;
            in_edge[child] = true;
        }


        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++)
        {
            vector<int> tri(3);
            int mini = INT_MAX;
            if (in_edge[i] == 0 && children[i] != -1)
            {
                tri[0] = i;
                int j = i;
                while (children[j] != -1)
                {
                    if (children[j] != -1)
                    {
                        mini = min(mini, dia[j]);
                    }
                    j = children[j];
                }
                tri[1] = j;
                tri[2] = mini;

                ans.push_back(tri);
            }
        }

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

    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
} // } Driver Code Ends