// @before-stub-for-debug-begin
#include <vector>
#include <string>

#include <limits>
#include "commoncppproblem7.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        int y = 0, max = numeric_limits<int>::max(), min = numeric_limits<int>::min();

        if (x > 0)
        {
            while (x != 0)
            {
                int r = x%10;
                if (y > (max - r)/10)  return 0;

                y = y*10 + r;
                x /= 10;
            }
        }
        else
        {
            while (x != 0)
            {
                int r = x%10;
                if (y < (min - r)/10)  return 0;

                y = y*10 + r;
                x /= 10;
            }
        }

        return y;
    }
};
// @lc code=end
