#include <bits/stdc++.h>
long long int solve(int ind, vector<int> &nums, vector<long long int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    long long int pick = nums[ind] + solve(ind - 2, nums, dp);
    long long int notpick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notpick);
}
long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    vector<int> temp1, temp2;

    if (n == 1)
        return valueInHouse[0];

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    vector<long long int> dp(n, -1);
    long long int ans1 = solve(n - 1, temp1, dp);
    long long int ans2 = solve(n - 1, temp2, dp);
    return max(ans1, ans2);
}
