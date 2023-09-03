class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, int n, vector<vector<vector<int>>> &dp, int cap){
        if(ind == n || cap == 0){
            return 0;
        }
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0;
        if(buy == 1){
            int take = -prices[ind] + solve(ind+1, 0, prices, n, dp, cap);
            int notTake = solve(ind+1, 1, prices, n, dp, cap);
            profit = max(take, notTake);
        }
        else{
            int sell = prices[ind] + solve(ind+1, 1, prices, n, dp, cap-1);
            int notsell = solve(ind+1, 0, prices, n, dp, cap);
            profit = max(sell, notsell);
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, prices, n, dp, k);
    }
};

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    if (buy == 1)
                    {
                        int take = -prices[ind] + dp[ind + 1][0][cap];
                        int notTake = 0 + dp[ind + 1][1][cap];
                        dp[ind][buy][cap] = max(take, notTake);
                    }
                    else
                    {
                        int sell = prices[ind] + dp[ind + 1][1][cap - 1];
                        int notSell = 0 + dp[ind + 1][0][cap];
                        dp[ind][buy][cap] = max(sell, notSell);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};