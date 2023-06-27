// ind - 0 -> n-1
// prev_ind - -1 -> n-1 we can store -1 so we co-ordenate shift
class Solution
{
public:
    int f(int ind, int prev_ind, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int notTake = 0 + f(ind + 1, prev_ind, n, nums, dp);

        int take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + f(ind + 1, ind, n, nums, dp);
        }

        return dp[ind][prev_ind + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, n, nums, dp);
    }
};

// tabulation
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // recursion ind -> 0 to n-1 prev_ind -> -1 to n-1
        // tabulation ind -> n-1 to 0 prev_ind -> n to -1

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int notTake = 0 + dp[ind + 1][prev_ind + 1];

                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    take = 1 + dp[ind + 1][ind + 1];
                }

                dp[ind][prev_ind + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// TC - O(N^2)
// SC - O(N)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// BINARY SEARCH
//  TC - O(NlogN)
//  SC - O(N)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;

        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};