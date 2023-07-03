//taking advantage of the fact that the numbers are in the range 1 to n
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int n : nums)
        {
            int index = abs(n) - 1;

            //if the number is already negative, it means we have seen that number before
            if (nums[index] < 0)
                result.push_back(index + 1);

            //flip the number to negative
            else
                nums[index] *= -1;
        }
        return result;
    }
};

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> m;
        vector<int> answer;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 1)
            {
                answer.push_back(it->first);
            }
        }
        return answer;
    }
};