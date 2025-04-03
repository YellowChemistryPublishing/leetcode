/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unsigned short lo = 0, hi = nums.size();
        while (hi - lo > 0)
        {
            short med = lo + (hi - lo) / 2;
            if (nums[med] == target)
                return med;
            else if (med == lo)
                return -1;
            else if (target > nums[med])
                lo = med;
            else hi = med;
        }
        return -1;
    }
};
// @lc code=end

