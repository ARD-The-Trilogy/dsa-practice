#include <bits/stdc++.h>
using namespace std;

int main() {
  int n1, n2, n3;
  cout << "Enter n1 n2 n3: ";
  cin >> n1>>n2>>n3;
  int matrix1[n1][n2];
  int matrix2[n2][n3];
  int matrix[n1][n3] = {0};
  cout << "Enter matrix1: "<<endl;
  for (int i=0; i<n1; i++){
    for(int j=0; j<n2; j++){
      cin>>matrix1[i][j];
    }
  }
  cout << "Enter matrix2: "<<endl;
  for (int i=0; i<n2; i++){
    for(int j=0; j<n3; j++){
      cin>>matrix2[i][j];
    }
  }
  for (int i=0; i<n1; i++){
    for(int j=0; j<n3; j++){
      matrix[i][j] = 0;
    }
  }
  
  for(int i=0; i<n1; i++){
    for(int k=0; k<n3; k++){
      for(int j=0; j<n2; j++){
        matrix[i][k] += (matrix1[i][j])*(matrix2[j][k]);
      }
    }
  }
  
  cout<<"Result matrix: "<<endl;
  
  for(int i=0; i<n1; i++){
    for(int j=0; j<n3; j++){
      cout<<matrix[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}