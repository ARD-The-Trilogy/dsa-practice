#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*

*/

// Recursive solution
int lcs(string x, string y, int n, int m){
  if(n == 0 || m == 0){
    return 0;
  }
  if(x[n-1] == y[m-1]){
    return 1 + lcs(x, y, n-1, m-1);
  }
  return max(lcs(x, y, n, m-1), lcs(x, y, n-1, m));
}


// Memoization (Top-Down)
int lcs_TD(vvi &dp ,string x, string y, int n, int m){
  if(dp[n][m] != -1){
    return dp[n][m];
  }
  if(n == 0 || m == 0){
    return dp[n][m] = 0;
  }
  if(x[n-1] == y[m-1]){
    dp[n][m] = 1 + lcs_TD(dp, x, y, n-1, m-1);
  }
  else{
    dp[n][m] = max(lcs_TD(dp, x, y, n, m-1), lcs_TD(dp, x, y, n-1, m));
  }
  return dp[n][m];
}


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


int main(){
  string x = "codechef";    // codece
  string y = "codeforces";
  // string x = "geeksforgeeks";   // ekorek
  // string y = "freakofreak";
  int n = x.size();
  int m = y.size();

  vvi td(n+1, vi(m+1, -1));
  vvi bu(n+1, vi(m+1, -1));

  cout<<"Recursive: ";
  cout<<lcs(x, y, n, m)<<endl;

  cout<<"Top-Down: ";
  cout<<lcs_TD(td, x, y, n, m)<<endl;
  
  cout<<"Bottom-Up: ";
  cout<<lcs_BU(bu, x, y, n, m)<<endl;

  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<=m; j++){
  //     cout<<bu[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }

  return 0;
}