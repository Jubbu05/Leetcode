class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int ele = nums[i];
            if (ele >= 1 && ele <= n)
            {
                int chair = ele - 1;
                if (nums[chair] != ele) // if not at correct position
                {
                    swap(nums[i], nums[chair]);
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1; // 1 2 3 4 5
    }                 // want to return 6
};
