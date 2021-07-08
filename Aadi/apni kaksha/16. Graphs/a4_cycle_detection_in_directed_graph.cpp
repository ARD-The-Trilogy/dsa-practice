#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
    https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
    https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
*/

// v => curr_node
bool is_cycle_present(vvi &adj_ls, vi &visited, vi &st, int v){
  visited[v] = 1;
  bool cycle = false;

  st[v] = 1;
  for(auto it = adj_ls[v].begin(); it != adj_ls[v].end(); it++){
      cout<<v<<" -> "<<*it<<endl;
    if(!visited[*it]){
      st[*it] = 1;
      cycle = is_cycle_present(adj_ls, visited, st, *it);
    }
    else if(st[*it]){
      cycle = true;
    }
  }
  st[v] = 0;
  return cycle;
}


void make_directed_graph(vvi &edge_mat, vvi &adj_ls, int n, int m){
  for(int i=0; i<m; i++){
    int x = edge_mat[i][0];
    int y = edge_mat[i][1];
    adj_ls[x].push_back(y);
  }

  // cout<<"Adjacency List : "<<endl;
  // for(int i=1; i <= n; i++){
  //   cout<<i<<" => ";
  //   for(int j=0; j < adj_ls[i].size(); j++){
  //     cout<<adj_ls[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
}


int main(){

  int n = 8, m = 8;
  vvi edge_mat = {{1,2}, {1,3}, {2,4}, {3,4}, {6,5}, {5,7}, {7,8}, {8,6}};
    
  // int n = 8, m = 9;
  // vvi edge_mat = {{1,2}, {1,3}, {2,4}, {3,4}, {3,6}, {6,5}, {5,7}, {7,8}, {8,6}};
    
/*

    ↗  ↖    ↘  ↙   ↑ ↓   → ←  
    ↕  ←→   /   \   ↼⇁   ↽⇀

                 1              5
              ↙    ↘        ↗     ↘
            2        3 --> 6        7
             ↘     ↙        ↖     ↙ 
                4               8

*/

  vvi adj_ls(n+1, vi(0, n+1));
  vi visited(n+1, 0);
  vi st(n+1, 0);

  make_directed_graph(edge_mat, adj_ls, n, m);

  for(int i=1; i <= n; i++){
    if(!visited[i]){
      if(is_cycle_present(adj_ls, visited, st, i)){
        cout<<"Cycle present"<<endl;
      }
      else{
        cout<<"Cycle not present"<<endl;
      }
    }
  }

  return 0;
}