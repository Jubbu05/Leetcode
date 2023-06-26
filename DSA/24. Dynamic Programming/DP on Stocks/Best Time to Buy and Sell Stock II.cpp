// 0 -> NOT BUY
// 1 -> BUY
class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;

        if (buy == 1)
        {
            // buy
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp);
            int notTake = 0 + f(ind + 1, 1, prices, n, dp);
            profit = max(take, notTake);
        }
        else
        { 
            // sell
            int sell = prices[ind] + f(ind + 1, 1, prices, n, dp);
            int notSell = 0 + f(ind + 1, 0, prices, n, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, n, dp);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // base case
        dp[n][0] = dp[n][1] = 0;

        // recursion 0 -> n buy 1 -> 0
        // tabulation n -> 0 buy 0 -> 1
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if (buy == 1)
                { // buy
                    int take = -prices[ind] + dp[ind + 1][0];
                    int notTake = 0 + dp[ind + 1][1];
                    profit = max(take, notTake);
                }
                else
                { // sell
                    int sell = prices[ind] + dp[ind + 1][1];
                    int notSell = 0 + dp[ind + 1][0];
                    profit = max(sell, notSell);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};