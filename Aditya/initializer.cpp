#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  
*/

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vi v(n);
    cout<<"Enter vect: ";
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    for(int i=0; i<n; i++){
      cout<<v[i]<<' ';
    }

  }
  return 0;
}