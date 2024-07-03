// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem169.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <unordered_map>
#include <set>

class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> map;
    //     set<int> left_, right;

    //     if (nums.size() == 1) return nums[0];


    //     int maj = 0, count = 0;
    //     // middle element is added to both left and right
    //     for (int i = 0; i < (nums.size()+1)/2; ++i) {
    //         left_.insert(nums[i]);
    //     }
    //     for (int i = nums.size()/2; i < nums.size(); ++i) {
    //         int n = nums[i];
    //         if (left_.contains(n))
    //             right.insert(n);
    //     }
    //     set<int> left;
    //     for (int l : left_) {
    //         if (right.contains(l)) {
    //             left.insert(l);
    //         }
    //     }

    //     set<int> & merged = left;
    //     merged.insert(right.begin(), right.end());

    //     vector<int> small;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int n = nums[i];
    //         if (merged.contains(n))
    //             small.push_back(n);
    //     }

    //     return majorityElement_map(small);
    // }

    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        int maj = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const auto & it = map.find(nums[i]);
            if (it != map.end()) {
                it->second++;
                if (it->second > count) {
                    maj = it->first;
                    count = it->second;
                }
            } else {
                map[nums[i]] = 1;
                if (count == 0) {
                    maj = nums[i];
                    count = 1;
                }
            }
        }

        // for (auto it = map.begin(); it != map.end(); it++)
        // {
        //     if (it->second > count) {
        //         maj = it->first;
        //         count = it->second;
        //     }
        // }

        return maj;
    }
};
// @lc code=end
