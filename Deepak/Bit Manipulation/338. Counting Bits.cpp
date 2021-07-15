/*
LINK:
https://leetcode.com/problems/counting-bits/

*/

class Solution {
public:
    
    int totSetBits(int n) {
        int tot = 0;
        while(n) {
            tot++;
            n &= (n-1);
        }
        
        return tot;
    }
    
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        
        for(int i=1;i<=n;i++) {
            bits[i] = totSetBits(i);
            
        }
        
        return bits;
    }
};