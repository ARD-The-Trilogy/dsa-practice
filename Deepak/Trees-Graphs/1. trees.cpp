#include <bits/stdc++.h>
#define endl '\n'
#define fast        \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
using namespace std;
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repi(i, l, r) for (int i = l; i <= r; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef set<int> si;
typedef set<ll> sl;
typedef map<int, int> mii;
typedef map<char, int> mci;

struct node
{
    int data, height;
    node *left, *right;
    node(int val, node *le, node *ri) : data(val), left(le), right(ri), height(-1) {}
};

node *root;

void makeTree();

void preOrderRec(node *temp)
{
    if (temp)
    {
        cout << temp->data << ' ';
        preOrderRec(temp->left);
        preOrderRec(temp->right);
    }
}

void preOrderIterative()
{
    stack<node *> stk; // for storing nodes addreses;

    stk.push(root);
    while (!stk.empty())
    {
        node *temp = stk.top();
        stk.pop();
        cout << temp->data << ' ';
        if (temp->right)
            stk.push(temp->right);
        if (temp->left)
            stk.push(temp->left);
    }
    cout << endl;
}

void inOrderRec(node *temp)
{
    if (temp)
    {
        inOrderRec(temp->left);
        cout << temp->data << ' ';
        inOrderRec(temp->right);
    }
}

void levOrder()
{
    queue<node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();
        cout << temp->data << ' ';

        if (temp->left)
            qu.push(temp->left);
        if (temp->right)
            qu.push(temp->right);
    }
    cout << endl;
}

void inOrderIterative()
{
    stack<node *> stk;
    stk.push(root);
    stack<int> nums;

    while (!stk.empty())
    {
        node *temp = stk.top();
        stk.pop();

        if (temp->right)
        {
            stk.push(temp->right);
        }

        if (temp->left)
        {
            stk.push(temp->left);
        }
        else
        {
            cout << temp->data << ' ';
            stk.pop();
            if (temp->right)
                stk.push(temp->right);
        }
    }
}

map<int, vector<int>> mp;
void diagnoalSub(node *root, int lev)
{
    if (!root)
        return;
    auto ptr = mp.find(lev);
    if (ptr == mp.end())
    {
        mp.insert({lev, {root->data}});
    }
    else
    {
        mp[lev].push_back(root->data);
    }

    diagnoalSub(root->left, lev + 1);
    diagnoalSub(root->right, lev);
}

void diagnoalTraversal()
{
    mp.clear();
    diagnoalSub(root, 0);
    for (auto it : mp)
    {
        cout << it.first << '-';
        for (auto kt : it.second)
            cout << kt << ' ';
        cout << endl;
    }
    cout << endl;
}

int getHeight(node *root)
{
    if (!root)
        return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int height(node *root)
{
    if (!root)
        return -1;

    root->height = 1 + max(height(root->left), height(root->right));
    return root->height;
}

void showHeights(node *root)
{
    if (!root)
        return;

    cout << root->data << ' ' << root->height << endl;
    showHeights(root->left);
    showHeights(root->right);
}

int isTreeBalanced(node *root)
{
    if (!root)
        return 1;

    // if both children exist
    int ret = 1;
    if (root->left && root->right)
    {
        if (abs(root->left->height - root->right->height) > 1)
            return 0;
    }
    else if (root->height > 1)
    {
        return 0;
    }

    return 1 && isTreeBalanced(root->left) && isTreeBalanced(root->right);
}

int diameterTree(node *root, int &dia)
{
    if (!root)
        return 0;

    root->height = 1 + max(diameterTree(root->left, dia),
                           diameterTree(root->right, dia));

    int tmp = root->height - 1;

    if (root->left && root->right)
    {
        tmp = max(tmp, root->left->height + root->right->height);
    }

    // cout << root->data << ' ' << tmp << endl;
    dia = max(tmp, dia);
    return root->height;
}

map<int, int> lview;
void leftView(node *root, int lev)
{
    if (!root)
        return;

    if (lview.find(lev) == lview.end())
    {
        lview.insert({lev, root->data});
    }

    leftView(root->left, lev + 1);
    leftView(root->right, lev + 1);
}

void leftViewPrint()
{
    leftView(root, 0);
    for (auto it : lview)
    {
        cout << it.second << ' ';
    }
    cout << endl;
}

map<int, int> rview;
void rightView(node *root, int lev)
{
    if (!root)
        return;

    if (rview.find(lev) == rview.end())
    {
        rview.insert({lev, root->data});
    }

    rightView(root->right, lev + 1);
    rightView(root->left, lev + 1);
}

void rightViewPrint()
{
    rightView(root, 0);
    for (auto it : rview)
    {
        cout << it.second << ' ';
    }
    cout << endl;
}

void rightViewLev()
{
    int isFirst = true;
    vector<int> nums;
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {

        while (qu.front() != NULL)
        {
            node *tmp = qu.front();
            qu.pop();
            if (isFirst)
            {
                nums.push_back(tmp->data);
                isFirst = false;
            }
            if (tmp->left)
                qu.push(tmp->left);
            if (tmp->right)
                qu.push(tmp->right);
        }
        qu.pop();
        isFirst = true;

        if (!qu.empty())
            qu.push(NULL);
    }
    for (auto it : nums)
        cout << it << ' ';
    // cout << nums.size();
    cout << endl;
}

void topView()
{
    queue<pair<node *, int>> qu;
    // b & f denotes the width wise distance from root;
    int b = 0, f = 0;
    qu.push({root, 0});
    map<int, int> tView;
    while (!qu.empty())
    {
        pair<node *, int> tmp = qu.front();
        qu.pop();
        int da = tmp.first->data, lev = tmp.second;

        if (tView.find(lev) == tView.end())
        {
            tView.insert({lev, da});
        }

        if (tmp.first->left)
        {
            qu.push({tmp.first->left, lev - 1});
        }
        if (tmp.first->right)
        {
            qu.push({tmp.first->right, lev + 1});
        }
    }

    for (auto it : tView)
    {
        cout << it.second << ' ';
    }
    cout << endl;
}

void bottomView()
{
    queue<pair<node *, int>> qu;
    map<int, int> bView;
    qu.push({root, 0});
    bView.insert({0, root->data});

    while (!qu.empty())
    {
        pair<node *, int> tmp = qu.front();
        qu.pop();
        int lev = tmp.second;

        bView[lev] = tmp.first->data;

        if (tmp.first->left)
        {
            qu.push({tmp.first->left, lev - 1});
        }
        if (tmp.first->right)
        {
            qu.push({tmp.first->right, lev + 1});
        }
    }
    for (auto it : bView)
    {
        cout << it.second << ' ';
    }
    cout << endl;
}

// void leftBoundary(node *root, stack<node*> &stk) {
//     if(root->left) {
//         stk.push(root->left);
//         leftBoundary(root->left, )
//     }
//
// }
// void boundaryTraversal() {
//     stack<node*> stk;
//     vector<int> nums;
//
//     leftBoundary(root, stk);
//
//
// }

void subrtl(vector<vector<int>> &vt, vector<int> &tmp, node *root)
{
    if (!root)
        return;

    tmp.push_back(root->data);
    if (!root->left && !root->right)
    {
        vt.push_back(tmp);
    }

    subrtl(vt, tmp, root->left);
    subrtl(vt, tmp, root->right);
    tmp.pop_back();
}
void rootToLeaves()
{
    vector<vector<int>> vt;
    vector<int> tmp;
    subrtl(vt, tmp, root);

    for (auto it : vt)
    {
        for (auto kt : it)
        {
            cout << kt << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void subrtlSum(node *root, vector<int> &vt, int sum, bool &f1, int key)
{
    if (!root)
        return;

    sum += root->data;
    if (!root->left && !root->right)
    {
        vt.push_back(sum);
    }
    if (!root->left && !root->right && sum == key)
    {
        f1 |= true;
        return;
    }

    subrtlSum(root->left, vt, sum, f1, key);
    subrtlSum(root->right, vt, sum, f1, key);
}
bool rootToLeavesSum(int key)
{
    bool f1 = false;
    vector<int> vt;
    subrtlSum(root, vt, 0, f1, key);

    for (auto it : vt)
        cout << it << ' ';
    cout << endl;
    return f1;
}

int subkn(node *root, int lev, int k)
{
    if (!root)
        return 0;
    if (lev == k)
        return 1;

    int ret = 0;
    ret += subkn(root->left, lev + 1, k);
    ret += subkn(root->right, lev + 1, k);

    return ret;
}
int kthNodeFromRoot(int k)
{
    return subkn(root, 0, k);
}

bool subsymm(node *node1, node *node2)
{
    if (!node1 && !node2)
        return true;
    if (!(node1 && node2))
        return false;
    if (node1->data != node2->data)
        return false;

    return subsymm(node1->left, node2->left) && subsymm(node1->right, node2->right);
}
void symmetricTree()
{
    cout << subsymm(root->left, root->right) << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    makeTree();
    preOrderRec(root);
    cout << endl;
    preOrderIterative();

    levOrder();
    inOrderRec(root);
    cout << endl;

    // inOrderIterative();

    // diagnoalTraversal();

    // cout << getHeight(root) << endl;

    height(root);
    // showHeights(root);
    // cout << isTreeBalanced(root) << endl;

    int diameter = 0;
    diameterTree(root, diameter);
    cout << diameter << endl;

    // leftViewPrint();
    // rightViewPrint();
    // rightViewLev();

    // topView();
    // bottomView();

    // rootToLeaves();
    // cout << rootToLeavesSum(57);
    // cout << kthNodeFromRoot(9);
    symmetricTree();
}

void makeTree()
{
    node *node1 = new node(1, 0, 0);
    node *node2 = new node(2, 0, 0);
    node *node3 = new node(3, 0, 0);
    node *node4 = new node(4, 0, 0);
    node *node5 = new node(5, 0, 0);
    node *node6 = new node(6, 0, 0);
    node *node7 = new node(7, 0, 0);
    node *node8 = new node(8, 0, 0);
    node *node9 = new node(9, 0, 0);
    node *node10 = new node(10, 0, 0);
    node *node11 = new node(11, 0, 0);
    node *node12 = new node(12, 0, 0);
    node *node13 = new node(13, 0, 0);
    node *node14 = new node(14, 0, 0);

    // asymetric tree
    root = node5;

    node5->left = node6;
    node5->right = node7;

    node6->left = node8;
    node6->right = node1;

    node1->left = node3;

    node7->left = node2;

    node2->left = node4;
    node2->right = node9;

    node9->left = node10;

    node10->right = node11;

    node11->right = node12;

    node3->left = node13;
    node3->right = node14;

    // Symmetric tree
    // node6->data = 6;
    // node7->data = 6;
    // node2->data = 8;
    //
    // node5->left = node6;
    // node5->right = node7;

    // node6->left = node8;
    // node6->right = node1;

    // node7->left = node2;
}
