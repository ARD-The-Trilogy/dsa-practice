#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/LTIME97C/problems/TICTACTO
// https://youtu.be/5g03Ydcwseg    => # prefix sum


int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n, m, k;
    cout<<"Enter n m k: ";
    cin>>n>>m>>k;
    char a[n+1][m+1];
    for(int i=0; i<n*m; i++){
      cout<<"Enter x y: ";
      int x, y;
      cin>>x>>y;
      if(i % 2 == 0){
        a[x][y] = 'A';
      }
      else{
        a[x][y] = 'B';
      }
    }
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        cout<<a[i][j]<<' ';
      }
      cout<<endl;
    }
  }
  return 0;
}