// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int tot_xor = 0, len = nums.size();
        for(int i=0;i<len;i++) {
            tot_xor ^= nums[i];
        }
        
        
        int idx = 0, tmp = tot_xor;
        while((tmp & 1) == 0) {
            tmp >>= 1;
            idx++;
        }

        // we got the index here 
        
        int tot_xor2 = 0;
        for(int i=0;i<len;i++) {
            // xor only those who has a set bit at index idx
            if(((nums[i] >> idx) & 1) == 1) {
                tot_xor2 ^= nums[i];
            }
        }
        
        vector<int> ret;
        ret.push_back(tot_xor2);
        ret.push_back(tot_xor ^ tot_xor2);
        
        sort(ret.begin(), ret.end());
        return ret;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends