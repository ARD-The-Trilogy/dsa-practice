// link:  https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1/?track=md-greedy&batchId=144

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minCost(int *candies, int n, int k)
    {
        int mini = 0;
        int tot = n / (k + 1);
        if (tot * (k + 1) < n)
            tot++;

        mini = accumulate(candies, candies + tot, 0);

        return mini;
    }

    int maxCost(int *candies, int n, int k)
    {
        int maxi = 0;
        int tot = n / (k + 1);
        if (tot * (k + 1) < n)
            tot++;

        // cout << tot << endl;

        maxi = accumulate(candies, candies + tot, 0);

        return maxi;
    }

    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies + N);
        int mini = minCost(candies, N, K);

        sort(candies, candies + N, greater<int>());
        int maxi = maxCost(candies, N, K);

        return {mini, maxi};
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
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends