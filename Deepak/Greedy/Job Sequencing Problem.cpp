// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

struct reOrder
{
    bool operator()(const Job &obj1, Job &obj2)
    {
        return obj1.profit > obj2.profit;
    }
};

class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int cnt = 0, tot = 0;

        int deadl = 100;
        bool vis[101] = {0};

        sort(arr, arr + n, reOrder());

        for (int i = 0; i < n; i++)
        {
            int d = arr[i].dead, p = arr[i].profit;

            while (d)
            {
                if (vis[d] == 0)
                {
                    vis[d] = true;
                    cnt++, tot += p;
                    break;
                }

                d--;
            }

            if (cnt == 100 || cnt == n)
                break;
        }

        return {cnt, tot};
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends