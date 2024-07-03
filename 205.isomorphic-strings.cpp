/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[128], rmap[128];
        memset(map, 0, 128);
        memset(rmap, 0, 128);

        for (int i = 0; i < s.length(); ++i) {
            char sc = s[i];
            char tc = t[i];
            if (map[sc] == 0) {
                if (rmap[tc] != 0) return false; // other char already mapped to tc
                map[sc] = tc;
                rmap[tc] = sc;
            } else {
                if (map[sc] != tc) return false; // sc is mapped to some other char
            }
        }

        return true;
    }
};
// @lc code=end
