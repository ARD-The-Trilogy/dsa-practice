#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    string s;
    cout<<"Enter a: ";
    cin>>s;
    string res = "";
    if(s[0] == '1'){
      res = "10" + s.substr(1);
    }
    else{
      res = "1" + s;
    }
    cout<<res<<endl;
  }
	return 0;
}
