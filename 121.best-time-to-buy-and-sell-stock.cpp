/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int last = INT_MIN;
        for (auto i : prices)
        {
            if (last == INT_MIN)
            {
                last = i;
            }
            else
            {
                if (i > last)
                {
                    ret = max(ret, i - last);
                }
                else last = i;
            }
        }
        return ret;
    }
};
// @lc code=end

