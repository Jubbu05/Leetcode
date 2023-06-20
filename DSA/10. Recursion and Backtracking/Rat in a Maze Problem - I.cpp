class Solution
{
public:
    vector<string> ans; // Vector to store the paths

    // Recursive function to find paths
    void solve(int i, int j, vector<vector<int>> &m, int n, string s)
    {
        // If current position is out of bounds or blocked, return
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0)
            return;

        // If we reach the last position, add the path to the result vector
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            s = ""; // Resetting the string for the next path
            return;
        }

        m[i][j] = 0; // Mark current position as blocked to avoid revisiting

        // Recursive calls in four directions: right, left, down, up
        solve(i, j + 1, m, n, s + "R"); // Right
        solve(i, j - 1, m, n, s + "L"); // Left
        solve(i + 1, j, m, n, s + "D"); // Down
        solve(i - 1, j, m, n, s + "U"); // Up

        m[i][j] = 1; // Restore the current position as unblocked for other paths
    }

    // Function to find paths in a grid
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string s = ""; // Empty string to store the paths

        // Check if starting or ending position is blocked
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
            return {}; // Return empty vector if either is blocked

        solve(0, 0, m, n, s); // Call the solve function to find paths

        return ans; // Return the vector containing paths
    }
};
