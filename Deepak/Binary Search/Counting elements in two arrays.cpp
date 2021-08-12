// link: https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1/?problemStatus=unsolved&page=1&category[]=Binary%20Search&query=problemStatusunsolvedpage1category[]Binary%20Search#
// link: https://www.geeksforgeeks.org/element-1st-array-count-elements-less-equal-2nd-array/
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution
{
public:
    int bsearch(int *arr2, int l, int h, int key)
    {

        if (l > h)
            return h;

        int mid = l + (h - l) / 2;

        // cout << l << ' '<< h << endl;

        if (arr2[mid] <= key)
            return bsearch(arr2, mid + 1, h, key);

        if (arr2[mid] > key)
            return bsearch(arr2, l, mid - 1, key);
    }

    int iter(int *arr2, int n, int key) {
        int l = 0, h = n-1, res = -1;

        while(l <= h) {

            int mid = (l + h)/2;

            if(arr2[mid] <= key) {
                res = mid, l = mid+1;
            }
            else if(arr2[mid] > key) {
                h = mid-1;
            }

        }

        return res;
    }

    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],
                                        int m, int n)
    {
        //Your code goes here
        // if index if -1 that means no element
        vector<int> answer;

        sort(arr2, arr2 + n);

        for (int i = 0; i < m; i++)
        {
            // int idx = bsearch(arr2, 0, n - 1, arr1[i]);
            int idx = iter(arr2, n, arr1[i]);

            // cout << idx << endl;

            answer.push_back(idx + 1);
        }

        return answer;
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
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        for (int j = 0; j < n; j++)
            cin >> arr2[j];
        Solution obj;
        vector<int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }
    return 0;
} // } Driver Code Ends