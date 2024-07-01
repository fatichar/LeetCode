/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            char f = s[i];
            if (!isalnum(f))
            {
                ++i;
                continue;
            }
            char b = s[j];
            if (!isalnum(b))
            {
                --j;
                continue;
            }
            if (tolower(b) != tolower(f))   return false;

            ++i;
            --j;
        }
        return true;
    }
};
// @lc code=end
