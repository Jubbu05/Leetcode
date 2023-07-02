#include <bits/stdc++.h>
int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{

    // base condition
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {

        int ans = arr[i - 1] * arr[k] * arr[j] + f(arr, i, k, dp) + f(arr, k + 1, j, dp);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>> dp(N, vector<int>(N, -1));

    int i = 1;
    int j = N - 1;

    return f(arr, i, j, dp);
}

// TABULATION
#include <bits/stdc++.h>
int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {

        for (int j = i + 1; j < N; j++)
        {

            int mini = INT_MAX;

            // partioning loop
            for (int k = i; k <= j - 1; k++)
            {

                int ans = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}