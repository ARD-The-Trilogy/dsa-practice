
/*

https://www.geeksforgeeks.org/bridge-in-a-graph/

INPUT:
5 5
1 0
0 2
2 1
0 3
3 4

OUTPUT
0-3
3-4


*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

set<pair<int, int>> bridges;
vector<bool> visited;
vector<int> in_time, low_time;
int t_stamp;

void init(int n)
{
    visited.assign(n + 1, 0);
    in_time.assign(n + 1, 0);
    low_time.assign(n + 1, 0);
}

void findBridges(vector<int> graph[], int node, int par)
{
    visited[node] = true;
    in_time[node] = low_time[node] = ++t_stamp;

    for (int v : graph[node])
    {
        if (!visited[v])
        {
            findBridges(graph, v, node);
            low_time[node] = min(low_time[node], low_time[v]);

            if (in_time[node] < low_time[v])
            {
                bridges.insert({node, v});
            }
        }
        else if (v != par)
        {
            low_time[node] = min(in_time[v], low_time[node]);
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

    int n, m, u, v;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    init(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            findBridges(graph, i, i);
        }
    }

    for (auto it : bridges)
    {
        cout << it.first << '-' << it.second << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "->" << in_time[i] << ' ' << low_time[i] << endl;
    // }
}
