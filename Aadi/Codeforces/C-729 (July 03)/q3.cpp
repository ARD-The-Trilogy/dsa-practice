#include<bits/stdc++.h>
using namespace std;

/*
  https://codeforces.com/contest/1542
  https://codeforces.com/contest/1542/standings
  https://codeforces.com/contest/1542/problem/B
*/

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    // cout<<"Enter n: ";
    cin>>n;

    long long int N = 1e9 + 7;
    int ans = 0;
    int arr[n];
    for(int i=1; i<=n; i++){
      long long int d = 2;
      while(i%d != 0){
        d++;
      }
      cout<<d<<' ';
      ans += d % N;
    }
   
    cout<<' '<<ans<<endl;
  }
  return 0;
}