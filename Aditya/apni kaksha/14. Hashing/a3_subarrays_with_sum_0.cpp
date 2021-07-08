#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
// https://youtu.be/5g03Ydcwseg


int main(){
  int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
  int n = sizeof(arr)/sizeof(arr[0]);

  // unordered_map<int, vector<int>> ump;     // better complexity
  map<int, vector<int>> mp;

  int curr_sum = 0;
  mp[0].push_back(-1);
  for(int i=0; i<n; i++){
    curr_sum += arr[i];
    mp[curr_sum].push_back(i);
  }

  cout<<"sum => index: ";
  for(auto it= mp.begin(); it != mp.end(); it++){
    cout<<endl<<it->first<<" => ";
    for(int i=0; i < (it->second).size(); i++){
      cout<<(it->second)[i]<<' ';
    }
  }

// https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
  cout<<"\nsubarrays with sum = 0: ";
  for(auto it= mp.begin(); it != mp.end(); it++){  // not optimized
    if((it->second).size() > 1){
      for(int i=0; i < (it->second).size(); i++){
        for(int j=i+1; j < (it->second).size(); j++){
          cout<<endl<<(it->second)[i]+1<<" - "<<(it->second)[j];
        }
      }
    }
  }


  return 0;
}