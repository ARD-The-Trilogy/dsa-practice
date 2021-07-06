#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int d, x, y, z;
    cout<<"Enter d x y z: ";
    cin>>d>>x>>y>>z;

    int w1, w2;
    w1 = 7*x;
    w2 = d*y + (7-d)*z;

    if(w1 > w2){
      cout<<w1<<endl;
    } else {
      cout<<w2<<endl;
    }
  }
  return 0;
}