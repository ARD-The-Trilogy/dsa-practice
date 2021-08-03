// LINK: https://www.geeksforgeeks.org/longest-common-prefix-using-trie/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    // without trie
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = "";
        int len = INT_MAX;
        for(int i=0;i<N;i++) {
            len = min(len, int(arr[i].length()));
        }
        
        for(int idx=0;idx<len;idx++) {
            int chr = arr[0][idx];
            int cnt = 0;
            for(int i=0;i<N;i++) {
                if(arr[i][idx] == chr) cnt++;
            }
            
            if(cnt !=  N) break;
            ans.push_back(chr);
            
        }
        
        if(ans.length() == 0) ans = "-1";
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        // your code here
        string ans = "";
        int len = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            len = min(len, int(arr[i].length()));
        }

        for (int idx = 0; idx < len; idx++)
        {
            int chr = arr[0][idx];
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (arr[i][idx] == chr)
                    cnt++;
            }

            if (cnt != N)
                break;
            ans.push_back(chr);
        }

        if (ans.length() == 0)
            ans = "-1";

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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends