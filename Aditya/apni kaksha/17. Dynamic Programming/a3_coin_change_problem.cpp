#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;
/*
  https://youtu.be/GBBRjI_1LRI
  https://www.geeksforgeeks.org/coin-change-dp-7/ 
*/


// Memoization (Top-Down)


// Tabulation (Bottom-Up)



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