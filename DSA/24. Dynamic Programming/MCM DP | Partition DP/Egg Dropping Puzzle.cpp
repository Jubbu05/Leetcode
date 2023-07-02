class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int helper(int eggs, int floor, vector<vector<int>>& dp)
    {
        // base case
        // if eggs = 1 we have to check all floors from 1 to floors
        // so minumum attempts = floors
        if (eggs == 1)
            return floor;

        if (floor == 0 || floor == 1)
            return floor;

        if(dp[eggs][floor] != -1)
            return dp[eggs][floor];

        int mini = INT_MAX;
        for (int k = 1; k <= floor; k++)
        {
            // if break at kth floor then we have to check for k-1 floors with 1 less egg
            //  move down
            int brk = helper(eggs - 1, k - 1, dp);

            //egg does not break at kth floor then we have to check for floors above kth floor with same number of eggs
            // move up
            int not_break = helper(eggs, floor - k, dp);

            int temp = 1 + max(brk, not_break);
            mini = min(mini, temp);
        }
        return dp[eggs][floor] = mini;
    }

    int eggDrop(int egg, int floor)
    {
        vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, -1));
        return helper(egg, floor, dp);
    }
};