#include<bits/stdc++.h>
using namespace std;

/*
  https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>

void dfs(vvc &grid, vvb &visited, int i, int j, int n, int m){
  if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0'){
      return;
  }
  if(grid[i][j] == '1' && !visited[i][j]){
      visited[i][j] = 1;
      dfs(grid, visited, i-1, j, n, m);
      dfs(grid, visited, i, j+1, n, m);
      dfs(grid, visited, i+1, j, n, m);
      dfs(grid, visited, i, j-1, n, m);
      dfs(grid, visited, i-1, j-1, n, m);
      dfs(grid, visited, i-1, j+1, n, m);
      dfs(grid, visited, i+1, j+1, n, m);
      dfs(grid, visited, i+1, j-1, n, m);
  }
}

int numIslands(vvc &grid) {
  int n = grid.size(), m = grid[0].size();
  vvb visited(n, vb(m, 0));
  int ans = 0;
  for(int i=0; i<grid.size(); i++){
      for(int j=0; j < grid[i].size(); j++){
          if(grid[i][j] == '1' && !visited[i][j]){
              dfs(grid, visited, i, j, n, m);
              ans++;
          }
      }
  }
  return ans;
}

int main(){
  int n, m;
  cout<<"Enter n m: ";
  cin >> n >> m;
  vector<vector<char>>grid(n, vector<char>(m, '#'));
  cout<<"Enter grid (0/1): "<<endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }
  
  cout<<"No. of Islands: "<<numIslands(grid);
	return 0;
}

/*
grid[5][5]
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1
*/