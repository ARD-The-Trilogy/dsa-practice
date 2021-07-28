// LINK: https://www.geeksforgeeks.org/trie-insert-and-search/
// https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1#

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++)
        {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++)
            insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    TrieNode *curr = root;
    int len = key.length();
    for (int i = 0; i < len; i++)
    {
        int idx = key[i] - 'a';
        if (!curr->children[idx])
        {
            // then create a node first
            TrieNode *tmp = getNode();
            curr->children[idx] = tmp;
        }
        curr = curr->children[idx];
    }
    curr->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    // code here
    bool ans = false;
    TrieNode *curr = root;
    int len = key.length();
    for (int i = 0; i < len; i++)
    {
        int idx = key[i] - 'a';
        if (!curr->children[idx])
        {
            return false;
        }
        // if it is present
        curr = curr->children[idx];

        if (i == len - 1)
        {
            if (curr->isLeaf)
                return true;
            else
                return false;
        }
    }

    return false;
}