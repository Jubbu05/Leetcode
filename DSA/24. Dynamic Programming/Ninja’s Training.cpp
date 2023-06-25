// 0 -> 0th task was done
// 1 -> 1st task was done
// 2 -> 2nd task was done
// 3 -> No task was done
solve(int day, int lasttask, vector<vector<int>> &points)
{
    // base case
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != lasttask)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != lasttask)
        {
            int point = points[day][task] + solve(day - 1, task);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(n - 1, 3, points);
}