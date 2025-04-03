/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include <vector>
#include <map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) { return a->val > b->val; })> vals;

        for (auto& l : lists)
        {
            for (auto* it = l; it; it = it->next)
            {
                vals.push(it);
            }
        }

        if (vals.empty())
            return nullptr;

        ListNode* ret = nullptr;
        ListNode* prev = nullptr;
        ListNode* l;
        while (!vals.empty())
        {
            l = vals.top();
            if (prev)
                prev->next = l;
            else ret = l;
            prev = l;
            vals.pop();
        }
        prev->next = nullptr;
        return ret;
    }
};
// @lc code=end

