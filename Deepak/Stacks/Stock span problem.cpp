// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;
class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<pii> stk;
        stk.push({price[0], 1});

        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < n; i++)
        {
            int tot = 1;

            while (!stk.empty() && price[i] >= stk.top().first)
            {
                tot += stk.top().second;
                stk.pop();
            }

            stk.push({price[i], tot});
            ans.push_back(tot);
        }

        return ans;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends