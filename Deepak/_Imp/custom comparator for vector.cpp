#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

typedef pair<int, int> pii;
struct compr
{
    bool operator()(const pii &obj1, const pii &obj2)
    {
        if (obj1.second == obj2.second)
            return obj1.first < obj2.first;

        return obj1.second > obj2.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<pii> nums;
    sort(nums.begin(), nums.end(), compr());
}
