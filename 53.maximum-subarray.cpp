/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <span>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    map<pair<int,int>, int> sums;
    int hr(span<int> nums, int& ret)
    {
        if (nums.size() == 1)
            return max(0, nums[0]);
        int r = hr(nums.subspan(1), ret);
        ret = max({nums[0] + r, ret});
        if (nums[0] + r < r)
            return 0;
        else return nums[0] + r;
    }
    int maxSubArray(vector<int>& nums) {
        int ret = 0;
        return hr(span(nums), ret);
    }
};
// @lc code=end
