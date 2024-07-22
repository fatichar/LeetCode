/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;


        int start = nums[0], last = start;
        for (int i = 1; i < nums.size(); i++)
        {
            int& n = nums[i];
            if (n != last+1) {
                stringstream ss;
                ss << start;
                if (start != last)
                    ss << "->" << last;
                ans.emplace_back(ss.str());

                start = n;
            }
            last = n;
        }

        stringstream ss;
        ss << start;
        if (start != last)
            ss << "->" << last;
        ans.emplace_back(ss.str());

        return ans;
    }
};
// @lc code=end
