/*
LINK:
https://www.geeksforgeeks.org/print-left-view-binary-tree/

*/

// RECURSIVE APPROACH
// int max_lev = -1;
// void viewUtil(vector<int> &nums, Node *root, int lev)
// {
//     if (!root)
//         return;

//     if (lev > max_lev)
//     {
//         nums.push_back(root->data);
//         max_lev = lev;
//     }

//     viewUtil(nums, root->left, lev + 1);
//     viewUtil(nums, root->right, lev + 1);
// }

// vector<int> leftView(Node *root)
// {
//     // Your code here
//     vector<int> nums;
//     if (!root)
//         return nums;

//     viewUtil(nums, root, 0);
//     return nums;
// }


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

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
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

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> nums;
    if (!root)
        return nums;

    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);

    bool f1 = false;
    while (!qu.empty() || qu.size() == 1)
    {
        Node *ptr = qu.front();
        qu.pop();
        // if not null then push its children
        if (ptr)
        {
            if (ptr->left)
                qu.push(ptr->left);
            if (ptr->right)
                qu.push(ptr->right);

            if (!f1)
            {
                nums.push_back(ptr->data);
                f1 = true;
            }
        }

        // if null && qu not empty
        // then push null
        else if (!qu.empty())
        {
            qu.push(NULL);
            f1 = false;
        }
    }
    return nums;
}
