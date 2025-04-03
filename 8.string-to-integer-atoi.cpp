/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include <string>
#include <cctype>

using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        long long ret = 0;
        auto beg = s.begin();
        while (std::isspace(*beg))
        {
            if (beg == s.end())
                return ret;
            ++beg;
        }
        if (beg == s.end())
            return ret;
        if (*beg == '-')
        {
            neg = true;
            ++beg;
        }
        else if (*beg == '+')
            ++beg;
        while (beg != s.end() && *beg == '0')
            ++beg;
        auto end = beg;
        while (end != s.end() && std::isdigit(*end))
            ++end;
        long long mul = neg ? -1 : 1;
        for (auto it = --end; it >= beg; --it)
        {
            if (it != end)
            {
                if (mul == 1000000000000000000)
                    return INT_MAX;
                else if (mul == -1000000000000000000)
                    return INT_MIN;
                mul *= 10;
            }
            ret += (long long)(*it - '0') * mul;
            if (ret > INT_MAX)
                return INT_MAX;
            else if (ret < INT_MIN)
                return INT_MIN;
        }
        return ret;
    }
};
// @lc code=end
