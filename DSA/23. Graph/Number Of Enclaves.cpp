// DFS
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
        {
            return;
        }
        if (grid[i][j] == 1)
        {
            grid[i][j] = 2;
        }
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// BFS
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse boundary elements
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // first row, first col, last row, last col
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    // if it is a land then store it in queue
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // check for valid coordinates and for land cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // check for unvisited land cell
                if (grid[i][j] == 1 & vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};