// //O(N^2)
class Solution {
public:
    bool isPalindrome(string s){
        int n = s.length();
        int i = 0;
        int j = n-1;
        
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int minChar(string str){
        int n = str.length();
        int added = 0;
        
        while(n>0){
            if(isPalindrome(str.substr(0, n-added))) break;
            else added++;
        }
        return added;
    }
};

//O(N)
class Solution {
public:
    int minChar(string str){
        int n = str.length();
        int added = 0;
        int i = 0;
        int j = n-1;
        int lastIdx = n-1;
        
        while(i<j){
            if(str[i] == str[j]){
                i++;
                j--;
            }
            else{
                i = 0;
                lastIdx--;
                j = lastIdx;
            }
        }
        added = n-1 - lastIdx;
        return added;
    }
};

int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
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
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        return longestCommonSubsequence(s,s1);
    }

    int minInsertion(string &str) {
        int n = str.length();
        int lps = longestPalindromeSubseq(str);

        return n - lps;
    }