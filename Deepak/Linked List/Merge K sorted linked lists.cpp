// LINK: https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

struct node
{
    Node *ptr;
    int val;
    node(Node *p, int v) : ptr(p), val(v)
    {
    }
};

struct comprNode
{
    bool operator()(const node &obj1, const node &obj2)
    {
        return obj1.val > obj2.val;
    }
};

class Solution
{
public:
    //Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<node, vector<node>, comprNode> pq;

        for (int i = 0; i < K; i++)
        {
            Node *curr = arr[i];
            while (curr != 0)
            {
                pq.push({curr, curr->data});
                curr = curr->next;
            }
        }

        Node *list_root = 0, *pre = 0;
        while (!pq.empty())
        {
            node tmp = pq.top();
            pq.pop();
            tmp.ptr->next = 0;

            if (!list_root)
            {
                list_root = tmp.ptr;
            }
            else
            {
                pre->next = tmp.ptr;
            }

            pre = tmp.ptr;
        }

        return list_root;
    }
};

// { Driver Code Starts.
// Driver program to test above functions
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
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends