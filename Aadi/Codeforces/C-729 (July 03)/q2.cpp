#include<bits/stdc++.h>
using namespace std;

/*
  https://codeforces.com/contest/1542
  https://codeforces.com/contest/1542/standings
  https://codeforces.com/contest/1542/problem/B
  https://codeforces.com/contest/1542/submission/121207778
*/

bool pnm(int n, int a, int b){
  queue<long long int> q;
  q.push(1);
  while(!q.empty()){
    long long int x = q.front();
    // cout<<' '<<x;
    q.pop();
    if(x == n){
      return true;
    }
    long long int u = x*a;
    long long int v = x+b;
    if(u <= n && u != x){
      q.push(u);
    }
    if(v <= n){
      q.push(v);
    }
  }
  return false;
}

int main(){
  int t;
  // cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n, a, b;
    // cout<<"Enter n: ";
    cin>>n>>a>>b;

    if(pnm(n, a, b)){
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
  return 0;
}