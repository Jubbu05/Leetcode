class Solution {
public:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int maxi = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow, ncol, n, m) && matrix[row][col] > matrix[nrow][ncol]){
                maxi = max(maxi, 1 + solve(nrow, ncol, matrix, dp));
            }
        }
        return dp[row][col] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans+1;
    }
};