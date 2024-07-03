/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
class Solution {
public:
    bool hasCycle(ListNode *slow) {
        if (slow == nullptr) return false;

        auto fast = slow;
        do {
            slow = slow->next;
            fast = fast->next;
            // slow doesn't have to be checked for null, as fast will reach the end quicker
            if (fast == nullptr) return false;
            fast = fast->next;
            if (fast == nullptr) return false;
        } while (slow != fast);

        return true;
    }
};
// @lc code=end
