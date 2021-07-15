#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://codeforces.com/contests/1543
*/

int main(){
  int t;
  // cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    // cout<<"Enter n: ";
    cin>>n;
    vi v(n);
    // cout<<"Enter vect: ";
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    long long int sum = 0;
    for(int i=0; i<n; i++){
      sum += v[i];
    }
    long long int a = sum % n;
    long long int ans = a*(n-a);

    cout<<ans<<endl;

  }
  return 0;
}