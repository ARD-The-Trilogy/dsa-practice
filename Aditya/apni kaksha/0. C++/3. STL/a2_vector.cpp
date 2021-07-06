#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v, int i){
  cout<<"Vector "<<i<<" : ";
  for (int x : v){
    cout << x << " ";
  }
  cout<<endl;
}
 
int main()
{
  // 1. Initializing by pushing values one by one :
    vector<int> vect1;
    vect1.push_back(10);
    vect1.push_back(20);
    printVector(vect1, 1);
    
  // 2. Specifying size and initializing all values :
    vector<int> vect2(5, 10);
    printVector(vect2, 2);

  // 3. Initializing like arrays :
    vector<int> vect3{ 10, 20, 30 };
    printVector(vect3, 3);

  // 4. Initializing from an array :
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect4(arr, arr + n);
    printVector(vect4, 4);

  // 5. Initializing from another vector :
    vector<int> vect{ 10, 20, 30 };
    vector<int> vect5(vect.begin(), vect.end());
    printVector(vect5, 5);

  // 6. Initializing all elements with a particular value :
    vector<int> vect6(5);
    int value = 5;
    fill(vect6.begin(), vect6.end(), value);
    printVector(vect6, 3);



    return 0;
}