#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int s, int e, int key){
    while(s <= e){
        int m = (s+e)/2;
        if(arr[m] == key){
            return m;
        }
        else if(arr[m] < key){
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n];
    cout<<"Enter sorted array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter key: ";
    int key;
    cin>>key;
    
    cout<<"index: "<<binarySearch(a, 0, n-1, key);
    return 0;
}