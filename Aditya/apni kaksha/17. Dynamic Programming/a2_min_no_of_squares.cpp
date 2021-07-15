#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

/*
  https://youtu.be/EoMxK6zh9wU
*/

const int INF = 1e9;

// Memoization (Top-Down)
int minSquaresTD(vi &dp, int n){
  cout<<n<<" > ";
  if(n == 0 || n == 1){
    dp[n] = n;
  }
  if(dp[n] == INF){
    for(int i=1; i <= sqrt(n); i++){
      dp[n] = min(dp[n], 1 + minSquaresTD(dp, (n - i*i)));
    }
  }
  return dp[n];
}

// Tabulation (Bottom-Up)
int minSquaresBU(int n){
  vi dp(n+1, INF);
  dp[0] = 0;
  dp[1] = 1;
  for(int i=1; i<=sqrt(n); i++){
    for(int j=0; j <= n-i*i; j++){
      dp[i*i + j] = min(dp[i*i + j], 1 + dp[j]);
      cout<<i*i + j<<"-"<<dp[i*i + j]<<"  ";
    }
    cout<<endl;
  }
  for(int i=1; i<=n; i++){
    cout<<dp[i]<<' ';
  }
  return dp[n];
}

int main(){
  int n = 10;
  vi dp(n+1, INF);
  cout<<"Top-Down: "<<endl;
  cout<<n<<" => "<<minSquaresTD(dp, n)<<endl;
  for(int i=1; i<=n; i++){
    cout<<" => "<<minSquaresTD(dp, i)<<endl;
  }
  
  cout<<"Bottom-Up: "<<endl;
  cout<<endl<<n<<" => "<<minSquaresBU(n)<<endl;

  return 0;
}