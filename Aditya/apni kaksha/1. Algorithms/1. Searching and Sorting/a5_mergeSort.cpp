#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e, int m){
  int n1 = m-s+1;
  int n2 = e-m;
  int a[n1];
  int b[n2];
  for(int i=0; i<n1; i++){
    a[i] = arr[s+i];
  }
  for(int i=0; i<n2; i++){
    b[i] = arr[m+1+i];
  }
  int i = 0, j = 0;
  int k = s;
  while(i < n1 && j < n2){
    if(a[i] <= b[j]){
      arr[k] = a[i];
      i++, k++;
    }
    else{
      arr[k] = b[j];
      j++, k++;
    }
  }
  while(i < n1){
    arr[k] = a[i];
    i++, k++;
  }
  while(j < n2){
    arr[k] = b[j];
    j++, k++;
  }
}


void mergeSort(int arr[], int s, int e){
  if(s < e){
    int m = (s+e)/2;
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, e, m);
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
    
    mergeSort(a, 0, n-1);
    
    printArray(a, n);

    return 0;
}