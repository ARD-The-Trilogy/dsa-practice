// LINK: https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> brr;
void heapify(int n, int node)
{
    if (node < n)
    {
        int lchild = 2 * node + 1;
        int rchild = 2 * node + 2;
        int largest = node;

        if (lchild < n && brr[lchild] < brr[node])
        {
            largest = lchild;
        }
        if (rchild < n && brr[rchild] < brr[largest])
        {
            largest = rchild;
        }

        if (largest != node)
        {
            swap(brr[node], brr[largest]);
            heapify(n, largest);
        }
    }
}

void buildHeap(int k)
{

    for (int i = (k - 2) / 2; i >= 0; i--)
    {
        heapify(k, i);
    }
}

void heapSort(int k)
{

    int turns = k - 1, lastEle = turns;
    for (int i = k - 1; i > 0; i--)
    {
        swap(brr[0], brr[i]);
        heapify(i, 0);
    }
}

class Solution
{
public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        brr.assign(k, -1);
        for (int i = 0; i < k; i++)
            brr[i] = arr[i];
        buildHeap(k);

        for (int i = k; i < n; i++)
        {
            // extract one
            if (brr[0] < arr[i])
            {
                brr[0] = arr[i];
                heapify(k, 0);
            }
        }
        heapSort(k);
        return brr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends