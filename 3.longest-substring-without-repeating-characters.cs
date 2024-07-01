/*
 * @lc app=leetcode id=3 lang=csharp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int len = s.Length;
        if (len < 2) return len;

        int start = 0, longest = 0, latest = 0;
        int i = 0;
        foreach (char c in s)
        {
            int existingIndex = IndexOf(s, start, i, c);
            if (existingIndex != -1)
            {
                // duplicate found, restart
                latest = i - start;
                if (latest > longest) longest = latest;

                start = existingIndex + 1;
            }
            ++i;
        }
        latest = len - start;
        if (latest > longest) longest = latest;

        return longest;
    }

    int IndexOf(string s, int start, int end, char c)
    {
        for (int i = start; i < end; ++i)
        {
            if (s[i] == c) return i;
        }
        return -1;
    }
}
// @lc code=end
