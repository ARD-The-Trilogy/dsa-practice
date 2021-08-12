// link: https://practice.geeksforgeeks.org/problems/square-root/1/?problemStatus=unsolved&page=1&category[]=Binary%20Search&query=problemStatusunsolvedpage1category[]Binary%20Search#
// link: https://www.geeksforgeeks.org/square-root-of-an-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long bsearch(long long x)
    {
        int l = 1, h = 1e4;
        long long res = -1;

        while (l <= h)
        {


            cout << l << ' ' << r << end;
            
            int mid = l + (h - l) / 2;

            if (mid * mid == x)
            {
                return mid;
            }

            else if (mid * mid < x)
            {
                res = mid, l = mid + 1;
            }
            else if (mid * mid > x)
            {
                h = mid - 1;
            }
        }

        return res;
    }

    long long int floorSqrt(long long int x)
    {
        // Your code goes here

        return bsearch(x);
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
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}
// } Driver Code Ends