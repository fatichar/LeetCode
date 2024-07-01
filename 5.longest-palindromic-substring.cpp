// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem5.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<pair<int, int>> pairs;
        int len = s.length();

        char c = s[0];
        // palindromes with 2 or more repeating chars at the center
        for (int i = 1; i < len;)
        {
            if (s[i] == c)
            {
                pair p(i-1, i);
                do {
                    ++i;
                } while (s[i] == c);

                p.second = i-1;
                pairs.push_back(p);
            }
            c = s[i++];
        }

        // palindromes with a unique char at the center
        for (int i = 1; i < len - 1; ++i)
        {
            if (s[i+1] == s[i-1])
            {
                if (s[i-1] != s[i]) pairs.push_back(pair(i-1, i+1));
                else ++i; // all 3 same, so skip 2 steps instead of 1
            }
        }

        int max = 1, maxStart = 0;
        for (auto& p : pairs)
        {
            // try to grow the palindrome specified by p, equally in both the directions
            int len = getPalindromeLen(s, p.first, p.second);
            if (len > max)
            {
                max = len;
                // originalLen = p.second - p.first + 1;
                int growth = len + p.first - p.second - 1;
                maxStart = p.first - growth/2;
            }
        }

        return s.substr(maxStart, max);
    }

    int getPalindromeLen(const string& s, int left, int right)
    {
        // BB, left = 0, right = 1, last = 1
        int last = s.length() - 1;

        while (left > 0 && right < last)
        {
            if (s[--left] != s[++right]) return right - left - 1;
        }
        return right - left + 1;
    }
};
// @lc code=end
