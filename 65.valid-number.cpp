// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem65.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start

#include<map>
#include <ctype.h>
#include <exception>

enum charType
{
    INVALID,
    SIGN,
    DIGIT,
    DOT,
    E
};

class Solution {
    charType types[128];
    int len;

    public:
    Solution()
    {
        int size = sizeof (charType) * 128;
        memset(types, 0, size);

        types['-'] = SIGN;
        types['+'] = SIGN;
        types['.'] = DOT;
        types['e'] = E;
        types['E'] = E;
        types['0'] = DIGIT;
        types['1'] = DIGIT;
        types['2'] = DIGIT;
        types['3'] = DIGIT;
        types['4'] = DIGIT;
        types['5'] = DIGIT;
        types['6'] = DIGIT;
        types['7'] = DIGIT;
        types['8'] = DIGIT;
        types['9'] = DIGIT;
    }

public:
    bool isNumber(string s) {
        int i = 0;
        len = s.length();
        while (i < len) {
            if (types[s[i++]] == 0) return false;
        }
        i = 0;

        getSign(s, i);

        int digitsLen = getDigits(s, i);

        int dotLen = getDot(s, i);
        i += dotLen;

        int digitsLen2 = getDigits(s, i);

        if (digitsLen + digitsLen2 == 0) return false;
        if (digitsLen2 > 0 && dotLen == 0) return false;

        int eLen = getE(s, i);
        i += eLen;

        if (eLen > 0)
        {
            getSign(s, i);

            digitsLen = getDigits(s, i);

            if (digitsLen == 0) return false;
        }

        return i == len;
    }

    void getSign(string& s, int& i)
    {
        if (i == len) return;

        if (types[s[i]] == SIGN)
        {
            ++i;
        }
    }

    int getDot(string& s, int i)
    {
        if (i == len) return 0;

        return types[s[i]] == DOT ? 1 : 0;
    }

    int getE(string& s, int i)
    {
        if (i == len) return 0;

        return types[s[i]] == E ? 1 : 0;
    }

    int getDigits(string& s, int& i)
    {
        int start = i;
        while (i < len)
        {
            if (types[s[i]] != DIGIT) {
                break;
            }
            ++i;
        }

        return i - start;
    }
};
// @lc code=end