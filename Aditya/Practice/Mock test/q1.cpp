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
    string p, h;
    cout<<"Enter strings p h: ";
    cin>>p>>h;
    
    vvi mp(26);

    for(int i=0; i<h.size(); i++){
      mp[h[i] - 'a'].push_back(i);
    }
    for(int i=0; i<p.size(); j++){
      
    }

    for(int i=0; i<26; i++){
      for(int j=0; j<mp[i].size(); j++){
        cout<<mp[i][j]<<' ';
      }
      cout<<endl;
    }

  }
  return 0;
}