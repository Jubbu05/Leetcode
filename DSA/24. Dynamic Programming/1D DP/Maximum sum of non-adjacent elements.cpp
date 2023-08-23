#include <bits/stdc++.h>
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    // means we didn't pick ind=1 so pick ind=0
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + solve(ind - 2, nums, dp);
    int notpick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}