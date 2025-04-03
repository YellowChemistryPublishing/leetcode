/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <climits>
#include <cstdio>
#include <cmath>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        signed char bcd[10] { };
        for (int i = 0, m = 1e9; i < 10; i++, m /= 10)
        {
            bcd[i] = x / m;
            x %= m;
        }
        signed char* beg = bcd + 9;
        signed char* end = bcd;
        while (end <= beg && *end == 0)
            ++end;

        int ret = 0, m = 1;
        for (auto it = end; it <= beg; ++it)
        {
            if (!((int(*it) >= 0 && int(*it) <= INT_MAX / m && ret <= INT_MAX - int(*it) * m) ||
                (int(*it) < 0 && int(*it) >= INT_MIN / m && ret >= INT_MIN - int(*it) * m)))
                return 0;
            ret += int(*it) * m;
            if (it != beg)
                m *= 10;
        }
        return ret;
    }
};
// @lc code=end

