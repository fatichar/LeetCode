/*
 * @lc app=leetcode id=1 lang=csharp
 *
 * [1] Two Sum
 */

// @lc code=start
public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        return TwoSum_cpu(nums, target);
        // return TwoSum_memory(nums, target);
    }

    // static int[] TwoSum_memory(int[] nums, int target)
    // {
    //     var complementSet = new HashSet<int>(nums.Length);
    //     for (int i = 0; i < nums.Length; i++)
    //     {
    //         var num = nums[i];
    //         var complement = target - num;
    //         if (complementSet.TryGetValue(num, out int complementIndex))
    //         {
    //             complementIndex = findIndex(nums, complement);
    //             return new int[] { complementIndex, i };
    //         }
    //         else
    //         {
    //             complementSet.Add(complement);
    //         }
    //     }
    //     return new int[] { -1, -1 };
    // }

    // static int findIndex(int[] arr, int num)
    // {
    //     for (int i = 0; i < arr.Length; i++)
    //     {
    //         if (arr[i] == num)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    /*
    Your runtime beats 89.2 % of csharp submissions
Your memory usage beats 18.14 % of csharp submissions (48.1 MB)
    */
    static int[] TwoSum_cpu(int[] nums, int target)
    {
        var complementMap = new Dictionary<int, int>();
        int i = 0;
        foreach (int num in nums)
        {
            // var complement = target - num;
            if (complementMap.TryGetValue(num, out int numIndex))
            {
                return [numIndex, i];
            }
            else
            {
                complementMap.TryAdd(target - num, i);
            }
            ++i;
        }
        return [-1, -1];
    }
}
/*
//[1,1,2,1,3,5]\n5
//[7,2,-2,-6]

i = 0
nums[i] = 2
complement[i] = 7
complementMap.ContainsKey(nums[i]) = false

i = 1
nums[i] = 7
complement[i] = 2
complementMap.ContainsKey(nums[i]) = true
return new int[] { 0, 1 }
*/
// @lc code=end
