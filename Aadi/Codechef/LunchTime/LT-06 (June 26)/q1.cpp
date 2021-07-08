#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    cout<<"Enter a b x: ";
    int a, b, x;
    cin>>a>>b>>x;
    int res;
    res = ceil(((b-a)*1.0)/x);
    cout<<res<<endl;
  }
	return 0;
}
