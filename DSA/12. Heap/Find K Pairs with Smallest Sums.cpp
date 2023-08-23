//TLE
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        //{sum,{nums1[i],nums2[j]}}
        priority_queue<pair<int, pair<int, int>>> pq; // maxheap
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = nums1[i] + nums2[j];
                pq.push({sum, {nums1[i], nums2[j]}});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int u = it.second.first;
            int v = it.second.second;
            ans.push_back({u, v});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        //{sum,{nums1[i],nums2[j]}}
        priority_queue<pair<int, pair<int, int>>> pq; // max heap
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k)
                {
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else if (sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else
                {
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};