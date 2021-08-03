// LINK: https://www.geeksforgeeks.org/frequent-word-array-strings/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n)
    {
        // code here
        map<string, int> hash_map;
        string last = "";
        int maxi = 0;
        
        for (int i = 0; i < n; i++)
        {
            string str = arr[i];
            hash_map[str]++;
            
            if(hash_map[str] >= maxi) {
                maxi = hash_map[str];
                last = str;
            }
        }

        set<string> st;
        for(int i=0;i<n;i++) {
            string str = arr[i];
            if(hash_map[str] != maxi) continue;

            auto ptr = st.find(str);
            if(ptr == st.end()) {
                st.insert(str);
                last = str;
            } else continue;
            
        }
        
        
        return last;
    }
};

// { Driver Code Starts.
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
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends