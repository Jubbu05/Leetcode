int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1; // Initialize the lower and upper bounds of the search range

    while (l <= h)
    {
        int md = (l + h) >> 1; // Calculate the middle index

        if (row[md] <= mid) // If the value at middle index is less than or equal to mid, search in the right half
        {
            l = md + 1;
        }
        else // If the value at middle index is greater than mid, search in the left half
        {
            h = md - 1;
        }
    }
    return l; // Return the count of elements smaller than or equal to mid
}

int getMedian(vector<vector<int>> &A)
{
    int low = 1;         // Initialize the lower bound of the search range
    int high = 1e9;      // Initialize the upper bound of the search range
    int n = A.size();    // Get the number of rows in the matrix
    int m = A[0].size(); // Get the number of columns in the matrix

    while (low <= high)
    {
        int mid = (low + high) >> 1; // Calculate the middle value
        int cnt = 0;                 // Initialize the count of elements smaller than or equal to mid

        // Iterate over each row and count the number of elements smaller than or equal to mid
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
        }

        if (cnt <= (n * m) / 2) // If the count is less than or equal to half of the total elements, search in the right half
            low = mid + 1;
        else // If the count is greater than half of the total elements, search in the left half
            high = mid - 1;
    }
    return low; // Return the median value
}
