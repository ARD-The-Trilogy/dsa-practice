#include <bits/stdc++.h>
using namespace std;

void maximum_subarray_sum(int arr[], int n) {
  int curr_sum = 0;
  int max_sum = 0;
  for(int i=0; i<n; i++){
    if(curr_sum + arr[i] >= 0){
      curr_sum += arr[i];
    }
    else{
      curr_sum = 0;       // wrong -> corrected below
    }   // https://leetcode.com/problems/maximum-subarray/submissions/
    max_sum = max(max_sum, curr_sum);
  }
  cout<<max_sum;
}

int main() {
  int n;
  cout << "Enter length of array: ";
  cin >> n;
  int a[n];
  cout << "Enter array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  maximum_subarray_sum(a, n);

  return 0;
}