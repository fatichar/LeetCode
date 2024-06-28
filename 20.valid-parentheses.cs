/*
 * @lc app=leetcode id=20 lang=csharp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
public class Solution {
    static char[] closer = new char[128];
    static Solution()
    {
        closer[')'] = '(';
        closer[']'] = '[';
        closer['}'] = '{';
    }

    public bool IsValid(string s) {
        int len = s.Length;
        if (len%2 == 1) return false;

        char[] stack = new char[len/2 + 1];   //4
        stack[0] = 'A';
        stack[1] = s[0];    //(
        int top = 1;    // index of topmost element

        for (int i = 1; i < len; ++i)
        {
            var current = s[i]; //)
            if (stack[top] == closer[current])
            {
                top--;  // pop
            }
            else
            {
                if (top == len/2) return false;
                stack[++top] = current; // push
            }
        }

        return top == 0;
    }
}
// @lc code=end
