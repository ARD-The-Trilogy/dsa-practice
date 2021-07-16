// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    int mod = 1e9 + 7;
    int rec(int n)
    {
        if (n == 0)
            return 1;
        
        if(n < 0) return 0;



        // code here
        long long sing = rec(n - 1);
        long long pairs = (n - 1) * rec(n - 2);

        return sing + pairs;
    }
    // DP solution
    int countFriendsPairings(int n) {
        long long memo[n+1];
        memo[0] = 1, memo[1] = 1;
        for(int i=2;i<=n;i++) {
            memo[i] = (memo[i-1] % mod + ((i-1) * memo[i-2])%mod) % mod;
        }
        return memo[n];
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends