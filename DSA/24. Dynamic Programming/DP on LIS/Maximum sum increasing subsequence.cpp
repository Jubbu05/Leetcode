#include <bits/stdc++.h>
int lis(int ind, int prev_ind, int n, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int notTake = 0 + lis(ind + 1, prev_ind, n, nums, dp);

    int take = 0;
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        take = nums[ind] + lis(ind + 1, ind, n, nums, dp);
    }

    return dp[ind][prev_ind + 1] = max(take, notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return lis(0, -1, n, nums, dp);
}