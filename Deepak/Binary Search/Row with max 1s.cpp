// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    bool valid(int r, int c, int n, int m)
    {
        if (r < 0 || c < 0 || r > n - 1 || c > m - 1)
            return false;

        return true;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int i = 0, j = m - 1, maxi = 0, row_num = -1;

        for (int k = 0; k < m; k++)
        {
            if (arr[i][k])
            {
                j = k;
                row_num = 0;
                maxi = max(maxi, m - j);
                break;
            }
        }

        // cout << maxi << endl;

        while (valid(i, j, n, m))
        {

            if (arr[i][j - 1] == 1)
            {
                j--;
            }
            else
            {
                i++;
            }

            if (valid(i, j, n, m) && arr[i][j] == 1)
            {
                // answer is recorded
                int tmp = m - j;
                if (tmp > maxi)
                {
                    maxi = tmp;
                    row_num = i;
                }
            }
        }

        return row_num;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends