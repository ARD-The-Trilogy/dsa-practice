#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
  int row = x, col = y;
  while((row > 0 && row < n) && col > 0){
    if(arr[row][col] == 1){
      return false;
    }
    row--;
    col--;
  }
  row = x;
  col = y;
  while((row > 0 && row < n) && col > 0){
    if(arr[row][col] == 1){
      return false;
    }
    row++;
    col--;
  }
  row = x;
  col = y;
  while((row > 0 && row < n) && col > 0){
    if(arr[row][col] == 1){
      return false;
    }
    col--;
  }
  return true;
}

bool n_queens(int** arr, int x, int n){
  if(x >= n){
    return true;
  }
  for(int col=0; col<n; col++){
    if(isSafe(arr, x, col, n)){
      arr[x][col] = 1;
      if(n_queens(arr, x+1, n)){
        return true;
      }
      arr[x][col] = 0;        // Backtrack
    }
  }
  return false;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int** chess = new int*[n];
  for(int i=0; i<n; i++){
    chess[i] = new int[n];
    for(int j=0; j<n; j++){
      chess[i][j] = 0;
    }
  }

  if(n_queens(chess, 0, n)){
    cout<<"Successful :)"<<endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<<chess[i][j]<<' ';
      }
      cout<<endl;
    }
  } else {
    cout<<"Sorry!";
  }

  return 0;
}