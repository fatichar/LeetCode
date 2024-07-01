// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem48.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(), m = n-1, rmax = n/2;

        for (int r = 0; r < rmax; r++)
        {
            for (int c = r; c < m - r; c++)
            {
                int i = mat[r][c];     // save

                mat[r][c] = mat[m-c][r];
                mat[m-c][r] = mat[m-r][m-c];
                mat[m-r][m-c] = mat[c][m-r];
                mat[c][m-r] = i;
            }
        }
    }
};
// @lc code=end
