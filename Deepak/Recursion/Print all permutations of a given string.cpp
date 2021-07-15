// { Driver Code Starts

/*
LINK:
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

*/


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    set<string> st;
    vector<string> str_array;
    void strPermutations(string str, int len)
    {
        st.insert(str);

        for (int i = 0; i <= len; i++)
        {
            swap(str[i], str[len]);
            strPermutations(str, len - 1);
            swap(str[i], str[len]);
        }
    }

public:
    vector<string> find_permutation(string S)
    {
        // Code here there
        strPermutations(S, S.length() - 1);

        for (auto it : st)
        {
            str_array.push_back(it);
        }
        return str_array;
    }
};

class Solution2
{
public:
    void findPermutations(vector<string> &str_array, int *arr, string str, int len)
    {
        if (len == 0)
        {
            str_array.push_back(str);
        }

        for (int i = 0; i < 60; i++)
        {
            if (arr[i] > 0)
            {
                arr[i]--;
                findPermutations(str_array, arr, str + char('A' + i), len - 1);
                arr[i]++;
            }
        }
    }

    vector<string> find_permutation(string S)
    {
        // Code here there

        int cnt[60];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < S.length(); i++)
            cnt[S[i] - 'A']++;

        // for(int i=0;i<60;i++) cout << cnt[i] << endl;

        vector<string> str_array;
        int len = S.length();
        findPermutations(str_array, cnt, "", len);

        return str_array;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends