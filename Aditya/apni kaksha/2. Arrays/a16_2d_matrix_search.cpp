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

int main() {
  int m, n;
  cout << "Enter m n: ";
  cin >> m >> n;
  int matrix[m][n];
  cout << "Enter the sorted matrix: "<<endl;
  for (int i = 0; i < m; i++) {
    for(int j=0; j<n; j++){
      cin>>matrix[i][j];
    }
  }
  int target;
  cout<<"Enter target value: ";
  cin>>target;

  cout<<"Target posititon: ";
  
  for(int j=0; j<n; j++){
    int pos = binarySearch(matrix[][j], 0, n, target);
    if(pos != -1){
      cout<<'['<<pos<<']'<<'['<<j<<']';
      return 0;
    }
  }
  cout<<"Not found";

  return 0;
}