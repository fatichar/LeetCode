/*
 * @lc app=leetcode id=168 lang=csharp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
public class Solution
{
    public string ConvertToTitle(int col)
    {
        var len = 0;
        var sb = new char[100];

        do
        {
            int r = (--col) % 26;
            sb[len++] = ((char)(r + 'A'));
            col = col / 26;
        } while (col > 0);

        Array.Reverse(sb, 0, len);
        return new string(sb, 0, len);
    }
}
// @lc code=end
