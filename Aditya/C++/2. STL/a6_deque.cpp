#include<bits/stdc++.h>
using namespace std;

void printDeque(deque<int> dq){
  // for( auto i : dq){
  //   cout<<i<<' ';
  // }
  for(auto it=dq.begin(); it != dq.end(); it++){
    cout<<*it<<' ';
  }
  cout<<endl;
}

int main(){
  deque <int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_front(3);
  dq.push_front(4);

  printDeque(dq);

  dq.pop_front();
  dq.pop_back();
  
  printDeque(dq);

  return 0;
}