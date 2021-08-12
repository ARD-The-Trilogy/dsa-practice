// link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

struct reOrder
{
    bool operator()(const Item &obj1, const Item &obj2)
    {
        return (double(obj1.value) / obj1.weight) > (double(obj2.value) / obj2.weight);
    }
};

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, reOrder());

        double ans = 0.0;
        int i = 0, wt_sofar = 0;

        for (int i = 0; i < n; i++)
        {
            if (wt_sofar + arr[i].weight <= W)
            {
                ans += arr[i].value;
                wt_sofar += arr[i].weight;
            }
            else
            {
                int fra = W - wt_sofar;
                double tmp = arr[i].value * (double(fra) / arr[i].weight);
                ans += tmp;
                break;
            }
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
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends