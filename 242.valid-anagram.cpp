/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int letters[26];
        for (auto c : s)
            ++letters[c - 'a'];
        for (auto c : t)
            --letters[c - 'a'];
        for (auto i : letters)
            if (i != 0)
                return false;
        return true;
    }
};
// @lc code=end

