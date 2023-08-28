class Solution
{
    vector<vector<int>> ans;
    void solve(int ind, int sum, int k, vector<int> &temp, int start)
    {
        if (ind == k)
        {
            if (sum == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            temp.push_back(i);
            solve(ind + 1, sum - i, k, temp, i + 1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum3(int k, int sum)
    {
        vector<int> temp;
        solve(0, sum, k, temp, 1);
        return ans;
    }
};