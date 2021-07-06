#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
  
*/

const int INF = 1e9;

void Dijkstra(vvvi &g, vi &dist, int src){
  dist[src] = 0;
  set<vi> s;
  s.insert({src, 0});      // {src, weight}
  while(!s.empty()){
    auto x = *s.begin();
    s.erase(x);
    for(auto it : g[x[0]]){
      cout<<x[0]<<" -> "<<it[0]<<' '<<it[1]<<endl;
      if(dist[it[0]] > dist[x[0]] + it[1]){
        s.erase({it[0], dist[it[0]]});
        dist[it[0]] = dist[x[0]] + it[1];
        s.insert({it[0], dist[it[0]]});
      }
    }
  }
  cout<<"distance from src: "<<endl;
  for(int i=1; i<dist.size(); i++){
    if(dist[i] < INF){
      cout<<dist[i]<<' ';
    } else {
      cout<<"-1 "; 
    }
  }

}


void make_graph(vvi edges, vvvi &g, int n, int m){
  for(int i=0; i<m; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
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

  int n = 8, m = 9;   //{u,v,w}
  vvi edges = {{1,2,1}, {2,4,2}, {4,3,3}, {3,1,4}, {3,6,5}, {6,5,1}, {5,7,2}, {7,8,3}, {8,6,4}};
    
/*

    ↗   ↘   ↙   ↖   ↑   ↓   →   ←  
    ↕  ←→   /   \  ↼⇁  ↽⇀

                 1           5
              1/   \4  5  1/   \2
              2     3 --- 6     7
              2\   /3     4\   /3 
                 4           8

*/

  vvvi adj_ls(n+1);  //graph(g)
  vi dist(n+1, INF);

  make_graph(edges, adj_ls, n, m);

  Dijkstra(adj_ls, dist, 1);

  return 0;
}
