class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr1[i]]++;
        }

        for (int i = 0; i < m; i++)
        {
            if (mp.find(arr2[1]) != mp.end())
            {
                while (mp[arr2[i]])
                {
                    ans.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
            }
        }

        for (auto i : mp)
        {
            while (i.second)
            {
                ans.push_back(i.first);
                i.second--;
            }
        }

        return ans;
    }
};