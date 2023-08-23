class Solution
{
public:
    int dp[301][301];
    int area(int row, int col, int m, int n, vector<vector<char>> &matrix)
    {
        if (row >= m || col >= n || matrix[row][col] == '0')
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int right = 1 + area(row, col + 1, m, n, matrix);
        int below = 1 + area(row + 1, col, m, n, matrix);
        int diagonal = 1 + area(row + 1, col + 1, m, n, matrix);

        return dp[row][col] = min(right, min(below, diagonal));
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        memset(dp, -1, sizeof dp);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    ans = max(ans, area(i, j, m, n, matrix));
                }
            }
        }
        return ans * ans;
    }
};