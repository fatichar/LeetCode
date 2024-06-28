/*
 * @lc app=leetcode id=13 lang=csharp
 *
 * [13] Roman to Integer
 */

// @lc code=start
public class Solution
{
    static int[] Romans = new int[128];

    static Solution()
    {
        Romans['I'] = 1;
        Romans['V'] = 5;
        Romans['X'] = 10;
        Romans['L'] = 50;
        Romans['C'] = 100;
        Romans['D'] = 500;
        Romans['M'] = 1000;
    }

    public int RomanToInt(string s)
    {
        int len = s.Length;
        int ans = 0;
        int i = 0;
        while ( i < len)
        {
            int current = Romans[s[i]];

            if (i + 1 < len)
            {
                int next = Romans[s[i+1]];
                if (next > current)
                {
                    ans += next - current;
                    i += 2;
                    continue;
                }
            }
            ans += current;
            ++i;
        }

        return ans;
    }
}
// @lc code=end
