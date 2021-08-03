/*
LINK: https://practice.geeksforgeeks.org/problems/top-k-numbers3425/1#

LINK: https://www.geeksforgeeks.org/find-top-k-or-most-frequent-numbers-in-a-stream/
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

typedef pair<int, int> pii;
struct compr
{
    bool operator()(const pii &obj1, const pii &obj2)
    {
        if (obj1.second == obj2.second)
            return obj1.first < obj2.first;

        return obj1.second > obj2.second;
    }
};

class Solution
{
public:
    vector<int> kTop(int a[], int n, int k)
    {
        //code here.
        map<int, int> hash_int;
        vector<int> fin_arr;
        for (int i = 0; i < n; i++)
        {
            int num = a[i];
            hash_int[num]++;

            vector<pii> nums;
            for (auto it : hash_int)
            {
                nums.push_back(it);
            }

            sort(nums.begin(), nums.end(), compr());
            for (int i = 0; i < min(k, int(nums.size())); i++)
            {
                fin_arr.push_back(nums[i].first);
            }
        }

        return fin_arr;
    }
};

// { Driver Code Starts.

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
        long long k;
        cin >> n;
        cin >> k;
        int a[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<int> ans;
        ans = ob.kTop(a, n, k);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
// } Driver Code Ends