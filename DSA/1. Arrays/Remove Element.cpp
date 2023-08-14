class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(auto it : nums){
            if(it != val){
                nums[index++] = it;
            }
        }
        return index;
    }
};