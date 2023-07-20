class Solution
{
public:
    int countSmallerThanEqualToMid(vector<int> &row, int mid)
    {
        int l = 0, h = row.size() - 1;
        while (l <= h)
        {
            int md = (l + h) / 2;
            if (row[md] <= mid)
            {
                l = md + 1;
            }
            else
            {
                h = md - 1;
            }
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = 1;
        int high = 2000;
        int n = R, m = C;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = 0;

            for (int i = 0; i < n; i++) // for each row
            {
                cnt += countSmallerThanEqualToMid(matrix[i], mid);
            }

            if (cnt <= (n * m) / 2)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
};