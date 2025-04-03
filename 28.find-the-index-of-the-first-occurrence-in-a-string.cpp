/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t f = haystack.find(needle);
        if (f == std::string::npos)
            return -1;
        else return f;
    }
};
// @lc code=end

