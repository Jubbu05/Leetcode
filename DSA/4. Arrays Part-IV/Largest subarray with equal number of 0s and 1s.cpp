#include <bits/stdc++.h>
int findSubarray(vector<int> &nums)
{
    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int zeroes = 0, ones = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
            if (zeroes == ones)
            {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}

//-----------------------------------------------------------

int findSubarray(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            nums[i] = -1;
        }
    }

    int sum = 0, res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == 0)
        {
            res = max(res, i + 1);
        }

        if (mp.find(sum) != mp.end())
        { // sum is in map
            res = max(res, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return res;
}
