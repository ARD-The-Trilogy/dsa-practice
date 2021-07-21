/*
LINK:
https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<long long> qu;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            qu.push(A[i]);
    }

    vector<long long> ans;
    if (!qu.empty())
        ans.push_back(qu.front());
    else
        ans.push_back(0);

    int end_ptr = 0;
    for (int i = K; i < N; i++)
    {
        if (A[i] < 0)
            qu.push(A[i]);
        if (A[end_ptr] == qu.front())
            qu.pop();

        if (!qu.empty())
            ans.push_back(qu.front());
        else
            ans.push_back(0);

        end_ptr++;
    }

    // for (auto it : ans)
    //     cout << it << ' ';
    // cout << endl;
    return ans;
}