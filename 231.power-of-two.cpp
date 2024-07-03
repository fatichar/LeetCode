/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 0) {
            if (n == 1) return true;
            if (n&1) return false;
            n >>= 1;
        }
        return false;
    }
};
// @lc code=end
