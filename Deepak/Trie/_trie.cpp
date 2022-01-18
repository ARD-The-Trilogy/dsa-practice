#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct Node {
    // 26 pointers for children
    Node *children[26];
    int endCnt;
    char chr;
    Node(char c, int cnt) {
        chr = c;
        for(int i=0;i<26;i++) children[i] = NULL;
        endCnt = cnt;
    }
};

class Trie {
    private:
        Node *root;

    public:

        Trie(char c, int e) {
            root = new Node(c, e);
        }

    
    void insertTrie(string str) {
        Node *curr = root;
        for(int i=0;i<str.length();i++) {

            int idx = str[i] - 'a';
            if(curr->children[idx] == NULL) {
                // new node is created
                Node *tmp = new Node(str[i], 0);
                curr->children[idx] = tmp;
                curr = curr->children[idx];
            }
            else {
                // no new node is created
                curr = curr->children[idx];
            }

            if(i == str.length() - 1) {
                // if its the last one
                curr->endCnt++;
            }

        }
    }

    bool searchTrie(string str) {
        Node *curr = root;
        for(int i=0;i<str.length();i++) {
            int idx = str[i] - 'a';
            // find if idx is true in curr;
            if(curr->children[idx] == NULL) {
                return false;
            }
            
            curr = curr->children[idx];

            if(i == str.length() - 1 && curr->endCnt > 0) {
                return true;
            }

        }

        return false;
    }

    void printUtil(vector<string> &allStrings, string &s, Node *node) {
        if(node->endCnt > 0) {
            for(int i=0;i<node->endCnt;i++) 
                allStrings.push_back(s);
        }

        for(int i=0;i<26;i++) {
            if(node->children[i] != NULL) {
                s.push_back(char(i + 'a'));
                printUtil(allStrings, s, node->children[i]);
                s.pop_back();
            }
        }

    }

    void printAll() {
        string tmp;
        tmp.push_back(root->chr);
        // string tmp(root->chr);
        Node *curr = root;

        vector<string> allStr;

        printUtil(allStr, tmp, root);

        for(auto it:allStr) {
            cout << it << endl;
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    string str;

    cin >> n >> q;
    string arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    Trie tri('/', 1);

    for(int i=0;i<n;i++) {
        tri.insertTrie(arr[i]);
    }

    for(int i=0;i<q;i++) {
        cin >> str;
        cout << tri.searchTrie(str) << endl;
    }

}