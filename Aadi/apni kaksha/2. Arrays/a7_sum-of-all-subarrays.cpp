#include <bits/stdc++.h>
using namespace std;

void sum_of_all_subarrays(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int subarraySum = 0;
    for (int j = i; j < n; j++)
    {
      subarraySum += arr[j];
      cout << subarraySum << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter length of array: ";
  cin >> n;
  int a[n];
  cout << "Enter array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sum_of_all_subarrays(a, n);

  return 0;
}