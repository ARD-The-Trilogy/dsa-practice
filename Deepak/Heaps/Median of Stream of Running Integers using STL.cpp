// LINK: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to insert heap.
    priority_queue<int> first_half;
    priority_queue<int, vector<int>, greater<int>> second_half;
    void insertHeap(int &x)
    {
        if (first_half.size() > second_half.size())
        {
            first_half.push(x);
            int tmp = first_half.top();
            first_half.pop();

            second_half.push(tmp);
        }
        else
        {
            second_half.push(x);
            int tmp = second_half.top();
            second_half.pop();

            first_half.push(tmp);
        }
    }

    //Function to balance heaps.
    // void balanceHeaps()
    // {
    // }

    //Function to return Median.
    double getMedian()
    {
        double ans = 0;
        if (first_half.size() > second_half.size())
        {
            ans = first_half.top();
        }
        else
        {
            ans = (first_half.top() + second_half.top() * 1.0) / 2.0;
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

    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends