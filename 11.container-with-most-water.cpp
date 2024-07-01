// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem11.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int hs = heights.size(), iMax = hs - 1;
        vector<int> left, right;

        int last = 0;
        for (int l = 0, i = 0; i < iMax; ++i)
        {
            long h = heights[i];
            if (h > last)
            {
                left.push_back(i);
                ++l;
                last = h;
            }
        }
        int ls = left.size();
        if (ls == 0)    return 0;

        int minLi = left[0];
        last = 0;

        for (int r = 0, i = iMax; i > minLi; --i)
        {
            long h = heights[i];
            if (h > last)
            {
                right.push_back(i);
                ++r;
                last = h;
            }
        }
        if (right.size() == 0)   return 0;
        int maxRi = right[0];

        //remove indices from left which are not less than the maxRi
        for (int l = ls; l > 0; )
        {
            if (left[--l] >= maxRi)   left.pop_back();
            else break;
        }
        ls = left.size();

        int rightStart = 0;
        long maxArea = min(heights[0], heights[iMax]) * (iMax);
        for (int l = 0; l < ls; l++)
        {
            int li = left[l];
            long lh = heights[li];

            for (int r = rightStart; r < right.size(); r++)
            {
                int ri = right[r];
                if (ri <= li)
                    break;

                long rh = heights[ri];

                long area = min(rh, lh) * (ri - li);

                if (area > maxArea)
                    maxArea = area;

                // increased rh will be of no use if lh is already smaller
                if (rh >= lh)
                    break;
                else // these small ones are of no use with bigger lh
                {
                    ++rightStart;
                }
            }

            // increased lh will be of no use if max rh is already smaller
            if (lh > heights[right[right.size() - 1]])
                break;
        }

        return maxArea;
    }
};
// @lc code=end
