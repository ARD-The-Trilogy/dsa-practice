/*
LINK: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

LINK: https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        int hash_car[26];
        for (int i = 0; i < 26; i++)
            hash_car[i] = -1;

        queue<char> qu;
        string ans = "";

        for (int i = 0; i < A.size(); i++)
        {
            char chr = A[i];
            // push the possible candiate

            hash_car[chr - 'a']++;

            if (hash_car[chr - 'a'] == 0)
            {
                qu.push(chr);
            }

            while (!qu.empty() && hash_car[qu.front() - 'a'] > 0)
            {
                qu.pop();
            }

            if (qu.empty())
                ans += '#';
            else
            {
                ans += qu.front();
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends