/*

LINK:
https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

*/

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    Node *buildUtil(int *in, int *pre, int &ptr, int l, int r)
    {
        if (l > r)
            return 0;

        int tmp = pre[ptr++];

        int idx = -1;
        for (int i = l; i <= r; i++)
        {
            if (in[i] == tmp)
            {
                idx = i;
                break;
            }
        }
        // now we get the index of the center node.

        Node *tmp_node = new Node(tmp);
        tmp_node->left = 0, tmp_node->right = 0;

        // make left tree;
        if (l < r)
            tmp_node->left = buildUtil(in, pre, ptr, l, idx - 1);

        // make right tree;
        if (l < r)
            tmp_node->right = buildUtil(in, pre, ptr, idx + 1, r);

        return tmp_node;
        // return the address of the created node.
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        // return buildUtil(in, pre, 0, n - 1);
        int ptr = 0;
        return buildUtil(in, pre,ptr, 0, n - 1);
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends