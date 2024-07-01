/*
 * @lc app=leetcode id=70 lang=csharp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
public class Solution
{
    public int ClimbStairs(int n)
    {
        int max2s = n / 2;
        long totalWays = 0; // Initialize to 0

        for (int twos = 0; twos <= max2s; ++twos)
        {
            int ones = n - 2 * twos;
            totalWays += Comb(ones + twos, twos);
        }

        return totalWays;
    }

    // Method to calculate combinations: n! / (k! * (n-k)!)
    private int Comb(int n, int k)
    {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;

        long res = 1;
        for (int i = 1; i <= k; i++)
        {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    static int fact(int n)
    {
        if (n < 2) return 1;

        int f = 2;
        for (int i = 3; i <= n; ++i)
        {
            f *= i;
        }
        return f;
    }
}
// @lc code=end
