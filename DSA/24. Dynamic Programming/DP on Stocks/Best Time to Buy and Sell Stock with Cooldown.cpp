// COOLDOWN - Can't buy just after selling
class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
        {
            // buy
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp);
            int notTake = 0 + f(ind + 1, 1, prices, n, dp);
            dp[ind][buy] = max(take, notTake);
        }
        else
        {
            // sell
            int sell = prices[ind] + f(ind + 2, 1, prices, n, dp);
            int notSell = 0 + f(ind + 1, 0, prices, n, dp);
            dp[ind][buy] = max(sell, notSell);
        }
        return dp[ind][buy];
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

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int take = -prices[ind] + dp[ind + 1][0];
                    int notTake = 0 + dp[ind + 1][1];
                    dp[ind][1] = max(take, notTake);
                }

                else
                {
                    int sell = prices[ind] + dp[ind + 2][1];
                    int notSell = 0 + dp[ind + 1][0];
                    dp[ind][buy] = max(sell, notSell);
                }
            }
        }
        return dp[0][1];
    }
};