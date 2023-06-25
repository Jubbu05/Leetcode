class Solution
{
public:
  int minimumDifference(vector<int> &arr)
  {
    int n = arr.size();

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
      totSum += arr[i];
    }

    //subset sum equal to k
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    for (int i = 0; i < n; i++)
    {
      dp[i][0] = true;
    }

    if (arr[0] <= totSum)
      dp[0][totSum] = true;

    for (int ind = 1; ind < n; ind++)
    {
      for (int target = 1; target <= totSum; target++)
      {

        bool notTaken = dp[ind - 1][target];

        bool taken = false;
        if (arr[ind] <= target)
          taken = dp[ind - 1][target - arr[ind]];

        dp[ind][target] = notTaken || taken;
      }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
      if (dp[n - 1][i] == true)
      {            //abs(s1- s2)
        int diff = abs(i - (totSum - i));
        mini = min(mini, diff);
      }
    }
    return mini;
  }
};


