/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = nullptr;
        ListNode* last = nullptr;
        while (list1 || list2)
        {
            ListNode*& next = [&]() -> ListNode*&
            {
                if ((list1 && list2 && list1->val < list2->val) || (list1 && !list2))
                {
                    return list1;
                }
                else return list2;
            }();
            
            if (!ret)
            {
                ret = next;
                last = next;
            }
            else
            {
                last->next = next;
                last = next;
            }
            next = next->next;
        }
        if (last)
            last->next = nullptr;
        return ret;
    }
};
// @lc code=end

