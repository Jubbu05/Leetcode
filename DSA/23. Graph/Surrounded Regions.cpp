//Intution mark all the 'O' which are connected to boundary 'O' as '#' as they can't be flipped
//then flip all the 'O' to 'X' coz they are not conected to a boundary and can be flipped and '#' to 'O'->restoring the original board
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