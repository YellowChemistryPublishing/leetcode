/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>

using namespace std;

// @lc code=start
bool isPalin(string& str, size_t at, size_t len)
{
    if (at + len <= str.size())
    {
        for (int i = 0; i < len / 2; i++)
        {
            if (str[at + i] != str[at + len - 1 - i])
                return false;
        }
        return true;
    }
    else return false;
}

class Solution {
public:
    string longestPalindrome(string s) {
        string_view ret = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size(); j >= i + max((size_t)1, ret.size()); j--)
            {
                if (isPalin(s, i, j - i))
                {
                    if (j - i > ret.size())
                        ret = std::string_view(&s[i], &s[j]);
                    break;
                }
            }
        }
        return string(ret);
    }
};
// @lc code=end

