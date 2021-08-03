// link: https://www.interviewbit.com/problems/search-in-bitonic-array/
// link: https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

int searchUtil(vector<int> &arr, int l, int h)
{
    // base case
    // no base case

    int mid = l + (h - l) / 2;

    if (mid > l && mid < h && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid - 1])
    {
        return mid;
    }

    if (arr[mid - 1] < arr[mid])
        searchUtil(arr, mid, h);

    else
        searchUtil(arr, l, mid);

    return -1;
}

int searchInc(vector<int> &A, int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;

    if (A[mid] == key)
        return mid;

    if (A[mid] < key)
        return searchInc(A, mid + 1, h, key);

    return searchInc(A, l, mid - 1, key);
}

int searchDecr(vector<int> &A, int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;
    if (A[mid] == key)
        return mid;

    if (A[mid] > key)
    {
        return searchDecr(A, mid + 1, h, key);
    }

    return searchDecr(A, l, mid - 1, key);
}

int Solution::solve(vector<int> &A, int B)
{

    int idx = searchUtil(A, 0, A.size() - 1);

    int ans1 = searchInc(A, 0, idx, B);
    if (ans1 == -1)
    {
        ans1 = searchDecr(A, idx + 1, A.size() - 1, B);
    }

    return ans1;
}
