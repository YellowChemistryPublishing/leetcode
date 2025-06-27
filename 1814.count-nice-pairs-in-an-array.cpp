/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define ll long long

class Solution {
public:
    constexpr ll rev(ll i)
    {
        if (i < 10)
            return i;
        
        ll i2 = i;
        ll invmul = 1;
        while (i2 != 0)
        {
            i2 /= 10;
            invmul *= 10;
        }

        ll ret = 0;
        invmul /= 10;
        while (invmul != 0)
        {
            //cout<<'\t'<<ret<<'\n';
            ret += invmul * (ll)(i % 10ll);
            //cout << "    " << i << "  " << i % 10ll << '\n';
            i /= 10;

            invmul /= 10ll;
        }
        return ret;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> numsreal(nums.begin(), nums.end());
        for (auto& n : numsreal)
            n = (int)((ll)n - (ll)rev(n));
        //for (auto& revc : numsreal)
        //    cout<<revc<<'\n';
        map<int,int> v;
        for (size_t i = 0; i < numsreal.size(); i++)
        {
            ++v[numsreal[i]];
        }
        ll ret = 0;
        for (auto[diff,count] : v)
        {
            //cout<<count<<'\n';
            --count;
            ll many = 0;
            if ((ll)(count) % 2ll == 0ll)
            {
                many = (ll)(count) / 2ll * ((ll)(count) + 1ll);
            }
            else many = (ll)(count) / 2ll * ((ll)(count) + 1ll) + (ll)(count) / 2ll + 1ll;
            ret = (ret + (ll)many) % ((ll)(1e9)+7ll);
        }
        return ret;
    }
};
// @lc code=end

