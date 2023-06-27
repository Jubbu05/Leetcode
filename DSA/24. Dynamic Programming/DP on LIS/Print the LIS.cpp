class Solution
{
public:
    vector<int> printLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastINdex = 1;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            id(dp[i] > maxi)
            {
                maxi = dp[i];
                lastINdex = i;
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastINdex]);
        while (hash[lastINdex] != lastINdex)
        {
            lastINdex = hash[lastINdex];
            lis.push_back(nums[lastINdex]);
        }

        revrese(lis.begin(), lis.end());

        return lis;
    }
};