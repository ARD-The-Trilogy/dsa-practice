// link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?problemStatus=unsolved&page=1&category[]=Binary%20Search&query=problemStatusunsolvedpage1category[]Binary%20Search#
// link: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;
struct compr
{

    bool operator()(const pair<int, int> &pr1, const pair<int, int> &pr2)
    {

        return pr1.second > pr2.second;
    }
};

class Solution
{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.

    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        int maxi = 0;
        vector<pii> vec;
        priority_queue<pii, vector<pii>, compr> pq;

        for (int i = 0; i < n; i++)
        {
            vec.push_back({arr[i], dep[i]});
        }

        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                pq.push(vec[i]);
            }
            else
            {

                // we will pop out till
                // the dep time is strictly less than
                // the start time of current

                while (!pq.empty() && pq.top().second < vec[i].first)
                {
                    // cout << pq.top().first << ' ' << pq.top().second << endl;
                    pq.pop();
                }

                pq.push(vec[i]);
            }

            maxi = max(maxi, int(pq.size()));
        }

        return maxi;
    }
};

// { Driver Code Starts.
// Driver code
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
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
} // } Driver Code Ends