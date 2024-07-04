/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
#define LN ListNode*

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        LN front = head;
        LN back = head;

        int i = 0;
        while (i++ < n) {
            front = front->next;
        }
        if (front == nullptr) {
            // head has to be deleted
            return head->next;
        }

        // now front is ahead of back by n nodes
        while (front->next != nullptr) {
            front = front->next;
            back = back->next;
        }
        // now front is at the last node
        // back is one place before the node to be deleted
        LN temp = back->next;
        back->next = temp->next;
        delete temp;

        return head;
    }
};
// @lc code=end
