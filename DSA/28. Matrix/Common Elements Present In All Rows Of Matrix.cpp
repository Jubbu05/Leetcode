#include <bits/stdc++.h>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    unordered_map<int, int> mp;
    vector<int> ans;

    // egde case for 1 row matrix
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
            ans.push_back(mat[0][i]);
        return ans;
    }

    // Inserting elements from first row
    for (int i = 0; i < m; i++)
        mp[mat[0][i]] = 1;

    // Traversing the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
                // we increment count of the element
                // in map by 1
                mp[mat[i][j]] = i + 1;

                // If this is last row
                if (i == n - 1 && mp[mat[i][j]] == n) // If this is last row and count is n, then it is a common element
                    ans.push_back(mat[i][j]);
            }
        }
    }
    return ans;
}
