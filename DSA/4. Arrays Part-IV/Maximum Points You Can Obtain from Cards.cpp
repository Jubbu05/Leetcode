// // Approach 1 : Recursion (TLE)
// // TC: O(2^n)
class Solution
{
public:
    int helper(vector<int> &cardPoints, int l, int h, int k)
    {
        if (k == 0)
            return 0;
        return max(cardPoints[l] + helper(cardPoints, l + 1, h, k - 1), cardPoints[h] + helper(cardPoints, l, h - 1, k - 1));
    }

    int maxScore(vector<int> &cardPoints, int k)
    {
        if (k >= cardPoints.size())
        {
            int sum = 0;
            for (auto e : cardPoints)
                sum += e;
            return sum;
        }
        else
        {
            return helper(cardPoints, 0, cardPoints.size() - 1, k);
        }
    }
};

// Approach 2 : Sliding Window
//DRY RUN
//  1 2 3 4 5 6 1  k = 3
// [1 2 3] 4 5 6 1    sum = 6       addind first k element
// [1 2] 3 4 5 6 [1]  sum = 4       removing the last element of the window and adding the last from array
// [1] 2 3 4 5 [6 1]  sum = 8
// 1 2 3 4 [5 6 1]    sum = 12      
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int res = 0;

        // First k elements in our window
        for (int i = 0; i < k; i++)
            res += cardPoints[i];

        int curr = res;
        for (int i = k - 1; i >= 0; i--)
        {
            // removing the last element of the window
            curr -= cardPoints[i];
            // adding the last element from the array
            curr += cardPoints[n - k + i];

            res = max(res, curr);
        }

        return res;
    }
};