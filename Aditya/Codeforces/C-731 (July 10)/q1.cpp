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
    int xa, ya, xb, yb, xf, yf;
    // cout<<"Enter a b f: ";
    cin>>xa>>ya>>xb>>yb>>xf>>yf;

    int ans = 0;    
    if(xa != xb && ya != yb){
      ans = abs(xb - xa) + abs(yb - ya);
    }
    else if(xa == xb){
      if(xf != xa){
        ans = abs(yb - ya);
      }
      else{
        if(yf >= min(ya, yb) && yf <= max(ya, yb)){
          ans = abs(yb - ya) + 2;
        }
        else{
          ans = abs(yb - ya);
        }
      }
    }
    else if(ya == yb){
      if(yf != ya){
        ans = abs(xb - xa);
      }
      else{
        if(xf >= min(xa, xb) && xf <= max(xa, xb)){
          ans = abs(xb - xa) + 2;
        }
        else{
          ans = abs(xb - xa);
        }
      }
    }

    cout<<ans<<endl;

  }
  return 0;
}