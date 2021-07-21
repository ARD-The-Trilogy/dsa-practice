// LINK:
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

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

// } Driver Code Ends
class Solution
{
public:
    //Function to find the vertical order traversal of Binary Tree.
    map<int, vector<int>> hash_node;

    void orderUtil(Node *root)
    {

        queue<pair<int, Node *>> qu;
        qu.push({0, root});

        while (!qu.empty())
        {
            auto pr = qu.front();
            qu.pop();
            int side_lev = pr.first;
            Node *tmp_root = pr.second;

            if (tmp_root->left)
                qu.push({side_lev - 1, tmp_root->left});

            if (tmp_root->right)
                qu.push({side_lev + 1, tmp_root->right});

            auto ptr = hash_node.find(side_lev);

            if (ptr == hash_node.end())
            {
                // push node inside new key;
                hash_node.insert({side_lev, {tmp_root->data}});
            }
            else
            {
                // push already existing
                hash_node[side_lev].push_back(tmp_root->data);
            }
        }
    }

    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> elements;
        if (!root)
            return elements;

        orderUtil(root);

        // process elements from its hash;
        // the map is already sorted.
        for (auto pr : hash_node)
        {
            for (int num : pr.second)
            {
                elements.push_back(num);
            }
        }

        return elements;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node *root = buildTree(s);

        vector<int> res = obj.verticalOrder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends