/*
 * @lc app=leetcode id=28 lang=csharp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
public class Solution {
    public int StrStr(string haystack, string needle) {
        int hl = haystack.Length, nl = needle.Length;
        if (nl > hl) return -1;

        // key = char, value = indices of char in haystack
        var dic = new Dictionary<int, List<int>>(26);
        for (int f = 0; f < 26; ++f)
        {
            dic.Add(f, new List<int>());
        }

        for (int h = 0; h < hl; ++h)
        {
            dic[haystack[h] - 'a'].Add(h);
        }

        var found = new List<List<int>>();
        for (int n = 0; n < nl; ++n)
        {
            var indices = dic[needle[n] - 'a'];
            if (indices.Count == 0) return -1;
            found.Add(indices);
        }

        return -1;
    }

    public int StrStr_flags(string haystack, string needle) {
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
            if (n == nl)    return hs;
        }

        return -1;
    }
}
// @lc code=end

