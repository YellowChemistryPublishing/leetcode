/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;
        for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend() || it2 != b.rend();)
        {
            int va = it1 != a.rend() ? *it1 - '0' : 0;
            int vb = it2 != b.rend() ? *it2 - '0' : 0;
            ret.push_back('0' + (va + vb + carry) % 2);
            carry = (va + vb + carry) / 2;

            if (it1 != a.rend())
                ++it1;
            if (it2 != b.rend())
                ++it2;
        }
        if (carry != 0)
            ret.push_back('0' + carry);
        while (ret.back() == '0' && ret.size() > 1)
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

