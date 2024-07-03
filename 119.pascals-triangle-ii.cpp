/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1);

        row[0] = 1;
        int r = 1;
        while (r < rowIndex) {
            row[r++] = 0;
        }
        row[rowIndex] = 1;

        int rows = rowIndex+1;
        r = 1;
        while (r++ < rows)
        {
            int last = row[0], c = 1;
            while (c <= rowIndex/2) {
                int temp = row[c];
                row[c] += last;
                last = temp;

                row[rowIndex-c] = row[c];

                ++c;
            }
        }

        return row;
    }
};
// @lc code=end
