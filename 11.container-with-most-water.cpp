/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin(), right = --height.end();
        int area = 0;
        while (right > left)
        {
            area = max(area, (int)(min(*right, *left) * (right - left)));
            if (*left < *right)
                ++left;
            else --right;
        }
        return area;
    }
};
// @lc code=end

