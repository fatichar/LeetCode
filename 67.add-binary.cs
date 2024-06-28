/*
 * @lc app=leetcode id=67 lang=csharp
 *
 * [67] Add Binary
 */

// @lc code=start
public class Solution
{
    public string AddBinary(string a, string b)
    {
        int al = a.Length, bl = b.Length, ai = al, bi = bl;

        var sum = new List<char>(Math.Max(al, bl) + 1);

        var carry = 0;
        while (ai > 0 && bi > 0)
        {
            --ai; --bi;

            var s = a[ai] - '0' + b[bi] + carry;
            if (s > '1')
            {
                sum.Add((char)(s - 2));
                carry = 1;
            }
            else
            {
                sum.Add((char)s);
                carry = 0;
            }
        }

        string r = b;
        int ri = bi - 1;
        if (ai > 0)
        {
            r = a;
            ri = ai - 1;
        }
        while (ri > -1)
        {
            var s = r[ri--] + carry;
            if (s > '1')
            {
                sum.Add((char)(s - 2));
                carry = 1;
            }
            else
            {
                sum.Add((char)s);
                carry = 0;
            }
        }
        if (carry == 1)
        {
            sum.Add('1');
        }

        var sb = new StringBuilder();
        for (int i = sum.Count; i > 0;)
        {
            sb.Append(sum[--i]);
        }

        return sb.ToString();
    }
}
// @lc code=end
