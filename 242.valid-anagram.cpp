/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
    int counts[128];
public:
    bool isAnagram(string &s, string &t) {
        if (s.length() != t.length()) return false;

        memset(counts, 0, 128*sizeof(int));

        for (char c : s) {
            counts[c]++;
        }
        for (char c : t) {
            counts[c]--;
        }

        for (size_t i = 0; i < 128; i++)
        {
            if (counts[i] != 0) return false;
        }

        return true;
    }
};
// @lc code=end
