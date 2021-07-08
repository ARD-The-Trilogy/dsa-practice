#include<bits/stdc++.h>
using namespace std;


int main(){
  int arr[] = {2,2,2,1,1,4,3,4};
  int n = sizeof(arr)/sizeof(arr[0]);

  map<int, int> mp;

  for(int i=0; i<n; i++){
    mp[arr[i]]++;
  }

  cout<<"freq count of elements: "<<endl;
  for(auto it= mp.begin(); it != mp.end(); it++){
    cout<<it->first<<" => "<<it->second<<endl;
  }

  return 0;
}