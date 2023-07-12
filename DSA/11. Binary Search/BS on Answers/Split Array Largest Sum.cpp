// largest sum of any subarray is minimized
class Solution
{
public:
    bool check(vector<int> &nums, int m, int curr)
    {
        int i = -1, n = nums.size(), count = 1;

        int sum = 0;

        while (++i < n && count <= m)
        {
            // if adding the nums[i] does not make the sum greater than curr (mid), we add it to group
            if (sum + nums[i] <= curr)
                sum += nums[i];
            // else we can add a new group to store the remaining element.
            else
                sum = nums[i], count++;
        }

        // If the total number of groups is less than the m, we can split the any of the current group of size >=2.
        // this will not increase the maximum sum and hence our answer will still be valid

        return count <= m;
    }

    int splitArray(vector<int> &nums, int m)
    {
        int low = *(max_element(nums.begin(), nums.end())); // maxElement
        int high = accumulate(nums.begin(), nums.end(), 0); // sumOfAllElements
        int mid, ans = high;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (check(nums, m, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

//------------------------------------------------------------------------------------------------

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int sum = 0, maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        int low = maxi, high = sum;
        while (low <= high)
        {
            int s = 0, d = 1;
            int mid = low + (high - low) / 2;
            for (int i = 0; i < nums.size(); i++)
            {
                s += nums[i];
                if (s > mid)
                {
                    d++;
                    s = nums[i];
                }
            }
            if (d <= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};