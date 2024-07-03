/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto lastA = headA, lastB = headB;
        int lenA = 1, lenB = 1;

        while (lastA->next != nullptr)
        {
            lastA = lastA->next;
            ++lenA;
        }
        while (lastB->next != nullptr)
        {
            lastB = lastB->next;
            ++lenB;
        }
        // last node not common, so no intersection
        if (lastA != lastB) return nullptr;

        auto small = headA, large = headB;
        int diff = lenB - lenA;
        if (lenA > lenB) {
            small = headB;
            large = headA;
            diff = lenA - lenB;
        }

        while (diff-- > 0)  large = large->next;

        while (small != nullptr)
        {
            if (small == large) return small;

            small = small->next;
            large = large->next;
        }

        return nullptr;
    }
};
// @lc code=end
