class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {BinarySearch(nums, target, "FIRST"), BinarySearch(nums, target, "LAST")};
    }

    int BinarySearch(vector<int> nums, int num, string find)
    {
        int left = 0, right = nums.size() - 1, mid;
        int result = -1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (nums[mid] == num)
            {
                result = mid;
                (find == "FIRST") ? right = mid - 1 : left = mid + 1;
            }
            else if (nums[mid] > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};


class Solution
{
public:
    int firstOccurrence(vector<int> &arr, int n, int k)
    {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k)
            {
                first = mid;
                // look for smaller index on the left
                high = mid - 1;
            }
            else if (arr[mid] < k)
            {
                low = mid + 1; // look on the right
            }
            else
            {
                high = mid - 1; // look on the left
            }
        }
        return first;
    }

    int lastOccurrence(vector<int> &arr, int n, int k)
    {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k)
            {
                last = mid;
                // look for larger index on the right
                low = mid + 1;
            }
            else if (arr[mid] < k)
            {
                low = mid + 1; // look on the right
            }
            else
            {
                high = mid - 1; // look on the left
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int> &arr, int k)
    {
        int n = arr.size();
        int first = firstOccurrence(arr, n, k);
        if (first == -1)
            return {-1, -1};
        int last = lastOccurrence(arr, n, k);
        return {first, last};
    }
};