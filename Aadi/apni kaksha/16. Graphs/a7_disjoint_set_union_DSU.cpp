#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i=a; i<b; i++)

/*
  https://www.geeksforgeeks.org/union-find/
  https://youtu.be/C0O8T3C8irU
*/

// Naive Implementation  [O(N)]

void make(int parent[], int v){
  parent[v] = v;
}

int find(int parent[], int v){
  if(v == parent[v]){
    return v;
  }
  return find(parent, parent[v]);
}

void union(int parent[], int v1, int v2){
  int p1 = find(parent, v1);      // to reduce the time of union
  int p2 = find(parent, v2);      // find() operation must be optimized
  if(v1 != v2){
    parent[v2] = v1;
  }
}

/*
   v1      => parent/leading element
   ↑
   v2      => member element
*/


// Path Compression  [O(logN)]

int find(int parent[], int v){
  if(v == parent[v]){
    return v;
  }
  return parent[v] = find(parent, parent[v]);  // this is the only difference
}


// Union by size/rank  [O(α(N)]
void make(int parent[], int size[], int v){
  parent[v] = v;
  size[v] = 1;
}

int find(int parent[], int v){
  if(v == parent[v]){
    return v;
  }
  return parent[v] = find(parent, parent[v]);  // this is the only difference
}

void union(int parent[], int size[], int v1, int v2){
  v1 = find(parent, v1);
  v2 = find(parent, v2);
  if(v1 != v2){
    if(size[v1] < size[v2]){
      swap(v1, v2);
    }
    parent[v2] = v1;      // shorter tree is inserted below longer one to reduce time
    size[v1] += size[v2];
  }
}


int main(){

/*

    ↗  ↖    ↘  ↙   ↑ ↓   → ←  
    ↕  ←→   /   \   ↼⇁   ↽⇀
                                                                                      _ _ _ _ _                  
                                                                                    ↓`         `↖         
          1          union(5,7)               1                                     1           6
          ↑                               ↗ ↗  ↖ ↖                             ↗ ↗  ↖ ↖        ↑   
          2          find using          2  3   5  7     union by size         2  3   5  7      8        
        ↗  ↖       path compression     ↑   ↑           =============>>                         
       3     4      ============>>       4  6          O[logN] -> [O(α(N)]                        
     ↗  ↖          O[N] -> O[logN]          ↑        
    5     6                                 8
    ↑     ↑     
   (7)    8            


*/

  return 0;
}