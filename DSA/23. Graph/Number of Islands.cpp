// class Solution
// {
// public:
//     void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         vis[row][col] = 1;
//         queue<pair<int, int>> q;
//         q.push({row, col});

//         while (!q.empty())
//         {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             for (int delrow = -1; delrow <= 1; delrow++)
//             {
//                 for (int delcol = -1; delcol <= 1; delcol++)
//                 {
//                     int nrow = row + delrow;
//                     int ncol = col + delcol;
//                     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
//                     {
//                         vis[nrow][ncol] = 1;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (!vis[i][j] && grid[i][j] == '1')
//                 {
//                     bfs(i, j, vis, grid);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    bool isValid(int row, int col, int n, int m){
        return row>=0 && row<n && col>=0 && col<m;
    }
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int noi=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    noi++;
                }
            }
        }
        return noi;
    }
};