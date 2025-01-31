/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        return areMirror(root->left, root->right);
    }

    bool areMirror(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr)    return right == nullptr;
        if (right == nullptr)   return false;

        return left->val == right->val
            && areMirror(left->left, right->right)
            && areMirror(left->right, right->left);
    }
};
// @lc code=end
