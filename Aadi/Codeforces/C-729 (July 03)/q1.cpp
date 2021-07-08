#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  // cout<<"Enter t: ";
  cin>>t;
  while(t--){
    int n;
    // cout<<"Enter n: ";
    cin>>n;

    int N = 2*n;
    int a[N];
    int even = 0, odd = 0;
    for(int i=0; i < N; i++){
      cin>>a[i];
      if(a[i] % 2 == 0){
        even++;
      }
      else{
        odd++;
      }
    }

    if(even == odd){
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
    
  }
  return 0;
}