#include <bits/stdc++.h>
using namespace std;

void smallest_positive_missing_number(int arr[], int n) {
  int N = 10^6 + 1;
  // int mp[N] = {0};
  bool mp[N] = {false};
  for(int i=0; i<n; i++){
    if(arr[i] > 0){
      // mp[arr[i]] = 1;
      mp[arr[i]] = true;
    }
  }
  int j = 1;
  while(j < N && mp[j]){
    j++;
  }
  if(j < N){
    cout<<j;
  }
  else{
    cout<<"No missing positive number";
  }
}

int main() {
  int n;
  cout << "Enter length of array: ";
  cin >> n;
  int a[n];
  cout << "Enter array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  smallest_positive_missing_number(a, n);

  return 0;
}