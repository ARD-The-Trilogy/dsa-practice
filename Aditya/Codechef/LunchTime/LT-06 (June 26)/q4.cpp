#include <bits/stdc++.h>
using namespace std;
 
void bin(unsigned n, stack<int> *st)
{
  if (n > 1){
    bin(n / 2, st);
  }
  // cout << n % 2;
  *st.push(n%2);
}

string bin_str(unsigned n){
  string s;
  stack<int> st;
  bin(n, &st);
  while(!st.empty()) {
    cout<<st.top();
    s.push_back(st.top());
    st.pop();
  }
  cout<<s;
  return s;
}
 
int main() {
  // int t;
  // cout<<"Enter t: ";
  // cin>>t;
  // while(t--){
  //   int n;
  //   cin>>n;
  //   int a[n];
  //   string bin_arr[n];
  //   for(int i=0; i<n; i++){
  //     cin>>a[i];
  //     bin_arr[i] = bin_str(a[i]);
  //     cout<<bin_str(a[i])<<endl;
  //   }
  // }

  cout<<bin_str(7)<<endl;

  return 0;
}
 