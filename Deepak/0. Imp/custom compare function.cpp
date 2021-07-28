/*
LINK: http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/#:~:text=priority_queue%20is%20categorized%20as%20a,one%20with%20the%20highest%20priority.



*/

#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct compr {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
    void hello() {
        cout << "hello";
    }

    void bef() {
        cout << "bef";
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

    vector<int> vt = {1,2,6,3,2,1};
    compr();
    // sort(vt.begin(), vt.end(), compr());

}
