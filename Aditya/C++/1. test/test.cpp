#include <bits/stdc++.h>
using namespace std;

int add(int a, int b){
  void printSum(int a, int b);
  printSum(a,b);
  return a+b;
}
void printSum(int a, int b){
  cout<<a+b<<endl;
}

int main()
{
  int a = 5, b = 10;
  int sum = add(a, b);
  cout<<"sum = "<<sum;
  return 0;
}
