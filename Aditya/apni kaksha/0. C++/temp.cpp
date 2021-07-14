#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(i=a; i<b; i++)


int main(){

  
//   int n = 8, m = 9;
//   int edge_matrix[][2] = {{1,2}, {1,3}, {2,4}, {3,4}, {3,6}, {6,5}, {6,8}, {5,7}, {7,8}};
    
  int n;
	cin>>n;

  int adj_mat[n][n] = {};

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>adj_mat[i][j];
		}
	}

	vvi edges;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(adj_mat[i][j] == 1){
				edges.push_back({i, j});
			}
		}
	}

	for(int i=0; i<edges.size()/2+1; i++){
		cout<<edges[i][0]<<' '<<edges[i][1]<<endl;
	}

  return 0;
}
