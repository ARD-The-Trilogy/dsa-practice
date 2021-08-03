// link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution
{
public:
    int eleIt(vector<char> &arr, int l, int r, char t)
    {
        int res = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (l == r && arr[l] > t)
            {
                res = l, l++;
            }

            if (arr[mid] <= t)
            {
                l++;
            }

            if (arr[mid] > t)
            {
                res = mid, r = mid;
            }
        }

        if (res == -1)
            res = 0;

        return res;
    }

    char nextGreatestLetter(vector<char> &letters, char target)
    {

        int ans2 = eleIt(letters, 0, letters.size() - 1, target);

        return letters[ans2];
    }
};