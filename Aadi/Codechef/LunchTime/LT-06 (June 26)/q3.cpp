#include <bits/stdc++.h>
using namespace std;


bool isValidHTML(string s){
  if((s.size() <= 3 || s[0] != '<') || (s[1] != '/') || (s[s.size()-1] != '>')){
    return false;
  }
  for(int i=2; i<s.size()-1; i++){
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}


int main() {
  int t;
  cout<<"Enter t: ";
  cin>>t;
  while(t--){
    string s;
    cout<<"Enter s: ";
    cin>>s;
    
    if(isValidHTML(s)){
      cout<<"Success"<<endl;
    }
    else{
      cout<<"Error"<<endl;
    }
  }
	return 0;
}
