/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candies;
        for (auto c : candyType)
        {
            if (candies.size() >= candyType.size() / 2)
                return candyType.size() / 2;
            
            candies.emplace(c);
        }
        return candies.size();
    }
};
// @lc code=end

