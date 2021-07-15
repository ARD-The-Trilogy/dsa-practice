#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

vector<bool> visited;
vector<pair<int, int>> nodes;
int tstamp;

void dfs(vector<int> graph[], int val)
{
    visited[val] = true;
    nodes[val].first = ++tstamp;

    for (auto v : graph[val])
    {
        if (!visited[v])
        {
            dfs(graph, v);
        }
    }
    nodes[val].second = ++tstamp;
}

bool subGraph(vector<pair<int, int>> adj_nodes)
{
    // for (auto it : adj_nodes)
    // {
    //     cout << it.first << ' ' << it.second << endl;
    // }
    // cout << endl;

    vector<int> nums;
    bool f1 = true;
    int size = adj_nodes.size(), count = 0;
    // cout << "si: " << size << endl;
    for (int i = 0; i < size;)
    {
        int end_time = adj_nodes[i++].second;
        count = 0;
        // count++;
        // k = 0;
        while (i < size && adj_nodes[i].first < end_time)
        {
            // cout << adj_nodes[i - 1].second << '-' << adj_nodes[i].second << endl;
            if (adj_nodes[i - 1].second < adj_nodes[i].second)
            {
                f1 = false;
                count++;
            }
            i++;
        }
        nums.push_back(count);
    }

    // Rules:
    bool f3 = true, f4 = true;
    for (auto it : nums)
    {
        if (it > 1)
            f4 = false;
        if (it > 0)
            f3 = false;
        // cout << it << ' ';
    }
    // cout << endl;

    if (nums.size() == 1 && f4)
        return true;
    else if (nums.size() == 2 && f3)
        return true;

    return false;
}

void solve()
{
    int n, v, u, q, k, inp;
    cin >> n;
    vector<int> graph[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.assign(n + 1, 0);
    nodes.assign(n + 1, {0, 0});
    dfs(graph, 1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << '-' << nodes[i].first << ' ' << nodes[i].second << endl;
    // }
    // cout << endl;

    cin >> q;
    while (q--)
    {
        vector<pair<int, int>> samp_nodes;
        cin >> k;

        for (int i = 0; i < k; i++)
        {
            cin >> inp;
            samp_nodes.push_back(nodes[inp]);
        }
        sort(samp_nodes.begin(), samp_nodes.end());
        bool ans = subGraph(samp_nodes);
        // cout << endl;
        if (ans == 0)
            cout << "No\n";
        else
            cout << "Yes\n";

        // cout << endl;
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
