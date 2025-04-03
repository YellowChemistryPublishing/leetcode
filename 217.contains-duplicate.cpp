/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int iprev = INT_MIN;
        for (auto i : nums)
        {
            if (iprev == INT_MIN)
            {
                iprev = i;
            }
            else if (iprev == i)
                return true;
            else iprev = i;
        }
        return false;
    }
};
// @lc code=end

