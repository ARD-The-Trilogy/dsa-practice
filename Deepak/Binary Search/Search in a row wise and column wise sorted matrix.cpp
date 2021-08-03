// link: https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#
// link: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    bool isValid(int r, int c, int N, int M)
    {
        if (r < 0 || c < 0 || r > N - 1 || c > M - 1)
            return false;

        return true;
    }

    int matSearch(vector<vector<int>> &mat, int N, int M, int X)
    {
        // your code here

        int i = 0, j = M - 1;
        while (isValid(i, j, N, M))
        {

            if (mat[i][j] == X)
                return true;
            else if (mat[i][j] < X)
                i++;
            else
                j--;
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int x;
        cin >> x;
        Solution ob;
        cout << ob.matSearch(arr, n, m, x) << endl;
    }
} // } Driver Code Ends