#include <bits/stdc++.h>
using namespace std;

void subarray_with_given_sum(int arr[], int n, int sum) {
  int s = 0;
  int e = 0;
  cout<<s<<' '<<e<<endl;
  int curr_sum = arr[0];
  cout<<curr_sum<<' '<<sum<<' '<<n<<endl;
  while(curr_sum != sum && s<n && e<n){
    if(curr_sum < sum){
      e++;
      curr_sum += arr[e];
      cout<<curr_sum<<' ';
    }
    else{
      curr_sum -= arr[s];
      s++;
      cout<<' '<<curr_sum<<' ';
    }
  }
  if(curr_sum == sum){
    cout<<endl<<s<<' '<<e;
  }
  else{
    cout<<endl<<"No such subarray";
  }
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
  int sum;
  cout<<"Enter target sum: ";
  cin>>sum;

  subarray_with_given_sum(a, n, sum);

  return 0;
}