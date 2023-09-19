// Intution mark all the 'O' which are connected to boundary 'O' as '#' as they can't be flipped
// then flip all the 'O' to 'X' coz they are not conected to a boundary and can be flipped and '#' to 'O'->restoring the original board
// DFS
class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
            return;
        if (board[i][j] == 'O')
            board[i][j] = '#';
        dfs(i + 1, j, board);
        dfs(i, j + 1, board);
        dfs(i - 1, j, board);
        dfs(i, j - 1, board);
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

// BFS
class Solution {
public:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board, int n, int m){
        queue<pair<int, int>> q;

        vis[row][col] = 1;
        q.push({row, col});

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && !vis[i][j] && board[i][j] == 'O'){
                    bfs(i, j, vis, board, n, m);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};