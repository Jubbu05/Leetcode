class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // BFS WILL BE USED
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
            return -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        int mins = INT_MAX;
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if (x == n - 1 && y == m - 1)
            {
                mins = min(mins, steps);
                continue;
            }
            int delrow[] = {0, -1, 0, 1, 1, -1, 1, -1};
            int delcol[] = {1, 0, -1, 0, 1, -1, -1, 1};
            for (int i = 0; i < 8; i++)
            {
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return mins == INT_MAX ? -1 : mins;
    }
};