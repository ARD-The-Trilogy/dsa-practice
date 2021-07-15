#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  
*/

int main(){
  int t;
  // cout<<"Enter t: ";
  cin>>t;
  while(t--){
    string s;
    // cout<<"Enter str: ";
    cin>>s;
    
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ans = "YES";
    int charr[26] = {0};

    for(int i=0; i < s.size(); i++){
      
      if(s[i] > alpha[s.size()-1]){
        ans = "NO";
        // cout<<"bigger ";
      }
      if(charr[s[i] - 'a'] != 0){
        ans = "NO";
        // cout<<"repeat ";
      }

      charr[s[i] - 'a'] = i+1;
    }
    if(ans != "NO"){
      int p = charr[0] + 1;
      int q = charr[0] - 1;
      for(int i=1; i<s.size(); i++){
        if(charr[i] == p){
          // cout<<p<<' ';
          p++;
        }
        else if(charr[i] == q){
          // cout<<q<<' ';
          q--;
        }
        else{
          ans = "NO";
          break;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}