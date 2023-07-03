// Not work if we have negative numbers in array
// OPTIMAL APPROACH FOR IF WE HAVE ONLY POSITIVE NUMBERS AND ZERO'S IN ARRAY
// TWO POINTER APPROACH
#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n)
    {
        // if sum is less than k then we will increase right pointer
        // if sum exceeds k then we will move left pointer ans decrease sum
        while (sum > k && left <= right)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
            maxLen = max(maxLen, right - left + 1);

        // moving right pointer and increasing sum
        right++;
        if (right < n)
            sum += a[right];
    }
    return maxLen;
}

// This will work for negative numbers
// OPTIMAL APPROACH FOR IF WE HAVE BOTH POSITIVE AND NEGATIVE NUMBERS IN ARRAY
// BETTER APPROACH FOR IF WE HAVE ONLY POSITIVE NUMBERS IN ARRAY
#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // if sum exists in map then we don't update it
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}