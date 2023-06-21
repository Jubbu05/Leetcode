// obervation - if any O is connected to boundary O then it will not be replaced by X

// start from boundary O and do dfs and mark that they are not to be replaced by X
class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        // check for top right bottom left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, mat, vis);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // // traverse first row and last row
        // for (int j = 0; j < m; j++)
        // {
        //     // first row
        //     if (!vis[0][j] && mat[0][j] == 'O')
        //     {
        //         dfs(0, j, mat, vis);
        //     }

        //     // last row
        //     if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        //     {
        //         dfs(n - 1, j, mat, vis);
        //     }
        // }

        // // traverse first col and last col
        // for (int i = 0; i < n; i++)
        // {
        //     // first col
        //     if (!vis[i][0] && mat[i][0] == 'O')
        //     {
        //         dfs(i, 0, mat, vis);
        //     }

        //     // last col
        //     if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        //     {
        //         dfs(i, m - 1, mat, vis);
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // first row, first col, last row, last col
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    // if it is a land then store it in queue
                    if (!vis[i][j1] && mat[i][j] == 'O')
                    {
                        dfs(i, j, mat, vis);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};