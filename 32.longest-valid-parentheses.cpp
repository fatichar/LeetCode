// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // s = "(())()(()((";
        int longest = 0, start = 0, ongoingLen = 0, ongoingStart = 0;

        vector<int> openIndices;
        vector<pair<int, int>> pairs;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c == '(')
            {
                openIndices.push_back(i);
            }
            else // ')'
            {
                if (openIndices.empty())
                {
                    int len = clear(pairs);
                    if (longest < len)
                        longest = len;
                }
                else
                {
                    int open = openIndices.back();
                    openIndices.pop_back();

                    while (!pairs.empty())
                    {
                        auto &lastPair = pairs.back();
                        // if lastPair is a subset of the current pair, discard it
                        if (lastPair.first > open)
                        {
                            pairs.pop_back();
                        }
                        else break;
                    }
                    pairs.push_back(pair(open, i));
                }
            }
        }
        if (!pairs.empty())
        {
            int len = clear(pairs);
            if (longest < len)
                longest = len;
        }
        return longest;
    }

    int clear(vector<pair<int, int>>& pairs)
    {
        if (pairs.empty()) return 0;

        int last = pairs[0].second, total = last - pairs[0].first + 1, longest = total;

        for (int i = 1; i < pairs.size(); ++i)
        {
            auto & pair = pairs[i];
            if (pair.first > last + 1)
            {
                // gap found, reset
                total = 0;
            }
            int len = pair.second - pair.first + 1;
            total += len;
            if (total > longest) longest = total;

            last = pair.second;
        }
        return longest;
    }
};
// @lc code=end

/*
 *   ()(()

        if open while stack is not empty
            ongoingStart remains same
            start = i

 */