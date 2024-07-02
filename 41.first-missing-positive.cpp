// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem41.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    // int firstMissingPositive(vector<int>& nums) {
    //     bool oneFound = false;

    //     for (size_t i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] == 1)
    //         {
    //             oneFound = true;
    //             break;
    //         }
    //     }
    //     if (!oneFound) return 1;

    //     return firstMissingPositive_(nums);
    // }

    int firstMissingPositive(vector<int>& nums) {
        bool* flags = new bool[nums.size() + 1];
        memset(flags, 0, sizeof(bool)*(nums.size() + 1));

        for (size_t i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n > 0 && n < nums.size() + 1)
            {
                flags[n] = true;
            }
        }
        for (size_t i = 1; i < nums.size() + 1; i++)
        {
            if (!flags[i]) return i;
        }

        return nums.size() + 1;
    }
};
// @lc code=end
