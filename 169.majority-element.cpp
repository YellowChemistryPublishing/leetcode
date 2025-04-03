/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int m;
        for (auto n : nums)
        {
            if (c == 0)
            {
                m = n;
                c = 1;
            }
            else if (m == n)
            {
                ++c;
            }
            else --c;
        }
        return m;
    }
};
// @lc code=end

