/*
LINK: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

LINK: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int arr[], int n)
    {
        // coode here
        int l = 0, md = 0, hg = n - 1;
        while (md <= hg)
        {
            if (arr[md] == 0)
            {
                swap(arr[l], arr[md]);
                l++, md++;
            }
            else if (arr[md] == 1)
                md++;
            else if (arr[md] == 2)
            {
                swap(arr[md], arr[hg]);
                hg--;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends