/*

LINK:
https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        // code here
        int maxi = 0, sum = 0;
        for (int i = 0; i < K; i++)
        {
            maxi += Arr[i];
            sum += Arr[i];
        }

        int end = 0;
        for (int i = K; i < N; i++)
        {
            sum += Arr[i];
            sum -= Arr[end];
            end++;

            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        ;
        vector<int> Arr;
        for (int i = 0; i < N; ++i)
        {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
} // } Driver Code Ends