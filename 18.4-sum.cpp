/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> workingSol;
        set<vector<int>> visited;
        auto findOne = [&](auto&& findOne, int i, int s = 0) -> void
        {
            cerr << i << "  " << s << '\n';
            if (i > 0)
            {
                for (auto it = nums.begin(); it < nums.end() - (4 - i); ++it)
                {
                    workingSol.emplace_back(*it);

                    vector<int> v = workingSol;
                    sort(v.begin(), v.end());
                    if (visited.contains(v))
                    {
                        workingSol.pop_back();
                        continue;
                    }

                    s += *it;
                    swap(*it, *(nums.end() - (5 - i)));

                    findOne(findOne, i - 1, s);
                    visited.emplace(move(v));

                    swap(*it, *(nums.end() - (5 - i)));
                    s -= workingSol.back();
                    workingSol.pop_back();
                }
            }
            else if (s == target)
            {
                ret.emplace_back(workingSol);
            }
        };
        findOne(findOne, 4);
        return ret;
    }
};
// @lc code=end

