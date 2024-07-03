// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem10.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string& s, string& p) {
        int pi = 0, si = 0, sl = s.length(), pl = p.length();

        char lastP;
        
        while (pi < pl && si < sl) {
            char c = p[pi];
            switch (c) {
                case '.':
                    lastP = c;
                    ++pi;
                    ++si;
                break;
                case '*':
                    if (s[si] == lastP || lastP == '.') {
                        ++si;   // continue to match with *
                    } else {
                        lastP = c;
                        ++pi;   // match s[i] with next char of pattern
                    }
                break;
                 default:
                    if (s[si] == p[pi]) {
                        lastP = c;
                        ++pi;
                        ++si;
                    } else if (pi < pl-1) {
                        if (p[pi+1] == '*') {
                            // zero matches for *
                            pi += 2;
                            lastP = '*';
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                break;
            }
        }

        if (si != sl) return false;
        if (pi == pl) return true;
        if (pi == pl-1) return p[pi] == '*';

        return false;
    }
};
// @lc code=end
