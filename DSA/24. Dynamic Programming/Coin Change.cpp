class Solution
{
public:
    int solve(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTaken = 0 + solve(ind - 1, target, coins, dp);

        int taken = 1e9;
        if (coins[ind] <= target)
            taken = 1 + solve(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = min(notTaken, taken);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// TABULATION
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case
        for (int tar = 0; tar <= amount; tar++)
        {
            if (tar % coins[0] == 0)
                dp[0][tar] = tar / coins[0];
            else
                dp[0][tar] = 1e9;
        }

        // reccursion n-1 -> 0
        // tabulation 0 -> n-1

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {

                int notTake = 0 + dp[ind - 1][target];
                int take = 1e9;
                if (coins[ind] <= target)
                    take = 1 + dp[ind][target - coins[ind]];

                dp[ind][target] = min(notTake, take);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
            return -1;

        return ans;
    }
};