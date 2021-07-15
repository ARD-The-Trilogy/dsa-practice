/*
LINK: 
https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        //code here
        map<int, int> mp;
        int ret = 1e7;
        for (int i = 0; i < n; i++)
        {
            auto fpr = mp.find(arr[i]);
            if (fpr != mp.end())
            {
                ret = min(ret, mp[arr[i]] + 1);
            }
            mp.insert({arr[i], i});
        }

        if (ret == 1e7)
            ret = -1;
        return ret;
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

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends