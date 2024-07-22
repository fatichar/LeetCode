/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        stringstream merged;
        int i = 0;
        int minLen = min(word1.length(), word2.length()), maxLen = max(word1.length(), word2.length());
        string& bigger = maxLen == word1.length() ? word1 : word2;

        while (i < minLen)
        {
            merged << word1[i] << word2[i];
            ++i;
        }
        while (i < maxLen)
        {
            merged << bigger[i];
            ++i;
        }
        return merged.str();
    }
};
// @lc code=end
