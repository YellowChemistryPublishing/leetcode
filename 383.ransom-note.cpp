/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int s[26] { };
        for (auto c : magazine)
            ++s[c - 'a'];
        for (auto c : ransomNote)
            --s[c - 'a'];
        for (auto ct : s)
        {
            if (ct < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

