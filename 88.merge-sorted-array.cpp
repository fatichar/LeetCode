// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;

        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }
        vector<int>& remaining = i == m ? nums2 : nums1;
        int r = i == m ? j : i;
        int k = i == m ? n : m;
        while (r < k)   merged.push_back(remaining[r++]);

        for (int q = 0; q < n+m; ++q)
        {
            nums1[q] = merged[q];
        }
    }
};
// @lc code=end
