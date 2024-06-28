/*
 * @lc app=leetcode id=35 lang=csharp
 *
 * [35] Search Insert Position
 */

// @lc code=start
public class Solution {
    public int SearchInsert(int[] nums, int target) {
        var end = nums.Length;
        var begin = 0;

        while (begin < end)
        {
            var mid = (begin + end)/2;
            if (nums[mid] == target) return mid;

            if (nums[mid] < target) begin = mid+1;
            else end = mid;
        }
        return end;
    }
}
// @lc code=end
