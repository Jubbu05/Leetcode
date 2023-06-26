// class Solution
// {
// public:
//     // robot starts at (0, 0) and robot 2 starts at (0, m - 1
//     //(i + 1, j - 1), (i + 1, j), or (i + 1, j + 1)
//     // row will increase by 1 but col of both will change
//     // so we can consider only 1 i
//     int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         // out of bounds
//         if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
//             return -1e8;

//         // base case
//         if (i == n - 1)
//         {
//             // both in same cell
//             if (j1 == j2)
//             {
//                 return grid[i][j1];
//             }
//             else
//             {
//                 return grid[i][j1] + grid[i][j2];
//             }
//         }

//         if (dp[i][j1][j2] != -1)
//             return dp[i][j1][j2];

//         /// for 3 moments of robot 1 there are 3 moments of robot 2
//         // so there are 9 possibilities
//         int maxi = -1e8;
//         for (int delta1 = -1; delta1 <= 1; delta1++)
//         {
//             for (int delta2 = -1; delta2 <= 1; delta2++)
//             {
//                 int ans = 0;
//                 // both in same cell
//                 if (j1 == j2)
//                 {
//                     // just add once
//                     ans = grid[i][j1] + solve(i + 1, j1 + delta1, j2 + delta2, grid, dp);
//                 }
//                 else
//                 {
//                     ans = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + delta1, j2 + delta2, grid, dp);
//                 }

//                 maxi = max(maxi, ans);
//             }
//         }
//         return dp[i][j1][j2] = maxi;
//     }

//     int cherryPickup(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

//         return solve(0, 0, m - 1, grid, dp);
//     }
// };

// TABULATION
class Solution
{
public:
    // robot starts at (0, 0) and robot 2 starts at (0, m - 1
    //(i + 1, j - 1), (i + 1, j), or (i + 1, j + 1)
    // row will increase by 1 but col of both will change
    // so we can consider only 1 i
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Outer Nested Loops for travering DP Array
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {

                    int maxi = -1e8;

                    // Inner nested loops to try out 9 options
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {

                            int ans;

                            if (j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];

                            if ((j1 + di < 0 || j1 + di >= m) ||
                                (j2 + dj < 0 || j2 + dj >= m))

                                ans += -1e8;
                            else
                                ans += dp[i + 1][j1 + di][j2 + dj];

                            maxi = max(ans, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};