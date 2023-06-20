class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < n - 1; i++) {
    //         if (nums[i] == nums[i + 1]){
    //           return nums[i];  
    //         } 
    //     }
    //     return 0;
    // }
    
    // int findDuplicate(vector<int>& nums){
    //     int n = nums.size();
    //     vector<int> freq(n+1, 0);
        
    //     for (int i=0; i<n; i++){
    //         if(freq[nums[i]] == 0){
    //             freq[nums[i]] += 1;
    //         }
    //         else {
    //             return nums[i];
    //         }
    //     }
    //     return 0;
    // }

    // int findDuplicate(vector<int>& nums) {
    //     int n=nums.size();
    //     int left = 1, right = nums.size() - 1;
    //     while(left<right){
    //         int mid = left + (right - left) / 2;
    //         int c = 0;
    //         for(const int& el: nums)
    //             if(el <= mid)
    //                 ++c;
            
    //         if(c > mid)
    //             right = mid;
    //         else
    //             left = mid + 1;
    //       }
    //     return left;
    // }
    
    // 1. linklist cycle method
    // 2. tortoise method - two pointer
    //     slow moves - 1 step
    //     fast moves - 2 steps do until the meet on same point
    // 3. after they collide move the fast pointer to 0
    // 4. now both slow and fast both moves with 1 step and the point where they                 collide is duplicate number

    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[0];
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while (slow != fast);

      fast = nums[0];
      
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};