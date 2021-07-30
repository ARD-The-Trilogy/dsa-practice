/*
LINk: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1#
LINK: https://www.geeksforgeeks.org/find-possible-words-phone-digits/

*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{

public:
    //Function to find list of all words possible by pressing given numbers.

    map<int, string> hash_phn;
    Solution()
    {
        hash_phn[2] = "abc";
        hash_phn[3] = "def";
        hash_phn[4] = "ghi";
        hash_phn[5] = "jkl";
        hash_phn[6] = "mno";
        hash_phn[7] = "pqrs";
        hash_phn[8] = "tuv";
        hash_phn[9] = "wxyz";
    }

    vector<string> numbers;

    void dp(int arr[], int i, string str)
    {
        if (i < 0)
        {
            numbers.push_back(str);
            return;
        }

        int num = arr[i];
        for (auto it : hash_phn[num])
        {
            string tmp = it + str;
            dp(arr, i - 1, tmp);
            // cout << i << ' ' << tmp << endl;
        }
    }

    vector<string> possibleWords(int a[], int N)
    {
        //Your code here        
        dp(a, N - 1, "");
        sort(numbers.begin(), numbers.end());
        return numbers;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; //testcases

    while (T--)
    { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends