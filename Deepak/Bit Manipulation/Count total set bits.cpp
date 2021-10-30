// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int countSetBits(int n)
    {
        // Your logic here
        int tot = 0;
        n++;

        int num = 2, tmp = -1;
        int cnt = 31;
        while (tmp)
        {
            int segments = n / num;
            int seg_ones = num / 2;
            int left = n % num;
            // cout << segments << ' ' << left << endl;

            tmp = segments * seg_ones;
            if (left - seg_ones > 0)
            {
                tmp += (left - seg_ones);
            }

            tot += tmp;

            // cout << tmp << endl;
            num <<= 1;
        }

        return tot;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends