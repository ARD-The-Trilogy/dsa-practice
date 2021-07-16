/*

LINK:
https://leetcode.com/problems/permutations-ii/

*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

class Solution
{
public:
    vector<vector<int>> all_arrays;
    set<vector<int>> st;

    void permuteUtil(vector<int> nums, int len)
    {

        if (len == 0)
        {
            st.insert(nums);
            return;
        }

        for (int i = 0; i <= len; i++)
        {

            swap(nums[i], nums[len]);
            permuteUtil(nums, len - 1);
            swap(nums[i], nums[len]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        permuteUtil(nums, nums.size() - 1);

        for (auto it : st)
        {
            all_arrays.push_back(it);
        }
        return all_arrays;
    }

    void printAll()
    {
        for (auto it : all_arrays)
        {
            for (auto kt : it)
            {
                cout << kt << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Very Efficient Solution
// 0ms
class Solution2
{
public:
    vector<vector<int>> allArrays;

    void permuteUtil(int *arr, vector<int> &array, int tot)
    {
        cout << tot << endl;
        if (tot == 0)
        {
            allArrays.push_back(array);
            return;
        }

        for (int i = 0; i < 22; i++)
        {
            if (arr[i] > 0)
            {
                array.push_back(i - 10);
                arr[i]--;
                permuteUtil(arr, array, tot - 1);
                arr[i]++;
                array.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int arr[22];
        memset(arr, 0, sizeof arr);

        int tot = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            arr[num + 10]++;
            tot++;
        }

        vector<int> vt;
        permuteUtil(arr, vt, tot);

        return allArrays;
    }

    void printAll()
    {
        for (auto it : allArrays)
        {
            for (auto kt : it)
            {
                cout << kt << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};

// STL APPROACH
void solution3 (vector<int> nums) {
    vector<vector<int>> allArrays;
    do {
        allArrays.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));

    for(auto it:allArrays) {
        for(auto kt: it) {
            cout << kt << ' ';
        }
        cout << endl;
    }
    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, inp;
    cin >> n;
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        vt.push_back(inp);
    }
    Solution2 obj1;
    obj1.permuteUnique(vt);
    obj1.printAll();
}
