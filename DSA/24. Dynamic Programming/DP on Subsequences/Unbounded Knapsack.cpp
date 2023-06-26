#include <bits/stdc++.h>
int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return ((int)(W / wt[0])) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

    int taken = 0;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}
int unboundedKnapsack(int n, int maxWt, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(maxWt + 1, -1));
    return knapsackUtil(weight, profit, n - 1, maxWt, dp);
}

// TABULATION
#include <bits/stdc++.h>
int unboundedKnapsack(int n, int maxWt, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(maxWt + 1, 0));

    for (int W = 0; W <= maxWt; W++)
        dp[0][W] = ((int)(W / weight[0])) * profit[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWt; W++)
        {
            int notTaken = 0 + dp[ind - 1][W];

            int taken = 0;
            if (weight[ind] <= W)
                taken = profit[ind] + dp[ind][W - weight[ind]];

            dp[ind][W] = max(notTaken, taken);
        }
    }

    return dp[n - 1][maxWt];
}
