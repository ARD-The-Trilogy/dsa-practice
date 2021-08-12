// link: https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1#
// link: https://www.geeksforgeeks.org/program-nth-catalan-number/

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find the nth catalan number.

    cpp_int findB(int n, int r)
    {
        // find 2nCr coefficient

        r = min(r, n - r);

        cpp_int ans = 1;
        for (int i = 0; i < r; i++)
        {
            ans *= (n - i);
            ans /= (i + 1);
        }

        return ans;
    }

    cpp_int findCatalan(int n)
    {
        //code here
        return findB(2 * n, n) / (n + 1);
    }
};

// { Driver Code Starts.

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking nth number
        int n;
        cin >> n;
        Solution obj;
        //calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
} // } Driver Code Ends