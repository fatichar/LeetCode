// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{

public:
    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty()) return result;

        int len = digits.size();
        char * current = new char[len + 1];
        current[len] = '\0';

        // the current indices for digits in table
        vector<int> maxIndex(digits.length());
        vector<int> index(digits.length());
        // populate end indices
        for (int i = 0; i < len; i++)
        {
            int d = digits[i] - '2';
            maxIndex[i] = table[d].size()-1;
            index[i] = 0;
        }

        for (size_t i = 0; i < len; i++)
        {
            int d = digits[i] - '2';
            current[i] = table[d][0];
        }

        result.emplace_back(current, len);

        do
        {
            for (int i = len - 1; i >= 0; --i)
            {
                if (index[i] < maxIndex[i]) {
                    ++index[i];

                    int pos = index[i];
                    int d = digits[i] - '2';
                    current[i] = table[d][pos];
                    break;
                }
                // can't increment, max size reached. Set to zero.
                // when first index has to be set to zero, it means all strings
                // are done
                if (i == 0) {
                    delete[] current;
                    return result;
                }

                index[i] = 0;
                int d = digits[i] - '2';
                current[i] = table[d][0];
            }

            // string s(current, len);
            result.emplace_back(current, len);
        } while (true);

        return result;
    }
};
// @lc code=end
