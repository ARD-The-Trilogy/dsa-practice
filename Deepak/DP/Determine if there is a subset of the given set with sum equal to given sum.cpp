/*
LINK: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1#

LINK: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here
        vector<vector<bool>> tab(N + 1, vector<bool>(sum + 1, 0));
        for (int i = 0; i <= N; i++)
        {
            for (int tot = 0; tot <= sum; tot++)
            {
                if (tot == 0)
                    tab[i][tot] = true;
                else if (i == 0)
                    tab[i][tot] = false;
                else if (tot < arr[i - 1])
                {
                    tab[i][tot] = tab[i - 1][tot];
                }
                else
                {
                    tab[i][tot] = tab[i - 1][tot] || tab[i - 1][tot - arr[i - 1]];
                }
            }
        }

        return tab[N][sum];
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
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends