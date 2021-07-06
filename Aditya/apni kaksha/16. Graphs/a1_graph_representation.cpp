#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(i=a; i<b; i++)

/*
  https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
  
*/


int main(){

  // int n = 7, m = 7;         // n = no. of nodes, m = no. of edges
  // int edge_matrix[][2] = {{1,2}, {1,3}, {2, 4}, {2, 5}, {2, 6}, {5, 7}, {4, 6}};
  
  int n = 8, m = 9;
  int edge_matrix[][2] = {{1,2}, {1,3}, {2,4}, {3,4}, {3,6}, {6,5}, {6,8}, {5,7}, {7,8}};
    

  /*

    ↗   ↘   ↙   ↖   ↑   ↓   →   ←  
    ↕  ←→   /   \  ↼⇁  ↽⇀

                 1           5
               /   \       /   \
              2     3 --- 6     7
               \   /       \   / 
                 4           8

*/

  // Adjacency Matrix

  int adj_mat[n+1][n+1] = {};

  for(int i=0; i < m; i++){
    int x = edge_matrix[i][0];
    int y = edge_matrix[i][1];
    adj_mat[x][y] = 1; 
    adj_mat[y][x] = 1; 
  }

  cout<<"Adjacency Matrix : "<<endl;
  for(int i=1; i <= n; i++){
    cout<<i<<" => ";
    for(int j=1; j <= n; j++){
      cout<<adj_mat[i][j]<<' ';
    }
    cout<<endl;
  }


  // Adjacency List

  vvi adj_ls(n+1, vi(0, n+1));

  for(int i=0; i<m; i++){
    int x = edge_matrix[i][0];
    int y = edge_matrix[i][1];
    adj_ls[x].push_back(y);
    adj_ls[y].push_back(x);
  }

  cout<<"\nAdjacency List : "<<endl;
  for(int i=1; i <= n; i++){
    cout<<i<<" => ";
    for(int j=0; j < adj_ls[i].size(); j++){
      cout<<adj_ls[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}
