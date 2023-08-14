class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp)
    {
        // we reach the destination
        if (i == 0 && j == 0)
            return 1;

        // we exceed the grid
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);

        return dp[i][j] = (up + left);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];

        // base case
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};