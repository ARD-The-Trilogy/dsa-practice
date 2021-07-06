#include<bits/stdc++.h>
using namespace std;

int main(){
  list <int> ls;
  int n;
  cout<<"Enter n: ";
  cin>>n;
  for(int i=0; i<n; i++){
    ls.push_back(i+1);
  }
  for(auto it=ls.begin(); it!=ls.end(); it++){
    cout<<*it<<"->";
  }
  cout<<"NULL";
  return 0;
}