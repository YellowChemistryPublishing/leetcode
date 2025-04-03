/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        s.reserve(nums.size());
        for (auto n : nums)
            s.insert(n);
        int ret = 0;
        for (auto n : s)
        {
            if (s.find(n - 1) == s.end())
            {
                int v = 1;
                int i = n;
                while (s.find(i + 1) != s.end())
                {
                    ++v;
                    ++i;
                }
                ret = max(ret, v);
            }
        }
        return ret;
    }
};
// @lc code=end

