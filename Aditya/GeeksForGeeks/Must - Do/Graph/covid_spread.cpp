// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>

class Solution {
public:
    bool isSafe(int i, int j, int n, int, m){
        if(i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }

    int count_spread_time(vvi hospital, vvb &visited, int i, int j, int n, int m){
        if(isSafe(i, j, n, m) && hospital[i][j] == 0){
            return 0;
        }
        else if(isSafe(i, j, n, m) && hospital[i][j] == 1){
            count_spread_time(hospital, visited, i-1, j, n, m);
            count_spread_time(hospital, visited, i, j+1, n, m);
            count_spread_time(hospital, visited, i+1, j, n, m);
            count_spread_time(hospital, visited, i, j-1, n, m);
        }
    }

    int helpaterp(vvi hospital){
        
        int n = hospital.size(), m = hospital[0].size();
        vvb visited(n, vb(m, 0));
        int ans = -1;
        
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(hospital[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = 1;
                    ans = count_spread_time(hospital, visited, i, j, n, m);
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends