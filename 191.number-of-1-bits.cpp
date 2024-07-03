/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int ones = 0;
        while (n != 0) {
            ones += n & 1;
            n >>= 1;
        }
        return ones;
    }
};
// @lc code=end
