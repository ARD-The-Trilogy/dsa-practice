#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    
    bubbleSort(a, n);

    printArray(a, n);
    
    return 0;
}