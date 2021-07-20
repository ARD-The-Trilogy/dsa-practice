/*
LINK:
https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
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

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User Fuction template for C++

class Solution
{
public:
    //Function to return maximum path sum from any node in a tree.
    int maxi = -1e9;

    int pathUtil(Node *root)
    {
        if (!root)
            return 0;

        // le = 0 means it will not accept any path from left subtree
        // if the subtree sum goes negative.
        int le = 0, ri = 0;
        le = max(le, pathUtil(root->left));
        ri = max(ri, pathUtil(root->right));

        // it will keep the maximum path including the current node
        int max_path = root->data + le + ri;
        maxi = max(maxi, max_path);

        return max(0, root->data + max(le, ri));
    }

    int findMaxSum(Node *root)
    {
        // Your code goes here
        pathUtil(root);

        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";
    }

    return 0;
} // } Driver Code Ends