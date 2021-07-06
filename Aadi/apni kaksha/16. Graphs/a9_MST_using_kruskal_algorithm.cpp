#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
  
*/

void make_set(int parent[], int size[], int n){
  for(int i=1; i<=n; i++){
    parent[i] = i;
    size[i] = 1;
  }
}

int find_set(int parent[], int v){
  if(v == parent[v]){
    return v;
  }
  return parent[v] = find_set(parent, parent[v]);
}

void union_set(int parent[], int size[], int v1, int v2){
  v1 = find_set(parent, v1);
  v2 = find_set(parent, v2);
  if(v1 != v2){
    if(size[v1] < size[v2]){
      swap(v1, v2);
    }
    parent[v2] = v1;
    size[v1] += size[v2];
  }
}

void MST_using_kruskal(vvi &edges, int parent[], int size[], int m){
  int cost = 0;
  for(int i=0; i<m; i++){
    int w = edges[i][0];
    int u = edges[i][1];
    int v = edges[i][2];
    int x = find_set(parent, u);
    int y = find_set(parent, v);
    if(x == y){
      continue;
    }
    else{
      cout<<u<<' '<<v<<' '<<w;
      cost += w;
      union_set(parent, size, u, v);
    }
    cout<<" => "<<cost<<endl;
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

  int parent[n+1] = {};
  int size[n+1] = {};

  make_set(parent, size, n);
  sort(edges.begin(), edges.end());

  cout<<"u v w => cost"<<endl;
  MST_using_kruskal(edges, parent, size, m);


  cout<<"parent: ";
  for(int i=1; i<=n; i++){
    cout<<parent[i]<<' ';
  }
  cout<<"\nsize: ";
  for(int i=1; i<=n; i++){
    cout<<size[i]<<' ';
  }

  return 0;
}
