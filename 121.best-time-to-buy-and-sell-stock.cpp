/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0, profit = 0;
        int min = prices[0], max = min, len = prices.size();

        for (int i = 1; i < len; ++i)
        {
            int price = prices[i];

            if (price > prices[i - 1])
            {
                max = price;
                profit = max - min;
                if (profit > max_profit)
                    max_profit = profit;
            }
            else
            {
                if (price < min)
                {
                    min = price;
                    max = min;
                    profit = 0;
                }
            }
        }

        return max_profit;
    }
};
// @lc code=end
