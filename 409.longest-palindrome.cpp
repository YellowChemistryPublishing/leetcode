/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (auto c : s)
            ++m[c];
        bool hasOneExtra = false;
        int ret = 0;
        for (auto&[_, count] : m)
        {
            if (count % 2 == 1)
                hasOneExtra = 1;
            ret += count / 2 * 2;
        }
        ret += hasOneExtra;
        return ret;
    }
};
// @lc code=end

