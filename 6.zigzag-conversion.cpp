// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem6.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include <sstream>
// @lc code=start
class Solution {
public:
    string convert(string s, int rows) {
        if (rows == 1) return s;

        stringstream ss;

        int row = 0, maxJump = 2*(rows - 1), jump = maxJump, len = s.length();
        if (rows > len) rows = len;

        for (int i = 0; row < rows;)
        {
            ss << s[i];

            i += jump;
            if (jump < maxJump) jump = maxJump - jump;

            if (i >= len)
            {
                i = ++row;

                if (row == rows - 1) jump = maxJump;
                else jump = 2*(rows - row - 1);
            }
        }
        return ss.str();
    }
};
// @lc code=end
