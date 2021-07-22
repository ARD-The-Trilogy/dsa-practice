/*
LINK:
https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    stack<Node *> stk1, stk2;
    vector<Node *> path;

    void lcaUtil(Node *root, int n1, int n2)
    {
        if (!root)
            return;

        path.push_back(root);

        if (root->data == n1)
        {
            for (Node *root : path)
            {
                stk1.push(root);
            }
        }
        if (root->data == n2)
        {

            for (Node *root : path)
            {
                stk2.push(root);
            }
        }

        lcaUtil(root->left, n1, n2);
        lcaUtil(root->right, n1, n2);

        path.pop_back();
    }

    //Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        //Your code here
        if (!root)
            return 0;

        lcaUtil(root, n1, n2);

        if (stk1.size() == 0 || stk2.size() == 0)
        return 0;

        // stk1 and stk2 are filled
        int size1 = stk1.size(), size2 = stk2.size();
        while (size1 < size2)
        {
            stk2.pop();
            size2--;
        }

        while (size1 > size2)
        {
            stk1.pop();
            size1--;
        }

        // here the size comes to parallel level

        Node *pre = 0;
        while (stk1.top()->data != stk2.top()->data)
        {
            stk1.pop(), stk2.pop();
        }
        pre = stk1.top();

        return pre;
    }
};

// { Driver Code Starts.

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d ", &a, &b);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.lca(root, a, b)->data << endl;
    }
    return 0;
}
// } Driver Code Ends