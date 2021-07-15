/*
LINK:
https://leetcode.com/problems/power-of-four/

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        long long num = 1;
        while(n > num) {
            num <<= 2;
        }
        
        if(num == n) return true;
            
        return false;
    }
};