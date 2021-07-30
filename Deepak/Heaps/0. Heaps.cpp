#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

vector<int> arr;
int size;

int par(int i) {
    return (i-1)/2;
}

int lChild(int i) {
    return 2 * i + 1;
}

int rChild(int i) {
    return 2 * i + 2;
}

void heapify(int i) {
    int lchild = 0, rchild = 0;
    int largest = 0;
    if(lChild(i) >= 0 && lChild(i) < size) {
        lchild = lChild;
        
    }
}

void buildHeap() {
    int size = arr.size();

    for(int i=par(size-1);i>=0;i--) {
        // from here start heapify
        heapify(i);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 10;
    arr = {1,4,2,3,6,7,3,7};
    size = arr.size();

    buildHeap();


}
