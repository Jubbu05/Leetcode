// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         set<int> set;
        
//         for(int i=0; i<n; i++){
//             set.insert(nums[i]);
//         }
//         int k = set.size();
//         int j = 0;
//         for(auto x : set){
//             nums[j] = x;
//             j++;
//         }
//         return k;
//     }
// };

//------------------------------------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j=1; j<n; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums [j];
            }
        }
        return i+1;
    }
};