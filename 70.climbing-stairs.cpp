/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int howMany(int n, map<int, int>& m)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        else if (m.contains(n))
            return m[n];
        else
        {
            int set = howMany(n - 1, m) + howMany(n - 2, m);
            m[n] = set;
            return set;
        }
    }
    int climbStairs(int n) {
        map<int, int> m;
        return howMany(n, m);
    }
};
// @lc code=end

