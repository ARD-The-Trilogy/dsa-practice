#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int mn = arr[i];
        int imin = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < mn){
                mn = arr[j];
                imin = j;
            }
        }
        arr[imin] = arr[i];
        arr[i] = mn;
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
    
    selectionSort(a, n);

    printArray(a, n);
    
    return 0;
}