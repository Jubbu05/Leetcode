// start from backwards
// 1. Find index where a[i] < a[i+1] --> ind1 O(N)
// 2. start from backwards again and find a[ind2] > a[ind1] --> ind2 O(N)
// 3. swap(a[ind1], a[ind2])
// 4. reverse(ind1+1, last) O(N) we will get the next permutation
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} 
        else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};