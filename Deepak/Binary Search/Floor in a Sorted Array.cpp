// link: https://www.geeksforgeeks.org/floor-in-a-sorted-array/

// link: https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find

    int search(vector<long long> arr, int l, int h, int key)
    {

        // base case
        if (l > h)
            return h;

        int mid = (l + h) / 2;

        if(arr[mid] == key)
        return mid;
        
        if (key < arr[mid])
            return search(arr, l, mid - 1, key);

        else if (key > arr[mid])
            return search(arr, mid + 1, h, key);
    }

    int findFloor(vector<long long> v, long long n, long long x)
    {

        // Your code here
        int num = search(v, 0, n-1, x);
        // cout << num << endl;
        if(num != -1 && v[num] > x) num--;

        return num;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
} // } Driver Code Ends