#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x, left = 0, right = 0;
    }
};

class Solution
{
public:
    vector<TreeNode *> path_p, path_q, tmp_path;

    void getPath(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void Solution::getPath(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (!root)
        return;

    // node address is pushed.
    tmp_path.push_back(root);

    if (root == p)
    {

        for (auto it : tmp_path)
        {
            path_p.push_back(it);
        }
    }
    if (root == q)
    {
        for (auto it : tmp_path)
        {
            path_q.push_back(it);
        }
    }

    getPath(root->left, p, q);
    getPath(root->right, p, q);

    // node address is popped.
    tmp_path.pop_back();
}

TreeNode *Solution ::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    // check if p and q doesn't exist
    // then the path_p, or path_q would be empty

    getPath(root, p, q);

    TreeNode *pre = 0;
    int lenp = path_p.size(), lenq = path_q.size();
    for (int i = 0; i < min(lenp, lenq); i++)
    {

        TreeNode *a = path_p[i], *b = path_q[i];
        if (a->val != b->val)
        {
            break;
        }

        pre = a;
    }

    return pre;
}
