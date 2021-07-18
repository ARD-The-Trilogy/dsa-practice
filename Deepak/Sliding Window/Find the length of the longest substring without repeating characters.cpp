/*
LINK:
https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        //code

        int tot = 0, len = S.length(), maxi = -1e9;
        int arr[26];
        for (int i = 0; i < 26; i++)
            arr[i] = -1;

        for (int i = 0; i < len; i++)
        {
            int idx = S[i] - 'a';

            if (arr[idx] == -1)
            {
                tot++;
            }
            else
            {

                int del = arr[idx];
                // delete everything before and equal to del;
                for (int j = 0; j < 26; j++)
                {
                    if (arr[j] <= del && arr[j] > -1)
                    {
                        arr[j] = -1;
                        tot--;
                    }
                }
                tot++;

                // setting the new idx for current character.
            }
            arr[idx] = i;
            // cout << "tot: " << S[i] << ' ' << arr[idx] << endl;
            // cout << "tot: " << S[i] << ' ' << tot << endl;
            maxi = max(maxi, tot);
        }

        return maxi;
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
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
} // } Driver Code Ends