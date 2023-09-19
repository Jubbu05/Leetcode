//TLE
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost,int i) {
//         if(i==0 || i==1) return 0;
//         return min(minCostClimbingStairs(cost,i-2)+cost[i-2],minCostClimbingStairs(cost,i-1)+cost[i-1]);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         return minCostClimbingStairs(cost,cost.size());
//     }
// };

// While trying to solve this problem like this. If I'm at my current location what was the minimum cost
// I paid to reach this location.
// Let  cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// at the first location the minimum cost I have to pay is 1.
// cost = [1,]
// for the second stair the minum cost I have to pay is that stair itself because u can skep a stair.
// cost = [1,100]
// for the third stair i could have come from the first stair or the second stair.Since the q states minmum cost
// I am going to pick the 1st stair + cost of the current stair.
// cost = [1,100,2]
// cost = [1,100,2,3] <--picked stair 3.
// cost = [1,100,2,3,3] <---picked stair 3
// cost = [1,100,2,3,3,103,4,5,104,6].
// Thus the final answer is dp[n]. Not necessarily!
// lets take this example:
// cost = [10,15,20]
// cost = [10,15,30] but i can reach my destination by skipping the 3 stair thus giving me a minimum cost of 15.
// thus you final answer must be min(dp[n],dp[n-1]).
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};