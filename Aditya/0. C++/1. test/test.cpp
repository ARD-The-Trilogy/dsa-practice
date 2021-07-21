#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}










// #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	// #ifndef ONLINE_JUDGE
// 	// 	freopen("input.txt", "r", stdin);
// 	// 	freopen("output.txt", "w", stdout);
// 	// #endif

// 	int a,b;
// 	cin>>a>>b;
// 	cout<<a+b;
	
// 	return 0;
// }
