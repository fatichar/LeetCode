/*
 * @lc app=leetcode id=14 lang=csharp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
public class Solution {
    int prefixLen;
    public string LongestCommonPrefix(string[] strs) {
        int count = strs.Length;
        if (count == 0) return "";

        var prefix = strs[0];
        prefixLen = prefix.Length;

        for (int i = 1; i < count; ++i)
        {
            var str = strs[i];
            int len = str.Length;

            if (len < prefixLen)
            {
                prefixLen = len;
            }
            else
            {
                len = prefixLen;
            }
            for (int j = 0; j < len; ++j)
            {
                if (str[j] != prefix[j])
                {
                    prefixLen = j;
                    break;
                }
            }
        }

        return prefix.Substring(0, prefixLen);
    }
}
// @lc code=end

/*
ABCDEF
ABCXXX

*/