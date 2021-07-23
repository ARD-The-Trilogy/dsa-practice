#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  
*/

int solve(vi v, int n){
  sort(v.begin(), v.end());
  int ans = 0;
  for(int k=0; k<n; k++){
    int a = v[k];
    int seek = -a;
    int i = k+1, j = n-1;
    while(i < j){
      if(v[i] + v[j] == seek){
        cout<<v[k]<<' '<<v[i]<<' '<<v[j]<<endl;
        ans++;
        j--;
      }
      else if(v[i] + v[j] < seek){
        i++;
      }
      else{
        j--;
      }
    }
  }
  return ans;
}


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
    
    cout<<solve(v, n)<<endl;

  }
  return 0;
}