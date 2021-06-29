#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> edge;
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        edge.push_back({x, y});
    }

    for(auto it: edge) {
        cout<<it[0]<<it[1]<<endl;
    }
    return 0;
}
