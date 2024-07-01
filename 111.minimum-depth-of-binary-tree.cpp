// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;

        int left = minDepth(root->left);
        if (left == 1)  return 2;

        int right = minDepth(root->right);
        if (right == 1) return 2;

        int min = left;
        if (min == 0 || (min > right && right > 0))    min = right;

        return min + 1;
    }
};
// @lc code=end
