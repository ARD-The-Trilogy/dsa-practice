/*
LINK:
https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

*/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    int R, C;
    vector<vector<int>> vis;
    
    bool isValid(int i, int j)
    {
        if (i > -1 && i < R && j > -1 && j < C && !vis[i][j])
            return true;
        return false;
    }

    
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        vis.assign(r, vector<int> (c, 0));
        R = r, C = c;
        
        vector<int> nums;
        int i = 0, j = 0, dir = 0;
        while (isValid(i, j) && !vis[i][j])
        {
            nums.push_back(matrix[i][j]);
            // cout << matrix[i][j] << ' ';
            vis[i][j] = true;
    
            if(dir == 0 && isValid(i, j+1)) j++;
            else if(dir == 0 && !isValid(i, j+1)) {
                i++, dir = 1;
            }
            else if(dir == 1 && isValid(i+1, j)) i++;
            else if(dir == 1 && !isValid(i+1, j)) {
                j--, dir = 2;
            }
            else if(dir == 2 && isValid(i, j-1)) j--;
            else if(dir == 2 && !isValid(i, j-1)) {
                i--, dir = 3;
            }
            else if(dir == 3 && isValid(i-1, j)) i--;
            else if(dir == 3 && !isValid(i-1, j)) {
                j++, dir = 0;
            }
            
        }
        return nums;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends