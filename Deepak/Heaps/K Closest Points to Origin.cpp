
// LINK: https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct compr
{
    bool operator()(const vector<int> &pr1, const vector<int> &pr2)
    {
        int dist1 = pr1[0] * pr1[0] + pr1[1] * pr1[1];
        int dist2 = pr2[0] * pr2[0] + pr2[1] * pr2[1];

        return dist1 < dist2;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{

    priority_queue<vector<int>, vector<vector<int>>, compr> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(points[i]);
    }

    for (int i = k; i < points.size(); i++)
    {
        pq.push(points[i]);
        pq.pop();
    }

    vector<vector<int>> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> vt = {{2,3}, {1,5}, {6,7}};
    vector<vector<int>> ans = kClosest(vt, 1);

    for(auto it: ans) {
        for(auto kt: it) {
            cout << kt << ' ';
        }
        cout << endl;
    }


}
