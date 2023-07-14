class NumArray
{
public:
    vector<int> nums;
    vector<int> prefix;
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        int n = nums.size();
        prefix.resize(n);

        prefixCalc(nums);
    }

    void prefixCalc(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            (i == 0) ? prefix[i] = nums[i] : prefix[i] = nums[i] + prefix[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return (left - 1 >= 0) ? prefix[right] - prefix[left - 1] : prefix[right];
    }
};
