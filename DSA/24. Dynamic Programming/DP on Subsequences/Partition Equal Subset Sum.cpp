class Solution
{
public:
    bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        bool taken = false;
        if (arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;
    }

    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();

        int totSum = 0;

        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }

        if (totSum % 2 == 1)
            return false;

        else
        {
            int k = totSum / 2;
            vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            return subsetSumUtil(n - 1, k, arr, dp);
        }
    }
};

class Solution
{
public:
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();

        int totSum = 0;

        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }

        if (totSum % 2 == 1)
            return false;

        else
        {
            int k = totSum / 2;
            vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

            for (int i = 0; i < n; i++)
            {
                dp[i][0] = true;
            }

            if (arr[0] <= k)
                dp[0][arr[0]] = true;

            for (int ind = 1; ind < n; ind++)
            {
                for (int target = 1; target <= k; target++)
                {

                    bool notTaken = dp[ind - 1][target];

                    bool taken = false;
                    if (arr[ind] <= target)
                        taken = dp[ind - 1][target - arr[ind]];

                    dp[ind][target] = notTaken || taken;
                }
            }

            return dp[n - 1][k];
        }
    }
};