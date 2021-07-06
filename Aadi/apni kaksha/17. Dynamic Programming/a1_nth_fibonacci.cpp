#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

/*

*/

// Memoization (bottom-up)
int nth_fibonacci(vi &dp, int n){
  
  if(n == 0 || n == 1){
    dp[n] = 0;
  }
  else if(n == 2){
    dp[n] = 1;
  }
  if(dp[n] == -1){
    dp[n] = nth_fibonacci(dp, n-1) + nth_fibonacci(dp, n-2);
  }
  return dp[n];
}

// Tabulation (top-down)
void fib(int n){
  vi dp(n+1);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  cout<<0<<' '<<1<<' ';
  for(int i=3; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
    cout<<dp[i]<<' ';
  }
}

int main(){
  int n = 10;
  // cout<<"Enter n: ";
  // cin>>n;

  cout<<"Top-down: ";
  fib(n);
  
  vi dp(n+1, -1);
  cout<<"\nBottom-Up: ";
  for(int i=1; i<=n; i++){
    cout<<nth_fibonacci(dp, i)<<' ';
  }
  
  return 0;
}