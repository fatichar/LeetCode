/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            num = sum(num);
        }
        return num;
    }

    int sum(int n) {
        int total = 0;
        while (n > 0) {
            total += n%10;
            n /= 10;
        }
        return total;
    }
};
// @lc code=end
