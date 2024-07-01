/*
 * @lc app=leetcode id=171 lang=csharp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
public class Solution {
    public int TitleToNumber(string title) {
        int col = 0;
        foreach (char c in title)
        {
            col = col * 26 + c - 'A' + 1;
        }
        return col;
    }
}
// @lc code=end
