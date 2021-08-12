/*
LINK:
https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/


 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4


*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;

class Solution
{
public:
    //Function to find the smallest positive number missing from the array.

    // Method 1 O(N) space
    // int missingNumber(int arr[], int n)
    // {
    //     // Your code here
    //     bool visited[n + 2];
    //     memset(visited, 0, sizeof visited);

    //     int mini = 1e7;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] > 0)
    //         {
    //             mini = min(mini, arr[i]);
    //             visited[arr[i]] = true;
    //         }
    //     }

    //     for (int i = mini;; i++)
    //     {

    //         if (visited[i] == false)
    //             return i;
    //     }
    // }

    bool isValid(int num, int n)
    {
        if (num < 1 || num > n)
            return false;
        return true;
    }
    int missingNumber(int arr[], int n)
    {
        // Your code here
        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            for (; isValid(num, n) && arr[num - 1] != num;)
            {
                int tmp = arr[num - 1];
                arr[num - 1] = num;

                num = tmp;
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            // cout << arr[i - 1] << ' ';
            if (arr[i - 1] != i)
            {
                ans = min(ans, i);
            }
        }

        if (ans == INT_MAX)
            ans = n + 1;
        return ans;
    }
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        //input number n
        int n;
        cin >> n;
        int arr[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        //calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends