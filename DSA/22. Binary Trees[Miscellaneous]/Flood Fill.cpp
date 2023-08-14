// DFS
class Solution
{
public:
    void mark(vector<vector<int>> &image, int sr, int sc, int newColor, int m, int n, int oldcolor)
    {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldcolor)
        {
            return;
        }
        image[sr][sc] = newColor;
        mark(image, sr + 1, sc, newColor, m, n, oldcolor);
        mark(image, sr, sc + 1, newColor, m, n, oldcolor);
        mark(image, sr - 1, sc, newColor, m, n, oldcolor);
        mark(image, sr, sc - 1, newColor, m, n, oldcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc])
        {
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];
        mark(image, sr, sc, newColor, m, n, oldcolor);
        return image;
    }
};

//------------------------------------------------------------------------------------------------------------------

// BFS
class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        if (i >= n || j >= m || i < 0 || j < 0)
            return 0;
        else
            return 1;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];

        if (image[sr][sc] == newColor)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (isvalid(nrow, ncol, n, m) && image[nrow][ncol] == oldcolor)
                {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = newColor;
                }
            }
        }
        return image;
    }
};