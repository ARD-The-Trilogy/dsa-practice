#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://youtu.be/x5hQvnUcjiM
  https://www.geeksforgeeks.org/printing-longest-common-subsequence/
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

string print_lcs(vvi &dp, string x, string y, int n, int m){

  lcs_BU(dp, x, y, n, m);

  string res = "";
  int i = n, j = m;

  while(i > 0 && j > 0){
    if(x[i-1] == y[j-1]){
      res += x[i-1];
      i--;
      j--;
    }
    else{
      if(dp[i][j-1] > dp[i-1][j]){
        j--;
      }
      else{
        i--;
      }
    }
  }

  reverse(res.begin(), res.end());

  return res;
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
  
  cout<<"lcs: ";
  cout<<print_lcs(bu, x, y, n, m);
  cout<<" => "<<lcs_BU(bu, x, y, n, m)<<endl;

  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<=m; j++){
  //     cout<<bu[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }

  return 0;
}