/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr, *last; int carry = 0;
        for (auto* it1 = l1, *it2 = l2; it1 || it2; it1 = it1 ? it1->next : nullptr, it2 = it2 ? it2->next : nullptr)
        {
            if (!ret)
            {
                ret = new ListNode(0);
                last = ret;
            }
            else
            {
                last->next = new ListNode(0);
                last = last->next;
            }

            last->val += carry;
            if (it1)
                last->val += it1->val;
            if (it2)
                last->val += it2->val;

            carry = last->val / 10;
            last->val %= 10;
        }
        if (carry != 0)
        {
            last->next = new ListNode();
            last->next->val = carry;
        }
        return ret;
    }
};
// @lc code=end

