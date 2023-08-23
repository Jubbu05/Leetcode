// 0 -> 0th task was done
// 1 -> 1st task was done
// 2 -> 2nd task was done
// 3 -> No task was done
#include <bits/stdc++.h>

using namespace std;

int f(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != lastTask)
                maxi = max(maxi, points[0][i]);
        }
        return dp[day][lastTask] = maxi;
    }

    int maxi = 0;
    for (int task = 0; task <= 2; task++)
    {
        if (task != lastTask)
        {
            int activity = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, activity);
        }
    }

    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}