class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int col = m - 1;
        int row = -1;

        // traverse matrix row by row
        for (int i = 0; i < n; i++)
        {
            for (int j = col; j >= 0; j--) // traverse from last column as its sorted 
            {
                if (arr[i][j] == 1) // can be a contender
                {
                    row = i;
                    // move left
                    // we'll not see same column again as its sorted 
                    col--;
                }
                // if you see 0, move down skip that row
                else
                {
                    break;
                }
            }
        }
        return row;
    }
};