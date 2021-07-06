#include <bits/stdc++.h>
using namespace std;

bool myComparator(pair<int,int> p1, pair<int,int> p2){
  return (p1.first < p2.first);
}

void array_reduction(int arr[], int n){
  vector<pair<int,int>> vp;
  for(int i=0; i<n; i++){
    vp.push_back(make_pair(arr[i], i));
  }
  sort(vp.begin(), vp.end(), myComparator);
  for(int i=0; i<n; i++){
    arr[vp[i].second] = i;
  }
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
  }
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

  array_reduction(a, n);

  return 0;
}


// Input array: 10 16 7 14 5 3 12 9
// Output array: 4 7 2 6 1 0 5 3