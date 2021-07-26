// LINK: https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ret_arr;

        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else if (pq.size() == k && pq.top() < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }

            if (pq.size() < k)
                ret_arr.push_back(-1);
            else
                ret_arr.push_back(pq.top());
        }

        return ret_arr;
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
        int k, n;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends