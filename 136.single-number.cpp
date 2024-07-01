// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem136.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bool flags[60001];
        memset(flags, 0, sizeof(flags));

        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int num = nums[i] + 30000;

            flags[num] = !flags[num];
        }

        for (int i = 0; i < 60001; ++i)
        {
            if (flags[i])   return i - 30000;
        }
        return 0;
    }

    int singleNumber_set(vector<int>& nums) {
        int size = nums.size();
        set<int> bag;
        for (int i = 0; i < size; ++i)
        {
            int num = nums[i];

            if (bag.contains(num))
            {
                bag.erase(num);
            }
            else bag.insert(num);
        }
        return *bag.begin();
    }
};
// @lc code=end
