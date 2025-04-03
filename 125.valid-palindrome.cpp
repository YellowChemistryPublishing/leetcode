/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string real;
        real.reserve(s.size());
        for (auto c : s)
        {
            if (isalnum(c))
                real.push_back(tolower(c));
        }
        for (int i = 0; i < real.size() / 2; i++)
        {
            if (real[i] != real[real.size() - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end

