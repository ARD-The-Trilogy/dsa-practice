#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int sorted_arr[]){
  int MAX_VALUE = 0;
  for(int i=0; i<n; i++){
    MAX_VALUE = max(MAX_VALUE, arr[i]);
  }
  // cout<<MAX_VALUE;
  int count_arr[MAX_VALUE + 1] = {0};
  int position_arr[MAX_VALUE + 1] = {0};

  for(int i=0; i<n; i++){
    count_arr[arr[i]]++;
  }
  position_arr[0] = count_arr[0];
  for(int i=1; i<=MAX_VALUE; i++){
    position_arr[i] = position_arr[i-1] + count_arr[i];
  }
  for(int i=n-1; i>=0; i--){
    position_arr[arr[i]]--;
    sorted_arr[position_arr[arr[i]]] = arr[i];
  }

  for(int i=0; i<n; i++){
    cout<<sorted_arr[i]<<' ';
  }
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int a[n];
  int sorted_arr[n] = {0};
  cout<<"Enter array: ";
  for(int i=0; i<n; i++){
      cin>>a[i];
  }
  
  countSort(a, n, sorted_arr);
  
  return 0;
}