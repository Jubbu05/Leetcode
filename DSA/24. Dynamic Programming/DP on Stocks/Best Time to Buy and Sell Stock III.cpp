class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<vector<int>>> &dp, int cap)
    {
        if (ind == n || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;
        if (buy == 1)
        {
            // buy
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp, cap);
            int notTake = 0 + f(ind + 1, 1, prices, n, dp, cap);
            profit = max(take, notTake);
        }
        else
        {
            // sell
            int sell = prices[ind] + f(ind + 1, 1, prices, n, dp, cap - 1);
            int notSell = 0 + f(ind + 1, 0, prices, n, dp, cap);
            profit = max(sell, notSell);
        }
        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int cap = 2;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, prices, n, dp, cap);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int cap = 2;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // NOT NEEDED TO WRITE THIS AS DP IS ALREADY INITIALIZED TO 0
        //  for (int buy = 0; buy <= 1; buy++)
        //  {
        //      for (int cap = 0; cap <= 2; cap++)
        //      {
        //          dp[n][buy][cap] = 0;
        //      }
        //  }

        // for (int ind = 0; ind < n; ind++)
        // {
        //     for (int buy = 0; buy <= 1; buy++)
        //     {
        //         dp[ind][buy][0] = 0;
        //     }
        // }

        // recursion 0 -> n buy 1 -> 0 cap 2 -> 0
        // tabulation n -> 0 buy 0 -> 1 cap 0 -> 2

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                // cap == 0 done in base case
                for (int cap = 1; cap <= 2; cap++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        // buy
                        int take = -prices[ind] + dp[ind + 1][0][cap];
                        int notTake = 0 + dp[ind + 1][1][cap];
                        profit = max(take, notTake);
                    }
                    else
                    {
                        // sell
                        int sell = prices[ind] + dp[ind + 1][1][cap - 1];
                        int notSell = 0 + dp[ind + 1][0][cap];
                        profit = max(sell, notSell);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};