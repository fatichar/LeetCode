/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;

        auto node = head;

        while (node->next != nullptr)
        {
            if (node->next->val == val)
            {
                deleteNext(node);
            }
            else
            {
                node = node->next;
            }
        }
        // all cleaned up except for the head
        if (head != nullptr && head->val == val)
        {
            auto temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }

    void deleteNext(ListNode *node)
    {
        auto next = node->next;
        node->next = next->next;
        delete next;
    }
};
// @lc code=end
