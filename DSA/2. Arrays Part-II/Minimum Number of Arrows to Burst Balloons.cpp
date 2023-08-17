class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
        {
            return ans;
        }
        sort(intervals.begin(), intervals.end());
        auto temp = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                // just slight modification from Merge Intervals.cpp
                temp[1] = min(temp[1], it[1]);
                temp[0] = max(temp[0], it[0]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    int findMinArrowShots(vector<vector<int>> &p)
    {
        merge(p);
        return ans.size();
    }
};