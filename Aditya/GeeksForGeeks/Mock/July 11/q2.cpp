#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  
*/

int solve(string s1, string s2){
  vi a(26, 0), b(26, 0);
  int ans = 0;
  for(int i=0; i<s1.size(); i++){
    a[s1[i] - 'a']++;
  }
  for(int i=0; i<s2.size(); i++){
    b[s2[i] - 'a']++;
  }
  for(int i=0; i<26; i++){
    ans += abs(b[i] - a[i]);
  }
  return ans;
}

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    string s1, s2;
    cout<<"Enter s1 s2: ";
    cin>>s1>>s2;
    
    cout<<solve(s1, s2)<<endl;

  }
  return 0;
}