#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9 + 7;

/*
  https://leetcode.com/problems/two-sum/
*/

// M1: Brute Force [O(n^2), O(1)]

// M2: Two-pass Hash Table [O(n), O(n)]
vi two_sum_m2(vi nums, int target){
  map<int, int> mp;
  for(int i=0; i < nums.size(); i++){
    mp[nums[i]] = i;
  }
  for(int i=0; i < nums.size(); i++){
    int comp = target - nums[i];
    if(mp.find(comp) != mp.end() && mp[comp] != i){
      return {i, mp[comp]};
    }
  }
  return {-1, -1};
}

// M2: One-pass Hash Table [O(n), O(n)]
vi two_sum_m3(vi nums, int target){
  map<int, int> mp;
  for(int i=0; i < nums.size(); i++){
    int comp = target - nums[i];
    if(mp.find(comp) != mp.end()){
      return {i, mp[comp]};
    }
    mp[nums[i]] = i;
  }
  return {-1, -1};
}


int main(){
  
  vi nums = {1,4,9,5,6,7,3,2,8};
  int target = 12;

  // vi ans = two_sum_m2(nums, target);
  vi ans = two_sum_m3(nums, target);

  cout<<"indices: "<<ans[0]<<' '<<ans[1];

  return 0;
}