class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> um;
        vector<int> ans;
        stack<int> s;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int ele = nums2[i];
            while (!s.empty() && s.top() <= ele)
            {
                s.pop();
            }
            int res = (s.empty()) ? -1 : s.top();
            um.insert({ele, res});
            s.push(nums2[i]);
        }
        for (auto x : nums1)
        {
            ans.push_back(um[x]);
        }
        return ans;
    }
};