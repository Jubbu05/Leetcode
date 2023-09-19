#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    while (j < n)
    {
        mp[arr[j]]++;
        if (j - i + 1 == k)
        {
            ans.push_back(mp.size());

            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);

            i++;
        }
        j++;
    }
    return ans;
}