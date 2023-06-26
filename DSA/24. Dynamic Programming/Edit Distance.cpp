class Solution
{
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 0 + solve(i - 1, j - 1, s1, s2, dp);

        int insert = solve(i, j - 1, s1, s2, dp);
        int del = solve(i - 1, j, s1, s2, dp);
        int replace = solve(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min(replace, min(insert, del));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, word1, word2, dp);
    }
};

// TABULATION
// INDEX SHIFTING
class Solution
{
public:
    int minDistance(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // BASE CASE
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }

                else
                {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(replace, min(insert, del));
                }
            }
        }

        return dp[n][m];
    }
};