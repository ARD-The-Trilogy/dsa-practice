// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;
class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        ll ans = 0;
        for(int i=0;i<n;i++) {
            pq.push(arr[i]);
        }
        
        while (pq.size() > 1)
        {
            ll cost = pq.top();
            pq.pop();
            cost += pq.top();
            pq.pop();

            pq.push(cost);
            ans += cost;
        }

        return ans;
    }
};

// { Driver Code Starts.
long long minCost(long long arr[], long long n);
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
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends