class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int rem = sum % k;
            if (rem == 0)
                ans = max(ans, i + 1);
            if (rem < 0)
                rem += k;
            if (mp.find(rem) != mp.end())
            {
                ans = max(ans, i - mp[rem]);
            }
            else
                mp[rem] = i;
        }
        return ans;
    }
};