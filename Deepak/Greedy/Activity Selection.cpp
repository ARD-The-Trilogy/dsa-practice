// link: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/?track=md-greedy&batchId=144#

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;

class Solution
{
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pii> tasks;
        for (int i = 0; i < n; i++)
        {
            pii tmp;
            tmp.second = start[i], tmp.first = end[i];
            tasks.push_back(tmp);
        }


        sort(tasks.begin(), tasks.end());


        int tot = 0, pre = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (tasks[i].second > pre)
            {
                tot++;
                pre = tasks[i].first;
            }
        }

        return tot;
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

    //testcases
    cin >> t;
    while (t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
// } Driver Code Ends