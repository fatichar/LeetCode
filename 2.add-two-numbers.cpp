/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current = new ListNode(-1);
        ListNode *sum = current;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int total = carry + l1->val + l2->val;
            carry = total > 9;
            if (carry)
            {
                total %= 10;
            }
            current->next = new ListNode(total);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        auto lr = l1 == nullptr ? (l2 == nullptr ? nullptr : l2) : l1;
        while (lr != nullptr)
        {
            int total = carry + lr->val;
            carry = total > 9;
            if (carry)
            {
                total %= 10;
            }
            current->next = new ListNode(total);
            current = current->next;
            lr = lr->next;
        }
        if (carry)
        {
            current->next = new ListNode(1);
        }

        return sum->next;
    }
};
// @lc code=end
