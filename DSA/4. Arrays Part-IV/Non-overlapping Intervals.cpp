class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // sorting on the basis of start time
        sort(intervals.begin(), intervals.end());
        // fi==finish time of first interval
        int fi = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < fi)
            {
                ans++;
                // update the finish time
                fi = min(fi, intervals[i][1]);
            }
            else
            {
                fi = intervals[i][1];
            }
        }
        return ans;
    }
};
