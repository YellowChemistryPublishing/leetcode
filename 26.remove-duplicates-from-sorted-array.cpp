/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int swapIndex;
        int nextThs = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nextThs == INT_MIN)
            {
                nextThs = nums[i];
            }
            else if (nums[i] == nextThs)
            {
                swapIndex = i;
                ++nextThs;
            }
            else if (nums[i])
        }
    }
};
// @lc code=end

