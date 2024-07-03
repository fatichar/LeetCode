// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
        int height = 1;
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        // count the right side nodes
        // left side nodes can be found from the height
        for (auto left = root->left; left != nullptr; left = left->left) {
            ++height;
        }

        int maxCount = (1<<height) - 1;
        int missing = nullRightCount(root, 1);
        return maxCount - missing;
    }

    int nullRightCount(TreeNode* root, int level) {
        if (root == nullptr) return 0;
        if (root->left == nullptr) return (height - level)*2;

        if (root->right == nullptr) return 1;

        return nullRightCount(root->left, level+1) + nullRightCount(root->right, level+1);
    }

};
// @lc code=end
