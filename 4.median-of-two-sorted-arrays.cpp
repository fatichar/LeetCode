// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // inclusive indices
        int l1 = 0, l2 = 0, r1 = nums1.size() - 1, r2 = nums2.size() - 1;
        int throws, throw1, throw2;
        while ((l1 <= r1) && (l2 <= r2))
        {
            if (r1 == l1 && r2 == l2)
            {
                return (nums1[l1]+(float)nums2[l2])/2.0;
            }
            float m1 = median(nums1, l1, r1);
            float m2 = median(nums2, l2, r2);

            if (m1 > m2)
            {
                throw1 = (r1-l1)/2;
                throw2 = (r2-l2)/2;
                throws = min(throw1, throw2);
                if (throws == 0) break;
                r1 -= throws;
                l2 += throws;
            }
            else if (m1 < m2)
            {
                throw1 = (r2-l2)/2;
                throw2 = (r1-l1)/2;
                throws = min(throw1, throw2);
                if (throws == 0) break;
                r2 -= throws;
                l1 += throws;
            }
            else return m1;
        }
        return r1-l1 > r2-l2
            ? mergedMedian(nums1, l1, r1, nums2, l2, r2)
            : mergedMedian(nums2, l2, r2, nums1, l1, r1);
    }

    float mergedMedian(vector<int>& big, int l1, int r1, vector<int>& small, int l2, int r2)
    {
        int i = l1, j = l2;
        for (; l1 <= r1 && l2 <= r2;)
        {
            if (big[l1] < small[l2])
            {
                ++l1;
            }
            else
            {
                ++l2;
            }
            if (big[r1] > small[r2])
            {
                --r1;
            }
            else
            {
                --r2;
            }
            if (l1 == r1 && l2 == r2)
                return (big[l1]+(float)small[l2])/2.0;
        }


        return l1 <= r1 ? median(big, l1, r1) : median(small, l2, r2);
    }

    float median(vector<int>& nums, int start, int end)
    {
        int s = end - start + 1;
        if (s%2 == 1) // odd size
        {
            return nums[start + s/2];
        }
        return (nums[start + s/2 - 1] + (float)nums[start + s/2]) / 2;
    }
};
// @lc code=end
