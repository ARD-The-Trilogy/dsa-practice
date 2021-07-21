// link https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// Complexity O(ElogE)
// Input:
// 9 14
// 0 1 4
// 1 2 8
// 1 7 11
// 0 7 8
// 7 6 8
// 7 8 7
// 2 8 2
// 8 6 6
// 2 5 4
// 6 5 2
// 2 3 7
// 3 4 9
// 3 5 14
// 4 5 10

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

class Node
{
public:
    int v, weight;
};

class compareNode
{
public:
    bool operator()(const Node &node1, const Node &node2)
    {
        return node2.weight < node1.weight;
    }
};

void printGraph(vector<Node> graph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (auto it : graph[i])
        {
            cout << it.v << '-' << it.weight << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void primsAlgo(vector<Node> graph[], vector<Node> &dist, int n)
{
    vector<int> visited(n + 1, 0);
    priority_queue<Node, vector<Node>, compareNode> pq;
    pq.push({0, 0});
    visited[0] = 0;

    while (!pq.empty())
    {
        Node tmp = pq.top();
        pq.pop();
        int node = tmp.v, wt = tmp.weight;
        // cout << tmp.v << '-' << tmp.weight << endl;
        if (!visited[node])
        {
            visited[node] = true;
            for (auto pr : graph[node])
            {
                int v = pr.v, w = pr.weight;
                if (!visited[v] && dist[v].weight > w)
                {
                    dist[v].weight = w, dist[v].v = node;
                    pq.push({v, w});
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, u, v, wt;
    cin >> n >> m;
    vector<Node> graph[n + 1], dist(n + 1, {-1, 1000000000});
    dist[0].weight = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    // printGraph(graph, n);

    primsAlgo(graph, dist, n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cout << i << ' ' << dist[i].v << '-' << dist[i].weight << endl;
        sum += dist[i].weight;
    }
    cout << sum << endl;
}
