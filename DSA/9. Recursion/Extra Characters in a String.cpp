class Solution
{
public:
    int solve(string &s, unordered_map<string, int> &mp, vector<int> &dp, int idx)
    {
        if (idx >= s.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
            
        string currStr = "";
        int ans = INT_MAX;
        for (int cutIdx = idx; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            int count = ((mp.count(currStr)) ? 0 : currStr.size()) + solve(s, mp, dp, cutIdx + 1);
            ans = min(ans, count);
        }
        return dp[idx] = ans;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        vector<int> dp(s.size(), -1);
        unordered_map<string, int> mp;
        for (string &word : dictionary)
            mp[word]++;
        int ans = solve(s, mp, dp, 0);
        return ans;
    }
};