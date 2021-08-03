/*
LINK: https://www.geeksforgeeks.org/all-unique-combinations-whose-sum-equals-to-k/

LINK: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1/?track=md-backtracking&batchId=144#

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to return a list of indexes denoting the required
    //combinations whose sum is equal to given number.
    set<vector<int>> arrays;
    vector<int> nums;

    void rec(vector<int> arr, vector<int> &A, int i, int rem)
    {
        // base condition
        if (rem == 0)
        {
            sort(arr.begin(), arr.end());
            arrays.insert(arr);
        }
        if (i < 0 || rem < 0)
            return;

        // or leave it
        rec(arr, A, i - 1, rem);

        // may have this sum
        arr.push_back(A[i]);
        rec(arr, A, i, rem - A[i]);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        set<int> st;
        for (auto it : A)
        {
            st.insert(it);
        }

        for (auto it : st)
        {
            nums.push_back(it);
        }

        rec({}, nums, nums.size() - 1, B);

        vector<vector<int>> ans;

        for (auto it : arrays)
        {
            ans.push_back(it);
        }

        return ans;
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
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
} // } Driver Code Ends