#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;


void insert(int x){
  if(pqmax.size() == pqmin.size()){
    if(pqmax.size() == 0 || x < pqmin.top()){
      pqmax.push(x);
    }
    else{
      pqmin.push(x);
    }
  }
  else{
    if(pqmin.size() == 0){
      pqmin.push(x);
      return;
    }
    if(x > pqmin.top() && pqmin.size() > pqmax.size()){
      int temp = pqmin.top();
      pqmax.push(temp);
      pqmin.pop();
      pqmin.push(x);
    }
    else if(x < pqmax.top() && pqmax.size() > pqmin.size()){
      int temp = pqmax.top();
      pqmin.push(temp);
      pqmax.pop();
      pqmax.push(x);
    }
    else{
      if(pqmax.size() > pqmin.size()){
        pqmin.push(x);
      }
      else{
        pqmax.push(x);
      }
    }  
  }
}

double find_median(){
  if(pqmax.size() == pqmin.size()){
    return (pqmax.top() + pqmin.top())*1.0 / 2;
  }
  else if(pqmax.size() > pqmin.size()){
    return pqmax.top();
  }
  return pqmin.top();
}

void printpqmax(){
  while(pqmax.size() > 0){
    cout<<pqmax.top()<<' ';
    pqmax.pop();
  }
}

void printpqmin(){
  while(pqmin.size() > 0){
    cout<<pqmin.top()<<' ';
    pqmin.pop();
  }
}

int main(){

  // int arr[] = {10,15,21,30,18,19};
  // int arr[] = {1,2,3,2,1,2,4,6,5,7,8,2};
  int arr[] = {2,4,5,3,1,7,6,11};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<"arr: ";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
  }
  cout<<"\nmedian: ";
  for(int i=0; i<n; i++){
    insert(arr[i]);
    cout<<find_median()<<' ';
  }

  return 0;
}