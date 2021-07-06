#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
}

//https://youtu.be/GuTPwotSdYw

void permutations(int arr[], int n, int l){
  if(l == n-1){
    printArray(arr, n);
    return;
  }
  for(int i=l; i<n; i++){
    swap(arr[l], arr[i]);
    permutations(arr, n, l+1);
    swap(arr[l], arr[i]);    //Backtrack
  }
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int arr[n];
  cout<<"Enter array: ";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  permutations(arr, n, 0);

  return 0;
}