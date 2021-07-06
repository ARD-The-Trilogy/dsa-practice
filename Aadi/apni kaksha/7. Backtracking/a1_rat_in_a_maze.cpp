#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
  if((x < n && y < n) && arr[x][y] == 1){
    return true;
  }
  return false;
}

bool rat_in_maze(int** arr, int x, int y, int n, int** solArr){
  if(x == n-1 && y == n-1){
    solArr[x][y] = 1;
    return true;
  }
  if(isSafe(arr, x, y, n)){
    solArr[x][y] = 1;
    if(rat_in_maze(arr, x+1, y, n, solArr)){
      return true;
    }
    if(rat_in_maze(arr, x, y+1, n, solArr)){
      return true;
    }    
  }
  solArr[x][y] = 0;    //Backtrack
  return false;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  int** maze = new int*[n];
  for(int i=0; i<n; i++){
    maze[i] = new int[n];
  }

  cout<<"Set the maze: "<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>maze[i][j];
    }
  }

  int** solArr = new int*[n];
  for(int i=0; i<n; i++){
    solArr[i] = new int[n];
    for(int j=0; j<n; j++){
      solArr[i][j] = 0;
    }
  }

  if(rat_in_maze(maze, 0, 0, n, solArr)){
    cout<<"Look, I'm out."<<endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<<solArr[i][j]<<' ';
      }
      cout<<endl;
    }
  } else {
    cout<<"Sorry, I got stuck in there.";
  }

  return 0;
}