/*
 * @lc app=leetcode id=27 lang=csharp
 *
 * [27] Remove Element
 */

// @lc code=start
public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int u = 0;
        foreach (int num in nums)
        {
            if (num != val)
            {
                nums[u++] = num;
            }
        }
        return u;
    }
}
// @lc code=end
