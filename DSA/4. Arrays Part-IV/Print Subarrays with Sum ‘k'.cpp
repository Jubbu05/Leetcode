// https://www.codingninjas.com/studio/problems/subarrays-with-sum-%ESubarrays2%80%98k6922076?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{
    // Write your code here
    vector<vector<int>> ans;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> ds;
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            ds.push_back(a[j]);
            sum += a[j];
            if (sum == k)
            {
                ans.push_back(ds);
            }
            else if (sum > k)
                break;
        }
    }
    return ans;
}

#include <bits/stdc++.h>
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int n = a.size();
    unordered_map<long long, int> mp;
    vector<vector<int>> ans;

    long long sum = 0;
    
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == k){
            int start = 0;
            int end = i;
            vector<int> ds;
            for(int i=start; i<=end; i++){
                ds.push_back(a[i]);
            }
            ans.push_back(ds);
        }
        if(mp.find(sum-k) != mp.end()){
            int start = mp[sum-k] + 1;
            int end = i;
            vector<int> ds;
            for(int i=start; i<=end; i++){
                ds.push_back(a[i]);
            }
            ans.push_back(ds);
        }
        mp[sum] = i;
    }
    return ans;
}