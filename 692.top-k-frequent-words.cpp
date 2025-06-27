/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include <string>
#include <string_view>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <ranges>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string_view, size_t> counts;
        for (const string& word : words)
            ++counts[word];
        priority_queue<pair<size_t, string_view>, vector<pair<size_t, string_view>>,
            decltype([](const pair<size_t, string_view>& a, const pair<size_t, string_view>& b) -> bool
            {
                return a.first != b.first ? a.first > b.first : a.second < b.second;
            })> pq;
        for (const auto& wc : counts)
        {
            pq.emplace(make_pair(wc.second, wc.first));
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ret(k);
        while (!pq.empty())
        {
            ret[--k] = string(std::move(pq.top().second));
            pq.pop();
        }
        return ret;
    }
};
// @lc code=end

