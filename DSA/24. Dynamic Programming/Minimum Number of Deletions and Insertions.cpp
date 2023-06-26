// We will first keep the longest common subsequence of the str1 and str2 intact in str1 and delete all other characters from str1.
// Next, we will insert all the remaining characters of str2 to str1.
// Minimum Operations required = (n – k) + (m – k)

#include <bits/stdc++.h>
int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case
    for (int idx1 = 0; idx1 <= n; idx1++)
    {
        dp[idx1][0] = 0;
    }
    for (int idx2 = 0; idx2 <= m; idx2++)
    {
        dp[0][idx2] = 0;
    }

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            if (s1[idx1 - 1] == s2[idx2 - 1])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            else
                dp[idx1][idx2] = 0 + max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
        }
    }

    return dp[n][m];
}

int canYouMake(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    int k = longestCommonSubsequence(str1, str2);
    // number of deletion - n - k
    // number of insertions = m - k
    return (n - k) + (m - k);
}