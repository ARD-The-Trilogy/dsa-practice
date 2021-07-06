#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1541/problem/B

int main(){
  int t;
  // cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    // cout<<"Enter n: ";
    cin>>n;
    int a[n];
    // cout<<"Enter array: ";
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    
    vector<pair<int,int>> vp;
    for(int i=0; i<n; i++){
      vp.push_back(make_pair(a[i], i+1));
    }
    sort(vp.begin(), vp.end());

    int smax = n + (n-1);
    int res = 0;
    for(int i=0; i<n; i++){
      if((vp[i].first)*(vp[i+1].first) > smax){
        break;
      }
      for(int j=i+1; j<n; j++){
        int m = (vp[i].first)*(vp[j].first);
        int s = (vp[i].second)+(vp[j].second);
        if(m == s){
          res++;
        }
        if(m > smax){
          break;
        }
      }
    }
    cout<<res<<endl;
    // for(int i=0; i<n; i++){
    //   cout<<vp[i].second<<' ';
    // }
    // cout<<endl;
  }
}