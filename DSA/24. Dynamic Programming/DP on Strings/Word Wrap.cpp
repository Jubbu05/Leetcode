class Solution
{
public:
    int dp[505][2005];
    int solve(int i, int rem, vector<int> &nums, int &k)
    {
        if (i == nums.size())
            return 0;

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int ans;
        // if length of word is greater than remaining space
        if (nums[i] > rem)
        { // next line and pay cost //call for next word with k-nums[i]-1 spaces left
            ans = (rem + 1) * (rem + 1) + solve(i + 1, k - nums[i] - 1, nums, k);
        }
        else
        {   // next line and pay cost
            int choice1 = (rem + 1) * (rem + 1) + solve(i + 1, k - nums[i] - 1, nums, k);
            // place in same line and call for next word with rem-nums[i]-1 spaces left
            int choice2 = solve(i + 1, rem - nums[i] - 1, nums, k);
            ans = min(choice1, choice2);
        }
        return dp[i][rem] = ans;
    }
    int solveWordWrap(vector<int> nums, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, nums, k);
    }
};

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 1000000000);
        int ans[n];
        int cost = 0;
        int curlen = 0;
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            curlen = -1;
            for (int j = i; j < n; j++)
            {
                curlen += nums[j] + 1;
                if (curlen > k)
                    break;
                if (j == n - 1)
                    cost = 0;
                else
                {
                    cost = pow(k - curlen, 2) + dp[j + 1];
                }
                if (cost < dp[i])
                {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        return dp[0];
    }
};