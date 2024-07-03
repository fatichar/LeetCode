/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int sum = n, original = n;
        set<int> sums;

        do {
            n = sumOfDigits(n);
            if (sums.contains(n))   return false;
            sums.insert(n);
        } while (n != 1);

        return true;
    }

    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0)
        {
            int d = n%10;
            sum += d*d;
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end
