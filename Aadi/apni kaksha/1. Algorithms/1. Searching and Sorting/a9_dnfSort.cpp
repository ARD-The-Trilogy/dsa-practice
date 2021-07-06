#include <bits/stdc++.h>
using namespace std;

//Also known as 012-sort
void dnfSort(int arr[], int n){
  int low = 0;
  int mid = 0;
  int high = n-1;
  while(mid <= high){
    if(arr[mid] == 0){
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if(arr[mid] == 1){
      mid++;
    }
    else if(arr[mid] == 2){
      swap(arr[mid], arr[high]);
      high--;
    }
  }
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
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
  
  dnfSort(a, n);
  
  return 0;
}

// Enter n: 10
// Enter array: 1 0 2 1 0 1 2 1 2 0
// 0 0 0 1 1 1 1 2 2 2