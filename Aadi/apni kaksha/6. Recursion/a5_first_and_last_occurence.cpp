#include<bits/stdc++.h>
using namespace std;

int first_occurence(int arr[], int n, int key){
  if(n == 0){
    return -1;
  }
  if(arr[0] == key){
    return n;
  }
  int first = first_occurence(arr, n-1, key);
  return first;
}

int last_occurence(int arr[], int n, int key){
  if(n == 0){
    return -1;
  }
  if(arr[n] == key){
    return n;
  }
  return last_occurence(arr, n-1, key);
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int arr[n];
  cout<<"Enter Array: ";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int key;
  cout<<"Enter key: ";
  cin>>key;

  cout<<"first occurence: "<<first_occurence(arr, n, key)<<endl;
  cout<<"last occurence: "<<last_occurence(arr, n, key)<<endl;

  return 0;
}