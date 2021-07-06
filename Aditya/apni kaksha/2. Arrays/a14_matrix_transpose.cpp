#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  int matrix[n][n];
  cout << "Enter matrix: "<<endl;
  for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>matrix[i][j];
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  
  cout<<"Transpose Matrix: "<<endl;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<matrix[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}