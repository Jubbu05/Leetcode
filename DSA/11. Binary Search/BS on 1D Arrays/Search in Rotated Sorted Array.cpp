class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] == target)
                return mid; // Return the index if the target is found

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Checking if the target lies in the left half
                if (nums[low] <= target && nums[mid] >= target)
                    high = mid - 1; // Adjust the search range to the left half
                else
                    low = mid + 1; // Adjust the search range to the right half
            }

            // Right half is sorted
            else {
                // Checking if the target lies in the right half
                if (nums[mid] <= target && nums[high] >= target)
                    low = mid + 1; // Adjust the search range to the right half
                else
                    high = mid - 1; // Adjust the search range to the left half
            }
        }

        return -1; // Return -1 if the target is not found
    }
};
