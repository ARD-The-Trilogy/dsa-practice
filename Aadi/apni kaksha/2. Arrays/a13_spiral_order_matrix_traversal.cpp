#include <bits/stdc++.h>
using namespace std;

// void spiral_order_matrix_traversal(int matrix[][], int m, int n) {
  
// }

int main() {
  int m, n;
  cout << "Enter m n: ";
  cin >> m >> n;
  int matrix[m][n];
  cout << "Enter matrix: "<<endl;
  for (int i = 0; i < m; i++) {
    for(int j=0; j<n; j++){
      cin>>matrix[i][j];
    }
  }
  cout<<"Spiral Order Matrix: "<<endl;
  for(int k=0; k<(min(m,n)+1)/2; k++){
    for(int j=k; j<n-k; j++){
      cout<<matrix[k][j]<<' ';
    }
    cout<<endl;
    for(int i=k+1; i<m-k; i++){
      cout<<matrix[i][n-k-1]<<' ';
    }
    cout<<endl;
    for(int j=n-k-2; j>=k; j--){
      cout<<matrix[m-k-1][j]<<' ';
    }
    cout<<endl;
    for(int i=m-k-2; i>k; i--){
      cout<<matrix[i][k]<<' ';
    }
    cout<<endl;
  }

  // spiral_order_matrix_traversal((int*)matrix, m, n);

  return 0;
}