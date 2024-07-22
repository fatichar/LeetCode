// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem46.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans = {{nums[0]}};
        ans.reserve(fact(len));

        // start case

        for (int i = 1; i < len; i++)
        {
            int n = nums[i];
            //for each entry in ans, create all combos by including nums[i]
            int count = ans.size();
            for (int j = 0; j < count; j++)
            {
                for (int k = 0; k < ans[j].size(); k++)
                {
                    auto row = ans[j];
                    row.insert(row.begin() + k, n);
                    ans.emplace_back(row);
                }
            }
            for (int j = 0; j < count; j++)
            {
                ans[j].push_back(n);
            }
        }

        return ans;
    }

    int fact(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans *= i;
        }
        return ans;
    }
};
// @lc code=end