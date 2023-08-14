class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> set;
        
        for(int i=0; i<n; i++){
            set.insert(nums[i]);
        }
        int k = set.size();
        int j = 0;
        for(auto x : set){
            nums[j] = x;
            j++;
        }
        return k;
    }
};

//------------------------------------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = 1;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};