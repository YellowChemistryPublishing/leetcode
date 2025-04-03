/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <algorithm>
#include <set>
#include <deque>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        std::map<char, int> existing;
        auto itL = s.begin(), itR = s.begin();
        while (itR != s.end())
        {
            ++existing[*itR];
            while (existing[*itR] > 1)
            {
                --existing[*itL];
                ++itL;
            }
            ++itR;
            ret = std::max(ret, int(itR - itL));
        }
        return ret;
    }
};
// @lc code=end

