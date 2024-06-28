/*
 * @lc app=leetcode id=69 lang=csharp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
public class Solution {
    public int MySqrt(int x) {
        if (x < 2) return x;

        // xx is min 3
        long lower = 1, upper = x/2 + 1;

        while (lower < upper)
        {
            long avg = (lower + upper)/2;

            var sqr = avg * avg;
            if (sqr > x) upper = avg;

            else if (sqr == x) return (int)avg;

            // else if (lower == avg) ++lower;
            else lower = avg + 1;
        }
        return (int)(lower - 1);
    }
}
/*
x = 4

1. lower = 1    upper = 2
avg = 1         sqr = 1

*/
// @lc code=end
