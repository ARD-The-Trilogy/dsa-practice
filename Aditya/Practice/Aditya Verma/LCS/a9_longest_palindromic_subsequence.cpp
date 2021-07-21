#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://youtu.be/wuOOOATz_IA  => LPS
*/

// Tabulation (Bottom-Up)
int lcs_BU(vvi &dp, string x, string y, int n, int m){
  for(int i=0; i<=n; i++){
    for(int j=0; j<=m; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else{
        if(x[i-1] == y[j-1]){
          dp[i][j] = 1 + dp[i-1][j-1];
        }
        else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
  }
  return dp[n][m];
}

int LPS(string x){

  int n = x.size();
  string y = x;
  reverse(y.begin(), y.end());

  vvi bu(n+1, vi(n+1, -1));
  int res = lcs_BU(bu, x, y, n, n);

  return res;
}


int main(){
  // string x = "codechef";    // codece
  // string x = "codeforces";
  string x = "geeksforgeeks";   // ekorek
  string y = "freakofreak";
  string z = "agbcba";
  
  cout<<"LPS: "<<endl;
  // cout<<print_lcs(bu, x, y, n, m);
  cout<<x<<" => "<<LPS(x)<<endl;
  cout<<y<<" => "<<LPS(y)<<endl;
  cout<<z<<" => "<<LPS(z)<<endl;

  return 0;
}