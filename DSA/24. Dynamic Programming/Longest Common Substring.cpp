// TABULATION
class Solution
{
public:
    // shifting of index coz for the base case we want idx<0 i.e -1 but we can't store so we shift the index by 1
    //  -1 0 1 2 3 . . . n-1
    //   0 1 2 3 4 . . . n we do right shifting of index
    // so base case becomes
    // if (idx1 == 0 || idx2 == 0) return 0;
    int longestCommonSubstring(string s1, string s2)
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

        int ans = 0;

        for (int idx1 = 1; idx1 <= n; idx1++)
        {
            for (int idx2 = 1; idx2 <= m; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                    ans = max(ans, dp[idx1][idx2]);
                }
                else
                {
                    dp[idx1][idx2] = 0;
                }
            }
        }

        return ans;
    }
};