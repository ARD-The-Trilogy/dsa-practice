#include<bits/stdc++.h>
using namespace std;

bool is_sorted(int arr[], int n){
  if(n == 0){
    return true;
  }
  if(arr[n] < arr[n-1]){
    return false;
  }
  return is_sorted(arr, n-1);
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int arr[n];
  cout<<"Enter Array: ";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  cout<<"is_sorted: "<<is_sorted(arr, n);

  return 0;
}