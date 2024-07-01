// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem8.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <ctype.h>
#include <limits>
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        // step 1: leading whitespace
        int start = 0;
        while (start < s.length() && s[start] == ' ')   ++start;

        if (start == s.length())    return 0;

        // step 2: sign
        bool negavive = false;
        if (s[start] == '-')
        {
            negavive = true;
            ++start;
        }
        else if (s[start] == '+')
        {
            ++start;
        }

        // step 3A: leading zeros
        while (start < s.length() && s[start] == '0')   ++start;

        // step 3B: conversion
        if (negavive) return toNegative(s, start);

        int result = 0, max = numeric_limits<int>::max();
        char c;
        while (start < s.length() && isdigit(c = s[start++]))
        {
            int d = c - '0';
            if (result > (max - d)/10)  return max;
            result = result * 10 + d;
        }

        return result;
    }

    int toNegative(string s, int start)
    {
        int result = 0, min = numeric_limits<int>::min();
        char c;
        while (start < s.length() && isdigit(c = s[start++]))
        {
            int d = c - '0';
            if (result < (min + d)/10)  return min;
            result = result * 10 - d;
        }
        return result;
    }
};
// @lc code=end
