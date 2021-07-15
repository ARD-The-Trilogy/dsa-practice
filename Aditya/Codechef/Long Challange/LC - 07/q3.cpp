#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://www.codechef.com/JULY21C/problems/XXOORR
*/

bool getBit(int n, int pos){
  return ((n & (1<<pos)) != 0);
}

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n, k;
    cout<<"Enter n k: ";
    cin>>n>>k;
    vi v(n);
    cout<<"Enter vect: ";
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    int ans = 0;
    for(int u=0; u<32; u++){
      int x = 0;
      for(int i=0; i<n; i++){
        if(getBit(v[i], u) == 1){
          x++;
        }
      }
      ans += ceil((x*1.0)/k);
      // cout<<ans<<' ';
    }
    cout<<ans<<endl;
  }
  return 0;
}