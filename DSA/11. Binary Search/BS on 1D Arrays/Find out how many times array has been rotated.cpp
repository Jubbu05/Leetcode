class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int index = -1;

        int ans = INT_MAX;;

        while(low <= high){
            int mid = low + (high-low) / 2;

            //right half is sorted and then pick the minimum element from the right half
            //min  will be at mid
            //and then search in the left half
            if(nums[mid] <= nums[high]){
                if(nums[mid < ans]){
                    ans = nums[mid];
                    index = mid;
                }
                // ans = min(ans, nums[mid]);
                high = mid - 1;
            }
            //left half is sorted and then pick the minimum element from the left half
            //min  will be at low
            //search in the right half
            else{
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                // ans = min(ans, nums[low]);
                low = mid + 1;
            }
        }
        return index;
    }
};