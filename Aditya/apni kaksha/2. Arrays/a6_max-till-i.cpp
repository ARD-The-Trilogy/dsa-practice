#include <bits/stdc++.h>
using namespace std;

void max_till_i(int arr[], int n){
    int tempMax = arr[0];
    for(int i=0; i<n; i++){
        tempMax = max(tempMax, arr[i]);
        cout<<tempMax<<" ";
    }
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
    
    max_till_i(a, n);

    return 0;
}