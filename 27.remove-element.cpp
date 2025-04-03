/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums.back());
                nums.pop_back();
                if (nums.empty())
                    break;
            }
            else
            {
                ++i;
            }
        }
        return nums.size();
    }
};
// @lc code=end

