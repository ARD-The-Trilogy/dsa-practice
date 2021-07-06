#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
  
*/

const int INF = 1e9;

void MST_using_prims(vvvi &g, vi &dist, vi &parent, vi &visited, int n, int src){
  int cost = 0;
  set<vector<int>> s;

  for(int i=1; i <= n; i++){
    dist[i] = INF;
  }

  dist[src] = 0;
  s.insert({0, src});       //{weight, src}
  while(!s.empty()){
    auto x = *s.begin();
    s.erase(x);
    int u = x[1];
    int v = parent[u];
    int w = x[0];
    cout<<u<<' '<<v<<' '<<w<<endl;
    visited[u] = 1;
    cost += w;
    for(auto it : g[u]){
      if(visited[it[0]]){
        continue;
      }
      if(dist[it[0]] > it[1]){
        s.erase({dist[it[0]], it[0]});
        dist[it[0]] = it[1];
        s.insert({dist[it[0]], it[0]});
        parent[it[0]] = u;
      }
    }
  }
  cout<<"Cost: "<<cost;
}

void make_graph(vvi edges, vvvi &g, int n, int m){
  for(int i=0; i<m; i++){
    int u = edges[i][1];
    int v = edges[i][2];
    int w = edges[i][0];
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  cout<<"u =>  v w , ....."<<endl;
  for(int i=1; i<=n; i++){
    cout<<i<<" =>  ";
    for(auto it : g[i]){
      cout<<it[0]<<' '<<it[1]<<"  ";
    }
    cout<<endl;
  }
}

int main(){

  int n = 8, m = 9;
  vvi edges = {{1,1,2}, {2,2,4}, {3,4,3}, {4,3,1}, {5,3,6}, {1,6,5}, {2,5,7}, {3,7,8}, {4,8,6}};
    
/*

    ↗   ↘   ↙   ↖   ↑   ↓   →   ←  
    ↕  ←→   /   \  ↼⇁  ↽⇀

                 1           5
              1/   \4  5  1/   \2
              2     3 --- 6     7
              2\   /3     4\   /3 
                 4           8

*/

  vvvi adj_ls(n+1);
  vi dist(n+1);
  vi parent(n+1);
  vi visited(n+1);

  make_graph(edges, adj_ls, n, m);

  MST_using_prims(adj_ls, dist, parent, visited, n, 1);


  return 0;
}
