// LINK: https://www.geeksforgeeks.org/merge-k-sorted-arrays/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to merge k sorted arrays.
    int k = 0;

    vector<int> mergeUtil(vector<vector<int>> &arr, int up, int down)
    {
        if (up == down)
        {
            vector<int> vt;
            for (int i=0;i<k;i++)
            {
                vt.push_back(arr[up][i]);
            }

            return vt;
        }

        int mid = up + (down - up) / 2;
        auto arr1 = mergeUtil(arr, up, mid);
        auto arr2 = mergeUtil(arr, mid + 1, down);

        // now merge two arrays

        vector<int> ret_arr;
        int i = 0, j = 0, len1 = arr1.size(), len2 = arr2.size();

        while (i < len1 && j < len2)
        {
            if (arr1[i] < arr2[j])
            {
                ret_arr.push_back(arr1[i++]);
            }
            else
            {
                ret_arr.push_back(arr2[j++]);
            }
        }

        while (i < len1)
        {
            ret_arr.push_back(arr1[i++]);
        }
        while (j < len2)
        {
            ret_arr.push_back(arr2[j++]);
        }

        return ret_arr;
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        k = K;
        return mergeUtil(arr, 0, K - 1);
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
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends