class Solution
{
public:
    void mark(vector<vector<int>> &image, int sr, int sc, int color, int m, int n, int x)
    {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != x)
        {
            return;
        }
        image[sr][sc] = color;
        mark(image, sr + 1, sc, color, m, n, x);
        mark(image, sr, sc + 1, color, m, n, x);
        mark(image, sr - 1, sc, color, m, n, x);
        mark(image, sr, sc - 1, color, m, n, x);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color == image[sr][sc])
        {
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        int x = image[sr][sc];
        mark(image, sr, sc, color, m, n, x);
        return image;
    }
};