// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return isBalanced(root, 1);
    }

    // returns height if balanced, else 0
    int isBalanced(TreeNode* root, int level) {
        if (root == nullptr) return level;

        int lh = isBalanced(root->left, 1+level);
        if (lh < 1) return false;

        int rh = isBalanced(root->right, 1+level);
        if (rh < 1) return false;

        return abs(lh - rh) < 2 ? max(lh, rh) : 0;
    }

    // void addHeights(TreeNode* root, int level, vector<int>& heights) {
    //     if (root->left == nullptr && root->right == nullptr)    heights.push_back(level);

    //     if (root->left != nullptr)  addHeights(root->left,  level+1, heights);
    //     if (root->right != nullptr) addHeights(root->right, level+1, heights);
    // }
};
// @lc code=end
