class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                pq.push(mat[i][j]);
            }
        }
        int row = 0, col = 0;
        while (!pq.empty())
        {
            mat[row][col] = pq.top();
            pq.pop();
            col++;
            if (col == N)
            {
                col = 0;
                row++;
            }
        }
        return mat;
    }
};