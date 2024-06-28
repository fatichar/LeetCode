/*
 * @lc app=leetcode id=9 lang=csharp
 *
 * [9] Palindrome Number
 */

// @lc code=start
public class Solution {
    public bool IsPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0) return x == 0;

        int reverse = 0;
        int remainder = x;
        while (remainder > 0) {
            int d = remainder % 10;
            reverse = reverse * 10 + d;
            remainder = remainder / 10;
        }
        return x == reverse;
    }
}
// @lc code=end
