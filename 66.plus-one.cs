/*
 * @lc app=leetcode id=66 lang=csharp
 *
 * [66] Plus One
 */

// @lc code=start
public class Solution {
    public int[] PlusOne(int[] digits) {
        int len = digits.Length, i = len;
        while (--i > -1)
        {
            if (digits[i] < 9)
            {
                ++digits[i];
                break;
            }
            digits[i] = 0;
        }
        if (digits[0] == 0)
        {
            var result = new int[len + 1];
            result[0] = 1;
            for (i = 1; i <= len; ++i)
            {
                result[i] = digits[i-1];
            }
            return result;
        }

        return digits;
    }
}
// @lc code=end
