//FIXED STARTING POINT BUT VARIABLE ENDING POINT


// class Solution
// {
// public:
//     int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
//     {
//         // base case
//         int n = triangle.size();
//         if (i == n - 1)
//             return triangle[n - 1][j];

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int below = triangle[i][j] + solve(i + 1, j, triangle, dp);

//         int diagBelow = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

//         return dp[i][j] = min(below, diagBelow);
//     }
//     int minimumTotal(vector<vector<int>> &triangle)
//     {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return solve(0, 0, triangle, dp);
//     }
// };

// TABULATION
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case
        for (int j = 0; j < n; j++)
            dp[n - 1][j] = triangle[n - 1][j];

        // recursion 0->n-1
        // tabulation n-1->0
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int below = triangle[i][j] + dp[i + 1][j];

                int diagBelow = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(below, diagBelow);
            }
        }

        return dp[0][0];
    }
};