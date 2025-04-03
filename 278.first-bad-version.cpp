/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

bool isBadVersion(int version);

// @lc code=start

enum
{
    left,
    right,
    neither
};

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (right - left > 1)
        {
            if (!isBadVersion(left) && isBadVersion(right))
            {
                int mid = left + (right - left) / 2;
                if (isBadVersion(mid))
                    right = mid;
                else left = mid;
            }
        }
        return right;
    }
};
// @lc code=end

