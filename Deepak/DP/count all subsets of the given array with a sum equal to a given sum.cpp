/*
LINK: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int mod = 1e9 + 7;

    int dp(int arr[], int n, int sum)
    {
        int tab[n + 1][sum + 1];

        for (int item = 0; item <= n; item++)
        {
            for (int tot = 0; tot <= sum; tot++)
            {
                if (tot == 0)
                    tab[item][tot] = 1;
                else if (item == 0)
                    tab[item][tot] = 0;
                else if (tot < arr[item - 1])
                {
                    tab[item][tot] = tab[item - 1][tot];
                }
                else
                {
                    tab[item][tot] = tab[item - 1][tot] + tab[item - 1][tot - arr[item - 1]];
                }

                tab[item][tot] %= mod;
                cout << tab[item][tot] << ' ';
            }
            cout << endl;
        }

        return tab[n][sum];
    }

    int optimised(int arr[], int n, int sum)
    {
        int tab[sum + 1];
        int tmp[sum + 1];

        for (int item = 0; item <= n; item++)
        {
            for (int tot = 0; tot <= sum; tot++)
            {
                if (tot == 0)
                    tmp[tot] = 1;
                else if (item == 0)
                    tmp[tot] = 0;
                else if (tot < arr[item - 1])
                {
                    tmp[tot] = tab[tot];
                }
                else
                {
                    tmp[tot] = tab[tot] + tab[tot - arr[item - 1]];
                }

                tmp[tot] %= mod;
            }

            for (int i = 0; i <= sum; i++)
            {
                tab[i] = tmp[i];
            }
        }

        return tab[sum];
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        // cout << rec(arr, n, sum) << endl;
        // return dp(arr, n, sum);
        return optimised(arr, n, sum);
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
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}
// } Driver Code Ends