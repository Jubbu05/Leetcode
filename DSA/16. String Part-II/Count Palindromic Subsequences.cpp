class Solution
{
public:
    int dp[1001][1001];
    long long int helper(string &str, int i, int j)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return (dp[i][j]);
        if (str[i] == str[j])
            return dp[i][j] = 1 + helper(str, i + 1, j) + helper(str, i, j - 1);

            // a b c
            // this will call for
            // ab + bc - b here b is counted twice so we subtract it once
        else
            return dp[i][j] = helper(str, i + 1, j) + helper(str, i, j - 1) - helper(str, i + 1, j - 1);
    }

    long long int countPS(string str)
    {
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return helper(str, 0, n - 1);
    }
};