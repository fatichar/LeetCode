// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem23.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        auto joined = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            joined = merge(joined, lists[i]);
        }
        return joined;
    }

    ListNode* merge(ListNode* first, ListNode* second)
    {
        if (first == nullptr)   return second;
        if (second == nullptr)  return first;

        ListNode* target = first, *source = second;
        if (first->val > second->val)
        {
            target = second;
            source = first;
        }
        auto merged = target;
        // target = target->next;

        // keep inserting second nodes into node at correct pos
        while (target->next != nullptr && source != nullptr)
        {
            if (target->next->val > source->val)
            {
                // insert source node between target and target->next
                auto nextSource = source->next;
                auto nextTarget = target->next;

                target->next = source;
                source->next = nextTarget;

                source = nextSource;
            }
            target = target->next;
        }
        if (target->next == nullptr)
        {
            target->next = source;
        }

        return merged;
    }
};
// @lc code=end
