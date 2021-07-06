#include<bits/stdc++.h>
using namespace std;

void print_numbers_n_to_0(int n){
  if(n == 0){
    return;
  }
  cout<<n<<' ';
  print_numbers_n_to_0(n-1);
}
void print_numbers_0_to_n(int n){
  if(n == 0){
    return;
  }
  print_numbers_0_to_n(n-1);
  cout<<n<<' ';
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;

  cout<<"0 to n: ";
  print_numbers_0_to_n(n);
  cout<<endl<<"n to 0: ";
  print_numbers_n_to_0(n);
  
  return 0;
}