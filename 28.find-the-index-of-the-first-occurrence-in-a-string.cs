/*
 * @lc app=leetcode id=28 lang=csharp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
public class Solution
{
    public int StrStr(string haystack, string needle)
    {
        return StrStr_indices(haystack, needle);
    }

    public int StrStr_indices(string haystack, string needle)
    {
        int hl = haystack.Length, nl = needle.Length;
        if (nl > hl) return -1;

        // key = char, value = indices of char in haystack
        var dic = new ICollection<int>[26];
        for (int f = 0; f < 26; ++f)
        {
            dic[f] = new List<int>(hl);
        }

        // populate dic with indices of haystack
        for (int h = 0; h < hl; ++h)
        {
            dic[haystack[h] - 'a'].Add(h);
        }

        // list of indices of each needle char in haystack
        var found = new List<ICollection<int>>(nl);
        for (int n = 0; n < nl; ++n)
        {
            var indices = dic[needle[n] - 'a'];
            if (indices.Count == 0) return -1;
            found.Add(indices);
        }

        var begin = found[0];
        foreach (int start in begin)
        {
            if (start + nl > hl) continue;

            int j = 1, end = start + j;
            for (; j < nl; ++j, ++end)
            {
                var indices = found[j];
                if (!indices.Contains(end)) break;
            }

            if (j == nl) return start;
        }

        return -1;
    }

    public int StrStr_flags(string haystack, string needle)
    {
        int hl = haystack.Length, nl = needle.Length;
        if (nl > hl) return -1;

        bool[] flags = new bool[26];
        for (int n = 0; n < nl; ++n)
        {
            flags[needle[n] - 'a'] = true;
        }
        for (int h = 0; h < hl; ++h)
        {
            flags[haystack[h] - 'a'] = false;
        }
        for (int f = 0; f < 26; ++f)
        {
            if (flags[f]) return -1;
        }


        for (int hs = 0, max = hl - nl; hs <= max; ++hs)
        {
            int n = 0;
            for (int h = hs; n < nl; ++h, ++n)
            {
                if (haystack[h] != needle[n]) break;
            }
            if (n == nl) return hs;
        }

        return -1;
    }
}
// @lc code=end
