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
   long long int a, b;
    // cout<<"Enter a b: ";
    cin>>a>>b;
 
    if(a == b){
      a = 0; b = 0;
    }
    else{
      a = abs(a-b);
      b = min((b%a) ,a-(b%a));
    }
    cout<<a<<' '<<b<<endl;
  }
  return 0;
}

// a b: 1 10