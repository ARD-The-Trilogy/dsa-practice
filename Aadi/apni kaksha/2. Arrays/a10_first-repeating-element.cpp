#include <bits/stdc++.h>
using namespace std;

void first_repeating_element(int arr[], int n) {
  int index_arr[10^6];
  memset(index_arr, -1, sizeof(index_arr));
  int imin = INT_MAX;
  for(int i=0; i<n; i++){
    if(index_arr[arr[i]] != -1)
      imin = min(imin, index_arr[arr[i]]);
    index_arr[arr[i]] = i;
  }
  if(imin < INT_MAX)
    cout<<imin;
  else
    cout<<"No repeating element";
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  int a[n];
  cout << "Enter array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  first_repeating_element(a, n);

  return 0;
}