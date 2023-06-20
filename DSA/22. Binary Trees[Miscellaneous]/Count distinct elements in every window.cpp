class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        // code here.
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            mp[A[i]]++;
        }

        vector<int> ans;
        ans.push_back(mp.size());

        for (int i = k; i < n; i++)
        {
            if (mp[A[i - k]] == 1)
            {
                mp.erase(A[i - k]);
            }
            else
            {
                mp[A[i - k]]--;
            }

            mp[A[i]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};