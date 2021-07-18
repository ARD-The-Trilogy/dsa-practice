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

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int v, Node *le, Node *ri, int h = 0)
    {
        data = v, left = le, right = ri, height = h;
    }
};

map<int, vector<int>> mp;
Node *root;
map<int, int> lview;
map<int, int> rview;


void makeTree();
void preOrderRec(Node *);
void preOrderIterative();
void inOrderRec(Node *);
void levOrder();
void inOrderIterative();
void diagnoalSub(Node *root, int lev);
void diagnoalTraversal();
int getHeight(Node *root);
int height(Node *root);
void showHeights(Node *root);
int isTreeBalanced(Node *root);
int diameterTree(Node *root, int &dia);
void leftView(Node *root, int lev);
void leftViewPrint();
void rightView(Node *root, int lev);
void rightViewPrint();
void rightViewLev();
void topView();
void bottomView();
void leftBoundary(Node *root, stack<Node*> &stk);
void boundaryTraversal();
void subrtl(vector<vector<int>> &vt, vector<int> &tmp, Node *root);
void rootToLeaves();
void subrtlSum(Node *root, vector<int> &vt, int sum, bool &f1, int key);
bool rootToLeavesSum(int key);
int subkn(Node *root, int lev, int k);
int kthNodeFromRoot(int k);
bool subsymm(Node *Node1, Node *Node2);
void symmetricTree();



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
    Node *Node1 = new Node(1, 0, 0);
    Node *Node2 = new Node(2, 0, 0);
    Node *Node3 = new Node(3, 0, 0);
    Node *Node4 = new Node(4, 0, 0);
    Node *Node5 = new Node(5, 0, 0);
    Node *Node6 = new Node(6, 0, 0);
    Node *Node7 = new Node(7, 0, 0);
    Node *Node8 = new Node(8, 0, 0);
    Node *Node9 = new Node(9, 0, 0);
    Node *Node10 = new Node(10, 0, 0);
    Node *Node11 = new Node(11, 0, 0);
    Node *Node12 = new Node(12, 0, 0);
    Node *Node13 = new Node(13, 0, 0);
    Node *Node14 = new Node(14, 0, 0);

    // asymetric tree
    root = Node5;

    Node5->left = Node6;
    Node5->right = Node7;

    Node6->left = Node8;
    Node6->right = Node1;

    Node1->left = Node3;

    Node7->left = Node2;

    Node2->left = Node4;
    Node2->right = Node9;

    Node9->left = Node10;

    Node10->right = Node11;

    Node11->right = Node12;

    Node3->left = Node13;
    Node3->right = Node14;

    // Symmetric tree
    // Node6->data = 6;
    // Node7->data = 6;
    // Node2->data = 8;
    //
    // Node5->left = Node6;
    // Node5->right = Node7;

    // Node6->left = Node8;
    // Node6->right = Node1;

    // Node7->left = Node2;
}

void preOrderRec(Node *temp)
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
    stack<Node *> stk; // for storing Nodes addreses;

    stk.push(root);
    while (!stk.empty())
    {
        Node *temp = stk.top();
        stk.pop();
        cout << temp->data << ' ';
        if (temp->right)
            stk.push(temp->right);
        if (temp->left)
            stk.push(temp->left);
    }
    cout << endl;
}

void inOrderRec(Node *temp)
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
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *temp = qu.front();
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
    stack<Node *> stk;
    stk.push(root);
    stack<int> nums;

    while (!stk.empty())
    {
        Node *temp = stk.top();
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

void diagnoalSub(Node *root, int lev)
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

int getHeight(Node *root)
{
    if (!root)
        return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int height(Node *root)
{
    if (!root)
        return -1;

    root->height = 1 + max(height(root->left), height(root->right));
    return root->height;
}

void showHeights(Node *root)
{
    if (!root)
        return;

    cout << root->data << ' ' << root->height << endl;
    showHeights(root->left);
    showHeights(root->right);
}

int isTreeBalanced(Node *root)
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

int diameterTree(Node *root, int &dia)
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

void leftView(Node *root, int lev)
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

void rightView(Node *root, int lev)
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
    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {

        while (qu.front() != NULL)
        {
            Node *tmp = qu.front();
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
    queue<pair<Node *, int>> qu;
    // b & f denotes the width wise distance from root;
    int b = 0, f = 0;
    qu.push({root, 0});
    map<int, int> tView;
    while (!qu.empty())
    {
        pair<Node *, int> tmp = qu.front();
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
    queue<pair<Node *, int>> qu;
    map<int, int> bView;
    qu.push({root, 0});
    bView.insert({0, root->data});

    while (!qu.empty())
    {
        pair<Node *, int> tmp = qu.front();
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

void leftBoundary(Node *root, stack<Node*> &stk) {
    if(root->left) {
        stk.push(root->left);
        // leftBoundary(root->left, )
    }

}
void boundaryTraversal() {
    stack<Node*> stk;
    vector<int> nums;

    leftBoundary(root, stk);


}

void subrtl(vector<vector<int>> &vt, vector<int> &tmp, Node *root)
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

void subrtlSum(Node *root, vector<int> &vt, int sum, bool &f1, int key)
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

int subkn(Node *root, int lev, int k)
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

bool subsymm(Node *Node1, Node *Node2)
{
    if (!Node1 && !Node2)
        return true;
    if (!(Node1 && Node2))
        return false;
    if (Node1->data != Node2->data)
        return false;

    return subsymm(Node1->left, Node2->left) && subsymm(Node1->right, Node2->right);
}

void symmetricTree()
{
    cout << subsymm(root->left, root->right) << endl;
}
