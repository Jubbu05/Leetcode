#include <bits/stdc++.h>
int solve(int ind, vector<int> &height, vector<int> &dp, int k){
    if(ind == 0) return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int mmSteps = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(ind - i >= 0)
            mmSteps = min(mmSteps, solve(ind - i, height, dp, k) + abs(height[ind] - height[ind - i]));
    }
    return dp[ind] = mmSteps;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    return solve(n-1, height, dp, k);
}