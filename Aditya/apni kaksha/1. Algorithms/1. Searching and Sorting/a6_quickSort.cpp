#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
  int pivot = arr[e];
  int pi = s;
  for(int i=s; i<e; i++){
    if(arr[i] <= pivot){
      swap(arr[i], arr[pi]);
      pi++;
    }
  }
  // swap(arr[pi], pivot);      // why not swap with pivot?
  swap(arr[pi], arr[e]);        // b/coz pivot is not arr[e]
  return pi;                    // we want to swap arr[e] with arr[pi]
}                               // not with pivot


void quickSort(int arr[], int s, int e){
  if(s < e){
    int pi = partition(arr, s, e);
    quickSort(arr, s, pi-1);
    quickSort(arr, pi+1, e);
  }
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n];
    cout<<"Enter array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    quickSort(a, 0, n-1);
    
    printArray(a, n);

    return 0;
}