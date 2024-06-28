/*
 * @lc app=leetcode id=26 lang=csharp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
public class Solution {
    public int RemoveDuplicates(int[] nums)
    {
        int u  = 1, l = nums.Length;
        for (int i = 1; i < l; ++i)
        {
            var num = nums[i];
            if (nums[u-1] < num)
            {
                nums[u] = num;
                ++u;
            }
        }
        return u;
    }
}
// @lc code=end

