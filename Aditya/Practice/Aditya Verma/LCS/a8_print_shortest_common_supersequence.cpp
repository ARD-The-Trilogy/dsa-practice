#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://youtu.be/823Grn4_dCQ  => shortest common supersequence
  https://youtu.be/-fx6aDxcWyg  => Minimum Number of Insertion and Deletion to convert String a to String b
  https://www.geeksforgeeks.org/shortest-common-supersequence/
*/

// Tabulation (Bottom-Up)
int SCS(vvi &dp, string x, string y, int n, int m){
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
  return (n + m) - dp[n][m];    // only this line changes in LCS -> SCS
}

string print_SCS(vvi &dp, string x, string y, int n, int m){

  SCS(dp, x, y, n, m);

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
        res += x[j-1];
        j--;
      }
      else{
        res += y[i-1];
        i--;
      }
    }
  }
  while(i > 0){
    res += x[i-1];
    i--;
  }
  while(j > 0){
    res += y[j-1];
    j--;
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

  // vvi td(n+1, vi(m+1, -1));
  vvi bu(n+1, vi(m+1, -1));

  cout<<"SCS: "<<print_SCS(bu, x,y, n, m);
  cout<<" => "<<SCS(bu, x, y, n, m)<<endl;

  return 0;
}