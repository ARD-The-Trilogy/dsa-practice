// link: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    string chooseandswap(string a)
    {
        // Code Here

        map<char, int> mp;
        for (int i = 0; i < a.size(); i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp.insert({a[i], i});
            }
        }

        for (auto it : mp)
        {
            char letter = it.first;
            int idx = it.second;

            int i = 0;
            while (i < a.length())
            {
                if (a[i] >= letter)
                {
                    break;
                }
                i++;
            }
            if (a[i] == letter)
            {
                continue;
            }
            else
            {
                char tar = a[i];

                for (int j = 0; j < a.length(); j++)
                {
                    if (a[j] == letter)
                        a[j] = '0';
                    else if (a[j] == tar)
                        a[j] = letter;
                }

                for (int j = 0; j < a.length(); j++)
                {
                    if (a[j] == '0')
                        a[j] = tar;
                }

                break;
            }
            // replace all this letter with this letter
        }

        // for (auto it : mp)
        // {
        //     cout << it.first << ' ' << it.second << endl;
        // }

        return a;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}
// } Driver Code Ends