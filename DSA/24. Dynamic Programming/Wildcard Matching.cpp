class Solution
{
public:
    bool helper(string &str, string &pat, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 && j < 0)
        {
            return true;
        }
        // pattern get exausted but string still has some elements
        if (j < 0 && i >= 0)
        {
            return false;
        }
        // string get exausted but pattern still has some elements
        // if pattern has *'s then we can return true coz only *'s can be matched by empty string
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k < j; k++)
            {
                if (pat[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // match
        if (str[i] == pat[j] || pat[j] == '?')
        {
            return dp[i][j] = helper(str, pat, i - 1, j - 1, dp);
        }

        else if (pat[j] == '*')
        {
            // * as empty string              // with that element
            return dp[i][j] = helper(str, pat, i, j - 1, dp) || helper(str, pat, i - 1, j, dp);
        }

        else
            return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(s, p, n - 1, m - 1, dp);
    }
};

// TABULATION
// SHIFTING OF INDEXES
class Solution
{
public:
    bool isAllStars(string &S1, int i)
    {

        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++)
        {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    bool isMatch(string S2, string S1)
    {

        int n = S1.size();
        int m = S2.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = isAllStars(S1, i);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else
                {
                    if (S1[i - 1] == '*')
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                    else
                        dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
