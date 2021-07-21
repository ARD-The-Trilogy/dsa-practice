#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root);
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

vector<int> Solution::rightSideView(TreeNode *root)
{
    vector<int> nums;

    if (!root)
        return nums;

    queue<TreeNode *> qu;
    qu.push(root);
    qu.push(NULL);

    bool f1 = false;
    while (!qu.empty())
    {
        TreeNode *tmp = qu.front();
        qu.pop();

        if (tmp)
        {
            if (tmp->right)
                qu.push(tmp->right);
            if (tmp->left)
                qu.push(tmp->left);

            if (!f1)
            {
                nums.push_back(tmp->val);
                f1 = true;
            }
        }
        else if (!qu.empty())
        {
            qu.push(NULL);
            f1 = false;
        }
    }

    return nums;
}
