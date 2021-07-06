#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter key: ";
    int key;
    cin>>key;
    
    cout<<"index: "<<linearSearch(a, n, key);
    return 0;
}