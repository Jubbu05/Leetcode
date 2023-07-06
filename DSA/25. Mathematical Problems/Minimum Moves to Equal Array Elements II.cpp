// intution - choose the median as the value to which we have to make all the values equal
// 1 3 7 8 11 -> sorted
// 1 + x = 11 - y = n we have to make values equal to n so we will add some value to first number and subtract some value from last number
// x + y = 11 - 1 = n
// we just need to find x + y
// last value - first value = n
// start++ end-- and add the difference to count
// n will be the median we have to make all the values equal to median i.e n
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int count = 0;
        while (start < end)
        {
            count += nums[end] - nums[start];

            start++;
            end--;
        }
        return count;
    }
};