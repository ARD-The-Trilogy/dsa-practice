/* 

https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

INPUT
5 5
1 0
0 2
2 1
0 3
3 4

OUTPUT
0 3 


*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

vector<bool> visited;
vector<int> in_time, low_time;
set<int> art_points;
int t_stamp;

void dfs(vector<int> graph[], int node, int par)
{
    visited[node] = true;
    low_time[node] = in_time[node] = ++t_stamp;

    int child = 0;
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            child++;
            dfs(graph, it, node);
            low_time[node] = min(low_time[node], low_time[it]);

            if (child > 1 && par == node)
            {
                art_points.insert(par);
            }

            if (in_time[node] <= low_time[it])
                art_points.insert(node);
        }
        else if (it != par)
        {
            low_time[node] = min(in_time[it], low_time[node]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, fi, se;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> fi >> se;
        graph[fi].push_back(se);
        graph[se].push_back(fi);
    }

    visited.assign(n + 1, 0);
    in_time.assign(n + 1, 0);
    low_time.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            in_time[i] = 1, low_time[i] = 1;
            dfs(graph, i, i);
        }
    }

    for (auto it : art_points)
    {
        cout << it << ',';
    }
    cout << endl;
}