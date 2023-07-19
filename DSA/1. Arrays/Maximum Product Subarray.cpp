//https://www.youtube.com/watch?v=hnswaLJvr6g
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pref = 1, suff = 1, ans = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            pref = pref * nums[i];
            suff = suff * nums[n - 1 - i];

            ans = max(ans, max(pref, suff));

            if (pref == 0)
                pref = 1; // reset
            if (suff == 0)
                suff = 1; // reset
        }
        return ans;
    }
};