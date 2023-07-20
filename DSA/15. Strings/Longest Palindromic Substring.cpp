class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size(), maxlength = 0;
        string ans;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // diff is the difference between i and j
        // diagonal traversal
        for (int diff = 0; diff < n; diff++)
        {
            for (int i = 0, j = i + diff; j < n; i++, j++)
            {
                // diagonals element 1 single length string
                if (i == j) // diagonal element
                    dp[i][j] = 1; // single length string has 1 palindrome

                // 2 length string
                // like (0,1) (1,2) (2,3) (3,4)
                else if (diff == 1)
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                    
                else
                {   //last element of string is same and inner string is palindrome
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    else
                        dp[i][j] = 0; // not a palindrome
                }

                // getting max length
                if (dp[i][j] != 0) // if palindrome
                {
                    if (j - i + 1 > maxlength)
                    {
                        maxlength = j - i + 1;
                        ans = s.substr(i, maxlength);
                    }
                }
            }
        }
        return ans;
    }
};