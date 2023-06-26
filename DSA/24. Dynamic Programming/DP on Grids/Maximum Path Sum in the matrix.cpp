// VARIABLE STARTING POINT AND VARIABLE ENDING POINT

// WE CAM MOVE IN 3 DIRECTIONS: BELOW, DIAG LEFT, DIAG RIGHT

// GIVE MAXIMUM PATH SUM FROM ANY CELL OF FIRST ROW TO ANY CELL OF LAST ROW
// #include <bits/stdc++.h>

// using namespace std;

// int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {

//     // BASE CASE
//     // OUT OF BOUNDS CASE
//     if (j < 0 || j >= m)
//         return -1e9;
//     if (i == 0)
//         return matrix[0][j];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
//     int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
//     int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

//     return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {

//     int n = matrix.size();
//     int m = matrix[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     int maxi = INT_MIN;

//     for (int j = 0; j < m; j++)
//     {
//         int ans = getMaxUtil(n - 1, j, m, matrix, dp);
//         maxi = max(maxi, ans);
//     }

//     return maxi;
// }

// TABULATION
int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    // BASE CASE
    // OUT OF BOUNDS CASE
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    // recursion n-1 -> 0
    // tabulation 0 -> n-1

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = -1e9;
    for (int j = 0; j < m; j++)
    {
        int ans = dp[n-1][j];
        maxi = max(maxi, ans);
    }
    return maxi;
}