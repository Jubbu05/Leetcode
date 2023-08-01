class Solution
{
public:
    void solve(int ind, int k, vector<int> &temp, int n, vector<vector<int>> &ans)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, k, temp, n, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, temp, n, ans);
        return ans;
    }
};