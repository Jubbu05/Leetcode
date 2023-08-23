// We will first keep the longest common subsequence of the str1 and str2 intact in str1 and delete all other characters from str1.
// Next, we will insert all the remaining characters of str2 to str1.
// Minimum Operations required = (n – k) + (m – k)

#include <bits/stdc++.h>
int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
        return 0; // longest length if one string becomes 0 is 0

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s1[idx1] == s2[idx2])
        return dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
    else
        return dp[idx1][idx2] = 0 + max(helper(idx1 - 1, idx2, s1, s2, dp), helper(idx1, idx2 - 1, s1, s2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return helper(n - 1, m - 1, text1, text2, dp);
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