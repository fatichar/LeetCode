/*
 * @lc app=leetcode id=58 lang=csharp
 *
 * [58] Length of Last Word
 */

// @lc code=start
public class Solution {
    public int LengthOfLastWord(string s) {
        var start = s.Length;
        while (start > 0)
        {
            if (s[--start] != ' ') break;
        }
        var end = start;
        while (--end > -1)
        {
            if (s[end] == ' ') break;
        }
        return start - end;
    }
}
// @lc code=end
