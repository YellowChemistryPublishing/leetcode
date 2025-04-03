/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start

class Solution {
public:
    void trav(ListNode* head, ListNode*& last, ListNode* prev = nullptr)
    {
        //printf("%d\n", head->val);
        ListNode* next = head->next;
        head->next = prev;
        last = head;
        if (next)
            trav(next, last, head);
    }
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        else if (!head->next)
            return false;
        ListNode* last;
        trav(head, last);
        return last == head;
    }
};
// @lc code=end
