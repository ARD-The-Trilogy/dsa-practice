
#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct TrieNode
{
    int wt;
    char chr;
    TrieNode *next[26];
    // TrieNode(char c) : chr(c) {}
    TrieNode(char c)
    {
        wt = 0;
        chr = c;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

TrieNode *root = new TrieNode('/');

void printTrie(TrieNode *curr, string &str)
{
    char ch = curr->chr;

    if (ch != '/')
        str.push_back(ch);

    if (curr->wt > 0)
    {
        // print this string
        for (auto it : str)
            cout << it;
        cout << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        if (curr->next[i])
            printTrie(curr->next[i], str);
    }

    str.pop_back();
}

bool searchTrie(TrieNode *root, string str)
{
    char ans = '-'; // -, 1, 0;

    // search till the answer is not known

    TrieNode *curr = root;
    int idx = str[0] - 'a';
    int i = 0, len = str.length();
    while (ans == '-' && i < len)
    {
        int idx = str[i] - 'a';
        if (!curr->next[idx])
        {
            ans = '0';
            break;
        }

        curr = curr->next[idx];

        if (i == len - 1)
        {
            // last node
            if (curr->wt < 1)
            {
                ans = '0';
            }
            else
            {
                ans = '1';
            }
        }

        i++;
    }

    if (ans != '-')
        return ans - '0';
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string str, srch;
    vector<string> str_arr;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str_arr.push_back(str);
    }
    cin >> srch;

    for (int i = 0; i < n; i++)
    {

        TrieNode *curr = root;
        int len = str_arr[i].size();
        for (int j = 0; j < len; j++)
        {
            int idx = str_arr[i][j] - 'a';
            if (!curr->next[idx])
            {
                // then create it
                TrieNode *tmp = new TrieNode(str_arr[i][j]);
                curr->next[idx] = tmp;
            }

            curr = curr->next[idx];
        }
        curr->wt++;
        cout << "inc";
    }

    string tmp = "";
    printTrie(root, tmp);
    cout << endl;
    cout << searchTrie(root, srch);
}
