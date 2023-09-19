class Solution {
public:
    int f(int ind, vector<int>& a, vector<int>& dp){
        
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = a[ind] + f(ind-2, a, dp);
        int not_pick = 0 + f(ind-1, a, dp);
        
        return dp[ind] = max(pick, not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(n-1, nums, dp);
    }
        
};