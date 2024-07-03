/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> done;
        done.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (!(done.insert(nums[i])).second)  return true;
        }
        return false;
    }
};
// @lc code=end
