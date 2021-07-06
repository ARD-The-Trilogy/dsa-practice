#include<bits/stdc++.h>
using namespace std;

void prime_numbers_using_sieve(int n){
  int arr[n] = {0};
  for(int i=2; i<=floor(sqrt(n)); i++){
    if(arr[i] == 0){
      for(int j=i*i; j<=n; j+=i){
        arr[j] = 1;
      }
    }
  }
  for(int i=2; i<n; i++){
    if(arr[i] == 0){
      cout<<i<<' ';
    }
  }
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;

  prime_numbers_using_sieve(n);

}