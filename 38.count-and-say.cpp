// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem38.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start

#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        for (int i = 2; i <= n; i++)
        {
            last = runLengthEncode(last);
        }
        return last;
    }

    string runLengthEncode(const string& s) {
        stringstream ss;
        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            char c = s[i];
            if (c == s[i-1]) {
                ++count;
            }
            else {
                ss << (count);
                ss << s[i-1];
                count = 1;
            }
        }

        ss << (count);
        ss << s[s.length()-1];

        return ss.str();
    }
};
// @lc code=end
