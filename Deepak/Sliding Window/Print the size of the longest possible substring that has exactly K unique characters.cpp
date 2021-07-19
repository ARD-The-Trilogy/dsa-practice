/*

LINK:
https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/

Input:
2
aabacbebebe 3
aaaa 2

OUTPUT:
7
-1


*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here

        // arr stores the count of occurences
        int arr[26];
        for (int i = 0; i < 26; i++)
            arr[i] = 0;

        int uni = 0, end_ptr = 0, max_len = -1;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            // if already reached size k and its unique;
            if (arr[idx] == 0 && uni == k)
            {
                int cnt = 0;
                for (int i = 0; i < 26; i++)
                    cnt += arr[i];

                if (cnt != 0)
                    max_len = max(max_len, cnt);

                // we cant accept this character.
                // we first need to empty characters such that
                while (uni == k)
                {
                    int idx2 = s[end_ptr] - 'a';
                    if (arr[idx2] == 1)
                    {
                        uni--;
                    }
                    arr[idx2]--, end_ptr++;
                }
                // the uniques reduce to size k-1;
            }

            if (arr[idx] == 0)
                uni++;

            // increment the visit;
            arr[idx]++;
        }

        if (uni == k)
        {
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                cnt += arr[i];

            if (cnt != 0)
                max_len = max(max_len, cnt);
        }

        return max_len;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
// } Driver Code Ends