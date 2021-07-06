#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
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
    
    insertionSort(a, n);
    
    printArray(a, n);

    return 0;
}