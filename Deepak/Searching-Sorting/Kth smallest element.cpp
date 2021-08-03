// LINK: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        //code here

        int size = 1e5 + 1;
        int hash[size];
        for (int i = 0; i < size; i++)
            hash[i] = 0;

        for(int i=l;i<=r;i++) {
            int num = arr[i];
            hash[num]++;
        }

        int pre = 0, i = 1;
        while (i <= size && pre + hash[i] < k)
        {
            pre += hash[i++];
            // cout << pre << ' ' << hash[i] << endl;
        }

        return i;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends