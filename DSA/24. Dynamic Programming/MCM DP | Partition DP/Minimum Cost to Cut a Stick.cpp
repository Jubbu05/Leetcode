class Solution
{
public:
    int rec(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k <= j; k++)
        {                                            //partition at index k
                       // length of the stick        // left part of the stick     // right part of the
            int cost = (cuts[j + 1] - cuts[i - 1]) + rec(i, k - 1, cuts, dp) + rec(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return rec(1, cuts.size() - 2, cuts, dp);
    }
};