#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
    
*/

void make_undirected_graph(vvi &edge_mat, vvi &adj_ls, int n, int m){
  for(int i=0; i<m; i++){
    int x = edge_mat[i][0];
    int y = edge_mat[i][1];
    adj_ls[x].push_back(y);
    adj_ls[y].push_back(x);
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

void BFS(vvi &adj_ls, int visited[], int root_node){
  queue<int> q;
  q.push(root_node);
  visited[root_node] = 1;

  cout<<"\nBFS: ";
  while(!q.empty()){
    int curr_node = q.front();
    q.pop();
    cout<<curr_node<<' ';

    for(auto it= adj_ls[curr_node].begin(); it != adj_ls[curr_node].end(); it++){
      if(!visited[*it]){
        q.push(*it);
        visited[*it] = 1;
      }
    }
  }
}

void DFS(vvi &adj_ls, int visited[] , int root_node){  
  // preorder
  visited[root_node] = 1;
  cout<<root_node<<' ';

  // inorder
  for(auto it= adj_ls[root_node].begin(); it != adj_ls[root_node].end(); it++){
    if(!visited[*it]){
      DFS(adj_ls, visited, *it);
    }
  }

  // postorder
  // cout<<root_node<<' ';

}

int main(){

  // int n = 7, m = 7;
  // vvi edge_mat = {{1,2}, {1,3}, {2, 4}, {2, 5}, {2, 6}, {5, 7}, {4, 6}};
  int n = 8, m = 9;
  vvi edge_mat = {{1,2}, {1,3}, {2,4}, {3,4}, {3,6}, {6,5}, {6,8}, {5,7}, {7,8}};
    
    
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
  int visited[n+1] = {};

  make_undirected_graph(edge_mat, adj_ls, n, m);

  BFS(adj_ls, visited, 1);

  cout<<"\nDFS: ";
  int visited_dfs[n+1] = {};
  DFS(adj_ls, visited_dfs, 1);


  return 0;
}