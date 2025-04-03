/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        else if (!head->next)
            return head;
        ListNode* prev = head, *cur = head->next;
        while (cur)
        {
            ListNode* realNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = realNext;
        }
        head->next = nullptr;
        return prev;
    }
};
// @lc code=end

