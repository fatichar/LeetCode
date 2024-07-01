// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem112.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)   return false;

        bool has = hasSum(root, targetSum);
        return has;
    }

    bool hasSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return targetSum == 0;

        if (root->left == nullptr && root->right == nullptr)   return targetSum == root->val;

        // root is not a leaf node
        int requiredSum = targetSum - root->val;
        if (root->left != nullptr)
        {
            if (hasSum(root->left, requiredSum))    return true;
        }
        if ((root->right != nullptr) && hasSum(root->right, requiredSum))   return true;

        return false;
    }
};
// @lc code=end
