/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<decltype(nums.begin())> ordered;
        for (auto it = nums.begin(); it != nums.end(); ++it)
            ordered.push_back(it);
        std::sort(ordered.begin(), ordered.end(), [](auto a, auto b) { return *a < *b; });
        for (auto it = ordered.begin(); it != ordered.end(); ++it)
        {
            int searchVal = target - **it;
            int i = 0, j = ordered.size();
            while (j - i > 0)
            {
                if (searchVal < *ordered[i + (j - i) / 2])
                    j = i + (j - i) / 2;
                else if (searchVal > *ordered[i + (j - i) / 2])
                    i = i + (j - i) / 2 + 1;
                else
                {
                    auto itA = *it, itB = ordered[i + (j - i) / 2];
                    if (itA != itB)
                        return { int(itA - nums.begin()), int(itB - nums.begin()) };
                    else break;
                };
            }
        }
        return {};
    }
};
// @lc code=end
