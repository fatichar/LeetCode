// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();

        return sortedArrayToBST(nums, 0, len);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start >= end) return nullptr;

        int len = end - start;
        int mid = start+len/2;
        auto root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid+1, end);

        return root;
    }
};
// @lc code=end
