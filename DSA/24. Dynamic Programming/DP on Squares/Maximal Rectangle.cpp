class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int rightSmall[n];
        int leftSmall[n];

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top() + 1;
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                rightSmall[i] = n - 1;
            else
                rightSmall[i] = st.top() - 1;
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
            maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {

        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n, 0);

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    curr[j]++;
                else
                    curr[j] = 0;
            }
            int area = largestRectangleArea(curr);
            ans = max(ans, area);
        }
        return ans;
    }
};