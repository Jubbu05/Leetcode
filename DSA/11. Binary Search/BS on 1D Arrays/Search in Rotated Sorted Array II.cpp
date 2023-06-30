//WE HAVE DUPLICATE ELEMENTS
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] == target)
                return true; // Return true if the target is found
                

            //trimming down the duplicates search space
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

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

        return false; // Return false if the target is not found
    }
};
