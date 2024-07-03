/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> pascal(rows);
        pascal[0].push_back(1);

        int r = 1;
        while (r < rows) {
            vector<int>& row = pascal[r];
            vector<int>& lastRow = pascal[r-1];
            row.push_back(1);

            for (int c = 1; c < r; ++c) {
                int n = lastRow[c-1] + lastRow[c];
                row.push_back(n);
            }
            row.push_back(1);
            ++r;
        }

        return pascal;
    }
};
// @lc code=end
