// DFS
//  class Solution
//  {
//  public:
//      void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor)
//      {
//          ans[row][col] = newColor;
//          int n = image.size();
//          int m = image[0].size();

//         int delRow[] = {-1, 0, 1, 0};
//         int delCol[] = {0, 1, 0, -1};

//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = row + delRow[i];
//             int ncol = col + delCol[i];

//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
//             {
//                 ans[nrow][ncol] = newColor;
//                 dfs(nrow, ncol, ans, image, newColor, iniColor);
//             }
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
//     {
//         int iniColor = image[sr][sc];
//         vector<vector<int>> ans = image;
//         dfs(sr, sc, ans, image, newColor, iniColor);
//         return ans;
//     }
// };

// BFS
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        vis[sr][sc] = 1;

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == color)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = newColor;
                }
            }
        }

        return image;
    }
};