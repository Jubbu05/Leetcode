class Solution
{
public:
    int solve(int ind, int target, vector<int> &coins, vector<vector<long>> &dp)
    {
        if (ind == 0)
        {
            return (target % coins[0] == 0);
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        long notTaken = solve(ind - 1, target, coins, dp);

        long taken = 0;
        if (coins[ind] <= target)
            taken = solve(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = (notTaken + taken);
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, -1));

        return solve(n - 1, amount, coins, dp);
    }
};

// TABULATION
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, 0));

        for (int target = 0; target <= amount; target++)
        {
            dp[0][target] = (target % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long notTaken = dp[ind - 1][target];

                long taken = 0;
                if (coins[ind] <= target)
                    taken = dp[ind][target - coins[ind]];

                dp[ind][target] = (notTaken + taken);
            }
        }

        return dp[n - 1][amount];
    }
};
