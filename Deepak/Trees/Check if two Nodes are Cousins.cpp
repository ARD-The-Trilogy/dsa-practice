/*

LINK:
https://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isCousins(Node *root, int x, int y);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        if (x == y)
        {
            cout << "0\n";
            continue;
        }
        cout << isCousins(root, x, y) << endl;
    }
    return 1;
} // } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void cousinUtil(Node *root, int par, int lev, int a, int b, pair<int, int> &root_a, pair<int, int> &root_b)
{
    if (!root)
        return;

    if (root->data == a)
    {
        root_a.first = par, root_a.second = lev;
        // cout << root_a.first << ' ' << root_a.second << endl;
    }
    else if (root->data == b)
    {
        root_b.first = par, root_b.second = lev;
        // cout << root_b.first << ' ' << root_b.second << endl;
    }

    cousinUtil(root->left, root->data, lev + 1, a, b, root_a, root_b);
    cousinUtil(root->right, root->data, lev + 1, a, b, root_a, root_b);
}

// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
    //add code here.
    pair<int, int> root_a(0, 0), root_b(0, 0);
    cousinUtil(root, -1, 0, a, b, root_a, root_b);
    bool f1 = false;
    if (root_a.first != root_b.first && root_a.second == root_b.second)
        f1 = true;

    return f1;
}