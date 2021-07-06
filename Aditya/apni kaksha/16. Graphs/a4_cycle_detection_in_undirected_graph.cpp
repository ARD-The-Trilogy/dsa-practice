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
bool is_cycle_present(vvi &adj_ls, vi &visited, int v, int parent){
  visited[v] = 1;
  bool cycle = false;
  for(auto it= adj_ls[v].begin(); it != adj_ls[v].end(); it++){
    cout<<v<<" -> "<<*it<<endl;
    if(!visited[*it]){
      cycle = is_cycle_present(adj_ls, visited, *it, v);
    }
    else if(*it != parent){
      cycle = true;
    }
  }
  return cycle;
}


void make_undirected_graph(vvi &edge_mat, vvi &adj_ls, int n, int m){
  for(int i=0; i<m; i++){
    int x = edge_mat[i][0];
    int y = edge_mat[i][1];
    adj_ls[x].push_back(y);
    adj_ls[y].push_back(x);
  }

//   cout<<"Adjacency List : "<<endl;
//   for(int i=1; i <= n; i++){
//     cout<<i<<" => ";
//     for(int j=0; j < adj_ls[i].size(); j++){
//       cout<<adj_ls[i][j]<<' ';
//     }
//     cout<<endl;
//   }
}


int main(){

  int n = 8, m = 7;
  vvi edge_mat = {{1,2}, {1,3}, {2,4}, {6,5}, {6,8}, {5,7}, {7,8}};
    
  // int n = 8, m = 8;
  // vvi edge_mat = {{1,2}, {1,3}, {2,4}, {3,6}, {6,5}, {6,8}, {5,7}, {7,8}};
    
  // int n = 8, m = 9;
  // vvi edge_mat = {{1,2}, {1,3}, {2,4}, {3,4}, {3,6}, {6,5}, {6,8}, {5,7}, {7,8}};
    
/*

    ↗   ↘   ↙   ↖   ↑   ↓   →   ←  
    ↕  ←→   /   \  ↼⇁  ↽⇀

                 1           5
               /   \       /   \
              2     3 --- 6     7
               \   /       \   / 
                 4           8

*/

  vvi adj_ls(n+1, vi(0, n+1));
  vi visited(n+1, 0);

  make_undirected_graph(edge_mat, adj_ls, n, m);

  for(int i=1; i <= n; i++){
    if(!visited[i]){
      if(is_cycle_present(adj_ls, visited, i, -1)){
        cout<<"Cycle present"<<endl;
      }
      else{
        cout<<"Cycle not present"<<endl;
      }
    }
  }

  return 0;
}