#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://www.geeksforgeeks.org/longest-repeated-subsequence/
  https://www.geeksforgeeks.org/longest-repeating-subsequence/
*/

// Tabulation (Bottom-Up)
int LRS(string x){
  int n = x.size();
  vvi dp(n+1, vi(n+1, -1));
  string y = x;
  
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else{
        if((x[i-1] == y[j-1]) && (i != j)){
          dp[i][j] = 1 + dp[i-1][j-1];
        }
        else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
  }
  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<=n; j++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  return dp[n][n];
}


int main(){
  // string x = "codechef";    // codece
  // string x = "codeforces";
  string x = "geeksforgeeks";   // ekorek
  string y = "freakofreak";
  string z = "aabebcdd";
  
  cout<<"LPS: "<<endl;
  cout<<x<<" => "<<LRS(x)<<endl;
  cout<<y<<" => "<<LRS(y)<<endl;
  cout<<z<<" => "<<LRS(z)<<endl;

  return 0;
}