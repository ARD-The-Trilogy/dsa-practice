// link: https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1/?problemStatus=unsolved&page=1&category[]=Binary%20Search&query=problemStatusunsolvedpage1category[]Binary%20Search#
// link: https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the minimum element in sorted and rotated array.

    int bsearch(int *arr, int low, int high)
    {
        int res = -1;

        while (low <= high)
        {

            // cout << low << ' ' << high << endl;
            
            int mid = (high + low) / 2;

            if (mid > low && mid < high && arr[mid] < min(arr[mid - 1], arr[mid + 1]))
            {
                return mid;
            }

            else if (low == high)
                return low;

            else if (high - low == 1)
            {
                if (arr[high] > arr[low])
                    res = low;
                else if (arr[low] > arr[high])
                    res = high;

                break;
            }

            else if (arr[mid] < arr[high])
            {
                res = mid, high = mid;
            }
            else if (arr[mid] > arr[high])
            {
                low = mid + 1;
            }
        }

        return res;
    }

    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int idx = bsearch(arr, low, high);
        return arr[idx];

    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution obj;
        cout << obj.minNumber(a, 0, n - 1) << endl;
    }
    return 0;
} // } Driver Code Ends