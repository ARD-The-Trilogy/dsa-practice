#include<bits/stdc++.h>
using namespace std;

void printSet(set<int> s){
  for(auto it= s.begin(); it != s.end(); it++){
    cout<<*it<<' ';
  }
  cout<<endl;
}

/*
  https://youtu.be/F3Cpo4Cc04A

  https://www.geeksforgeeks.org/set-in-cpp-stl/
  https://www.geeksforgeeks.org/multiset-in-cpp-stl/
  https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/

*/


int main(){

  set<int> s1;                // duplicates not allowed
  set<int, greater<int>> s2;  // set in decresing order
  multiset<int> ms;           // duplicates allowed
  unordered_set<int> us;      // implemented using hash


  s1.insert(1);
  s1.insert(2);
  s1.insert(3);
  s1.insert(4);
  s1.insert(5);
  // no duplicates
  s1.insert(2);
  s1.insert(3);

  printSet(s1);
  
  cout<<"size: "<<s1.size()<<endl;

  s1.erase(3);
  s1.erase(s1.begin(), s1.find(2));

  cout<<"After erase: ";
  printSet(s1);

  cout<<"lower bounds: ";
  cout<<*s1.lower_bound(3)<<' ';
  cout<<*s1.lower_bound(4)<<' ';
  cout<<"\nupper bounds: ";
  cout<<*s1.upper_bound(3)<<' ';
  cout<<*s1.upper_bound(4)<<' ';

  return 0;

}