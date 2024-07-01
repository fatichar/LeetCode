/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder_recursive(result, root);
        return result;
    }

    void inorderTraversal_iterative(vector<int>& result, TreeNode* root) {
        if (root == nullptr)   return;

        vector<TreeNode*> nodes;

        // inorder(result, root);
        auto current = root;
        nodes.push_back(current);

        bool pushed = true;
        while (!nodes.empty())
        {
            if (current->left == nullptr || !pushed)
            {
                result.push_back(current->val);
                nodes.pop_back();
                if (current->right != nullptr)
                {
                    current = current->right;
                    nodes.push_back(current);
                    pushed = true;
                }
                else
                {
                    if (nodes.empty()) break;

                    current = nodes.back();
                    pushed = false;
                }
            }
            else
            {
                current = current->left;
                nodes.push_back(current);
                pushed = true;
            }
        }
    }

    void inorder_recursive(vector<int>& result, TreeNode* root)
    {
        if (root == nullptr)   return;

        inorder_recursive(result, root->left);
        result.push_back(root->val);
        inorder_recursive(result, root->right);
    }
};
// @lc code=end
