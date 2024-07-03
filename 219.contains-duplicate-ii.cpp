/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indices;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = indices.find(nums[i]);
            if (it == indices.end()) {
                indices[nums[i]] = i;
            } else {
                if (abs(it->second - i) <= k)
                    return true;
                it->second = i;
            }
        }
        return false;
    }
};
// @lc code=end
