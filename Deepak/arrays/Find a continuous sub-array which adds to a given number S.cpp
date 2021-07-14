/*
LINK:
https://www.geeksforgeeks.org/find-subarray-with-given-sum/

INPUT:
N = 5, S = 12
A[] = {1,2,3,7,5}

OUTPUT:
 2 4

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    int i = 0, j = -1;
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here

        long long prefix[n];
        prefix[0] = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                continue;
            prefix[i] = arr[i] + prefix[i - 1];
        }

        long long i = 0, j = -1, tmp = -1;

        while ((i < n && j < n) && tmp != s)
        {
            tmp = prefix[i];
            if (j != -1)
                tmp -= prefix[j];

            if (tmp < s)
                i++;
            else if (tmp > s)
                j++;
        }

        vector<int> res;
        if (i == n || j == n)
            res.push_back(-1);
        else
        {
            res.push_back(j + 2);
            res.push_back(i + 1);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends