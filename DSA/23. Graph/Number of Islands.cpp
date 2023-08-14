// BFS
class Solution
{
public:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int noi = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
                    noi++;
                }
            }
        }
        return noi;
    }
};

// DFS
class Solution
{
public:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (!isValid(i, j, n, m) || grid[i][j] != '1')
            return;

        if (grid[i][j] == '1')
        {
            grid[i][j] = '2';
        }
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int noi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    noi++;
                }
            }
        }
        return noi;
    }
};