/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 0, m = 0;
        while (i < 32) {
            m <<= 1;
            m += (n & (1 << i)) != 0;
            ++i;
        }

        return m;
    }
};
// @lc code=end
