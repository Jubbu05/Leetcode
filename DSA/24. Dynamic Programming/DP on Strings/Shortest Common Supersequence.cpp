// length of shortest Common Supersequence = length of str1 + length of str2 - length of longest common subsequence
class Solution
{
public:
    string printLCS(string s1, string s2)
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
        // we have our dp matrix

        int i = n, j = m;
        string ans = "";

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) // upward movement
            {
                ans += s1[i - 1]; // just add this in code of print longest common subsequence
                i--;
            }
            else // left ward movement
            {
                ans += s2[j - 1]; // just add this in code of print longest common subsequence
                j--;
            }
        }

        // edge case
        //  if i becomse 0 there is still some characters left in j
        //  if j becomes 0 there is still some characters left in i

        while (i > 0)
        {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        return printLCS(str1, str2);
    }
};