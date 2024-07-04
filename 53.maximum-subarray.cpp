// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int i = 0, positives = 0;
        for (; i < nums.size(); ++i)
        {
            positives += (nums[i] > 0);
            if (positives > 1)
                break;
        }
        if (i == nums.size()) // not +ve number
            return max(nums);

        int max = -9999999, sum = 0;
        for (int r = 0; r < nums.size();)
        {
            if (nums[r] >= -sum)
            {
                sum += nums[r++];
                if (max < sum)
                {
                    max = sum;
                }
            }
            else
            {
                // negative number can't increase the sum, so stop
                sum = 0;
                ++r;
            }
        }

        return max;
    }

    int max(const vector<int> &nums)
    {
        int max = -99999999;
        for (int n : nums)
        {
            if (n > max) max = n;
        }
        return max;
    }
};
// @lc code=end
