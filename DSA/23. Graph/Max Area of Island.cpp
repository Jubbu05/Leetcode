class Solution {
public:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void bfs(int row, int col, int &count, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m){
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    count++;
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int count = 1;
                    bfs(i, j, count, vis, grid, n, m);
                    maxi = max(maxi, count);
                }
            }
        }
        return (maxi == INT_MIN) ? 0 : maxi;
    }
};
